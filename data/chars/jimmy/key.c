// 2016-09-13
// Caskey, Damon
//
// Refined a bit from original code by magggas, which
// itself was based on one of my VERY old keyscripts.

// Macros and bitwise operators put in place of
// playerkeys press and hold lists. Is now much
// more friendly to debug and should be faster
// at runtime too.

// There is still a lot of copypasta (repeat code)
// though. We could eventually break it down with
// arrays and further use of bitwise, but for now
// it should be OK.


#include "data/scripts/key.h"
#include "data/chars/billy/animation.h"

#ifndef JIMKEY

#define JIMKEY 1

#define JIMKEY_FLAG_FALSE       0
#define JIMKEY_FLAG_TRUE            1

#define JIMKEY_KEY_ATTACK_LEFT  KEY_ATTACK
#define JIMKEY_KEY_ATTACK_RIGHT KEY_ATTACK_2

#endif

void main()
{
    int     player_index;       // Player index triggering key event.
    void    player_entity;      // Entity player is controlling.
    int     player_key_press;   // Keys pressed by player.
    int     player_key_hold;    // Keys held by player.
    int     idle;               // Entity idle or walking?
    int     animation_id;       // Current animation.
    int     animation_frame;    // Animation frame.
    float   vel_y;              // Velocity, Y axis.
    void    target_entity;      // Target entity pointer.
    float   player_pos_b;       // Player position, base.
    float   player_pos_d;       // Player position, direction.
    float   player_pos_x;       // Player position, X axis.
    float   player_pos_y;       // Player position, Y axis
    float   player_pos_z;       // Player position, Z axis.
    float   target_pos_b;       // Target's position, base.
    float   target_pos_d;       // Target's position, direction.
    float   target_pos_x;       // Target's position, X axis.
    float   target_pos_y;       // Target's position, Y axis
    float   target_pos_z;       // target's position, Z axis.
    int     var_type;           // Variable type.
    int     time_elapsed;       // OpenBOR elapsed time.
    int     in_range;           // Target in range.
    int     succeeded;          // An attack/animation was used?

    // Populate the basic entity and key variables.
    player_index        = getlocalvar("player");
    player_entity       = getplayerproperty(player_index, "entity");
    player_key_hold     = getplayerproperty(player_index, "keys");
    player_key_press    = getplayerproperty(player_index, "newkeys");

    // Get direction and idle status. We're going to need this a lot.
    player_pos_d    = getentityproperty(player_entity, "direction");
    idle            = is_idle(player_entity);

    // Facing right?
    if(player_pos_d)
    {
        // Elbow
        if(KEY_ATTACK_LEFT_AND_JUMP == JIMKEY_FLAG_TRUE)
        {
            succeeded = do_attack(player_entity, ANI_DRAGON_BACK_ELBOW);

            // If the move was executed, then clear keys and exit
            // function.
            if(succeeded != JIMKEY_FLAG_FALSE)
            {
                clear_keys(player_index);
                return succeeded;
            }
        }

        // Jumping spin kick.
        if(KEY_ATTACK_RIGHT_AND_JUMP == JIMKEY_FLAG_TRUE)
        {
            succeeded = do_attack(player_entity, ANI_DRAGON_BACK_ELBOW);

            // If the move was executed, then clear keys and exit
            // function.
            if(succeeded != JIMKEY_FLAG_FALSE)
            {
                clear_keys(player_index);
                return succeeded;
            }
        }

        // Back kick
        if(player_key_press & JIMKEY_KEY_ATTACK_LEFT)
        {
            // Get idle status.
            idle = is_idle(player_entity);

            if(idle == JIMKEY_FLAG_TRUE)
            {
                succeeded = do_attack(player_entity, ANI_DRAGON_BACK_ELBOW);

                // If the move was executed, then clear keys and exit
                // function.
                if(succeeded != JIMKEY_FLAG_FALSE)
                {
                    clear_keys(player_index);
                    return succeeded;
                }
            }
        }
    }


    // Elbow (back) or jumping spin kick (front).
    if(KEY_KEY_ATTACK_LEFT_AND_JUMP == JIMKEY_FLAG_TRUE)
    {
        // Is player idle?
        if(idle == JIMKEY_FLAG_TRUE)
        {
            // Stop movement.
            changeentityproperty(player_entity, "velocity", 0, 0, 0);

            // Perform move based on direction.
            if(direction == KEY_DIRECTION_RIGHT)
            {
                performattack(player_entity, KEY_ANI_BACK_ELBOW);
            }
            else
            {
                performattack(player_entity, KEY_ANI_JUMPING_SPIN_KICK);
            }

            // Nothing else to do, so escape script.
            return;
        }
    }


    // Somersault kick cancel.
    // This cancel has to be from script to preserve momentum
    // without complex workarounds.
    if(player_key_press & KEY_KEY_ATTACK_2)
    {
        animation_id = get_animation(player_entity);

        // In Somersault?
        if(animation_id == KEY_SOMERSAULT_JUMP)
        {
            // At peak or below of jump and not landed?
            vel_y = getentityproperty(player_entity, "tossv");

            if(vel_y < 0)
            {
                performattack(player_entity, KEY_SOMERSAULT_KICK);

                // Nothing else to do, so escape script.
                return;
            }
        }
    }

    // Somersault throw cancel.
    if(player_key_press & KEY_KEY_ATTACK)
    {
        animation_id = get_animation(player_entity);

        // In Somersault?
        if(animation_id == KEY_SOMERSAULT_JUMP)
        {
            // Have left ground but not at peak of jump?
            vel_y = getentityproperty(player_entity, "tossv");

            if(vel_y > 0)
            {
                // Get target(s) in range of somersault throw.
                target_entity = findtarget(player_entity, KEY_SOMERSAULT_THROW);

                // Get variable type of target.
                var_type = typeof(target_entity);

                // Target a valid pointer? Then a good target was found.
                if(var_type == openborconstant("VT_PTR"))
                {
                    // Get target's position data.
                    target_pos_b = getentityproperty(target_entity, "base");
                    target_pos_x = getentityproperty(target_entity, "x");
                    target_pos_y = getentityproperty(target_entity, "y");
                    target_pos_z = getentityproperty(target_entity, "z");

                    // Target on the ground?
                    if(target_pos_y <= target_pos_b)
                    {
                        // Stop all movement.
                        changeentityproperty(player_entity, "velocity", 0, 0, 0);

                        // Relocate to target's position.
                        changeentityproperty(player_entity, "position", target_pos_x, target_pos_z, target_pos_y);

                        // Make sure target is the current opponent.
                        changeentityproperty(player_entity, "opponent", target_entity);

                        // Perform the somersault throw.
                        performattack(player_entity, KEY_SOMERSAULT_THROW);

                        // Nothing else to do, so escape script.
                        return;
                    }
                }
            }
        }
    }

    // Hurricane Kick cancel
    // Moved to script to simplify checking for
    // the double team Hurricane Kick.
    if(player_key_press & KEY_KEY_ATTACK_3)
    {
        animation_id = get_animation(player_entity);

        // In a jump?
        if(animation_id == KEY_JUMP_VERTICAL || animation_id == KEY_JUMP_FORWARD)
        {
            vel_y = getentityproperty(player_entity, "tossv");

            // At apex of jump?
            if(vel_y >= -1.5 && vel_y <= 1.5)
            {
                // Now let's find out if we can do the double
                // hurricane kick. This is a simple module
                // with only two players and one character, so
                // all we need to do is get entity from opposite
                // index.
                if(player_index == 0)
                {
                    target_entity = getplayerproperty(1, "entity");
                }
                else
                {
                    target_entity = getplayerproperty(0, "entity");
                }

                // Get the variable type of entity.
                var_type = typeof(target_entity);

                // is the target entity variable a valid pointer?
                if(var_type == openborconstant("VT_PTR"))
                {
                    // Get target's animation.
                    animation_id = getentityproperty(target_entity, "animationid");

                    // Is target in a jump?
                    if(animation_id == KEY_JUMP_VERTICAL || animation_id == KEY_JUMP_FORWARD)
                    {
                        // Run a range check.
                        in_range = checkrange(player_entity, target_entity, KEY_HURRICANE_KICK_DOUBLE_1);

                        // Is target in range of double hurricane kick?
                        if(in_range == JIMKEY_FLAG_TRUE)
                        {
                            // Get player entity position.
                            player_pos_d = getentityproperty(player_entity, "direction");
                            player_pos_x = getentityproperty(player_entity, "x");
                            player_pos_y = getentityproperty(player_entity, "y");
                            player_pos_z = getentityproperty(player_entity, "z");

                            // Match target position and direction with player.
                            changeentityproperty(target_entity, "direction", player_pos_d);
                            changeentityproperty(target_entity, "position", player_pos_x, player_pos_z, player_pos_y);

                            // Get current game time and add a bit to use as
                            // toss time value.
                            time_elapsed = openborvariant("elapsed_time") + 200;

                            // Stop player and target movement, add toss time to
                            // stay in the air, and set animations.
                            changeentityproperty(player_entity, "velocity", 0, 0, 0);
                            changeentityproperty(player_entity, "tosstime", time_elapsed);
                            performattack(player_entity, KEY_HURRICANE_KICK_DOUBLE_1);

                            changeentityproperty(target_entity, "velocity", 0, 0, 0);
                            changeentityproperty(target_entity, "tosstime", time_elapsed);
                            performattack(target_entity, KEY_HURRICANE_KICK_DOUBLE_2);

                            // Nothing else to do, so exit.
                            return;
                        }
                    }
                }

                // If we got this far, then we can't do a double hurricane kick.
                // We'll just do the single instead.

                // Get current game time and add a bit to use as
                // toss time value.
                time_elapsed = openborvariant("elapsed_time") + 160;

                // Stop movement, add toss time to stay in the air,
                // and set animations.
                changeentityproperty(player_entity, "velocity", 0, 0, 0);
                changeentityproperty(player_entity, "tosstime", time_elapsed);
                performattack(player_entity, KEY_HURRICANE_KICK);
            }
            else
            {
                changeentityproperty(player_entity, "animation", KEY_JUMPING_SIDE_KICK);
            }

            // Nothing else to do, so escape script.
            return;
        }
    }
}

// Clear all key inputs
int clear_keys(player_index)
{
    changeplayerproperty(player_index, "keys", JIMKEY_FLAG_FALSE);
    changeplayerproperty(player_index, "newkeys", JIMKEY_FLAG_FALSE);

    return;
}

// Perform back elbow if possible.
int do_attack(entity, animation)
{
    int idle;

    idle = is_idle(entity)

    // Is player idle?
    if(idle == JIMKEY_FLAG_TRUE)
    {
        // Stop movement.
        changeentityproperty(entity, "velocity", 0, 0, 0);

        // Perform move based on direction.
        result = performattack(entity, animation);
    }
    else
    {
        // Result is false.
        result = JIMKEY_FLAG_FALSE
    }

    return result;
}

int is_idle(void target)
{
    int result;
    int animation_id;

    animation_id = getentityproperty(target, "animationID");

    // Currently in walking animation?
    if (animation_id == openborconstant("ANI_IDLE")
        || animation_id == openborconstant("ANI_WALK")
        || animation_id == openborconstant("ANI_UP"))
    {
        result = JIMKEY_FLAG_TRUE;
    }
    else
    {
        result = JIMKEY_FLAG_TRUE;
    }

    // Return result.
    return result;
}
