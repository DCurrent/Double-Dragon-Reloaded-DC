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

#ifndef BILLKEY

#define BILLKEY 1

#define BILLKEY_FLAG_FALSE            0
#define BILLKEY_FLAG_TRUE             1

#endif

void main()
{
    int     player_index;       // Player index triggering key event.
    void    player_entity;      // Entity player is controlling.
    int     player_key_press;   // Keys pressed by player.
    int     player_key_hold;    // Keys held by player.
    int     walking;            // Entity walking?
    int     animation_id;       // Current animation.
    int     animation_frame;    // Animation frame.
    float   vel_y;              // Velocity, Y axis.
    void    target_entity;      // Target entity pointer.
    float   player_pos_b;       // Player position, base.
    float   player_pos_d;       // Player position, direction.
    float   player_pos_x;       // Player position, X axis.
    float   player_pos_y;       // Player position, Y axis
    float   player_pos_z;       // Player position, Z axis.
    float   player_vel_x;       // Player velocity, X axis.
    float   player_vel_y;       // Player velocity, Y axis.
    float   player_vel_z;       // Player velocity, Z axis.
    float   target_pos_b;       // Target's position, base.
    float   target_pos_d;       // Target's position, direction.
    float   target_pos_x;       // Target's position, X axis.
    float   target_pos_y;       // Target's position, Y axis
    float   target_pos_z;       // target's position, Z axis.
    int     var_type;           // Variable type.
    int     time_elapsed;       // OpenBOR elapsed time.
    int     in_range;           // Target in range.

    // Populate the variables.
    player_index        = getlocalvar("player");
    player_entity       = getplayerproperty(player_index, "entity");
    player_key_hold     = getplayerproperty(player_index, "keys");
    player_key_press    = getplayerproperty(player_index, "newkeys");

    // Jumping back kick.
    if(KEY_ATTACK_2_AND_JUMP == BILLKEY_FLAG_TRUE)
    {
        walking = is_walking(player_entity);

        if(walking == BILLKEY_FLAG_TRUE)
        {
            changeentityproperty(player_entity, "velocity", 0, 0, 0);

            dc_set_attack(player_entity, ANI_DRAGON_JUMPING_BACK_KICK);

            // Nothing else to do, so escape script.
            return;
        }
    }

    // TKD Kick.
    if((player_key_press & KEY_ATTACK_2) && (player_key_hold & KEY_MOVE_DOWN))
    {
        walking = is_walking(player_entity);

        if(walking == BILLKEY_FLAG_TRUE)
        {
            changeentityproperty(player_entity, "velocity", 0, 0, 0);

            dc_set_attack(player_entity, ANI_DRAGON_TKD_KICK);

            // Nothing else to do, so escape script.
            return;
        }
    }

    // TKD Kick.
    if(player_key_press & KEY_ATTACK_3)
    {
        walking = is_walking(player_entity);

        if(walking == BILLKEY_FLAG_TRUE)
        {

            changeentityproperty(player_entity, "velocity", 0, 0, 0);

            dc_set_attack(player_entity, ANI_DRAGON_ROUNDHOUSE_KICK);

            // Nothing else to do, so escape script.
            return;
        }
    }

    // Somersault kick.
    // Jumping kick.
    // Jumping spin kick.
    if(player_key_press & KEY_ATTACK_2)
    {
        animation_id = get_animation(player_entity);

        // In Somersault?
        if(animation_id == ANI_DRAGON_SOMERSAULT_JUMP)
        {
            // At peak or below of jump and not landed?
            vel_y = getentityproperty(player_entity, "tossv");

            if(vel_y < 0)
            {
                dc_set_attack(player_entity, ANI_DRAGON_SOMERSAULT_KICK);

                // Nothing else to do, so escape script.
                return;
            }
        }
        // In Run?
        else if(animation_id == openborconstant("ANI_RUN"))
        {
            changeentityproperty(player_entity, "velocity", 0, 0, 0);

            dc_set_attack(player_entity, ANI_DRAGON_JUMPING_SPIN_KICK);

            // Nothing else to do, so escape script.
            return;
        }
        // In Jump?
        else if(animation_id == openborconstant("ANI_JUMP")
                || animation_id == openborconstant("ANI_FORWARDJUMP"))
        {
            // Switch directly to animation. No need to modify velocity.
            dc_set_animation(player_entity, ANI_DRAGON_JUMPING_SIDE_KICK);

            // Nothing else to do, so escape script.
            return;
        }
    }

    // Somersault throw cancel.
    if(player_key_press & KEY_ATTACK)
    {
        animation_id = get_animation(player_entity);

        // In Somersault?
        if(animation_id == ANI_DRAGON_SOMERSAULT_JUMP)
        {
            // Have left ground but not at peak of jump?
            vel_y = getentityproperty(player_entity, "tossv");

            if(vel_y > 0)
            {
                // Have the animation?
                if(getentityproperty(player_entity, "animvalid", ANI_DRAGON_SOMERSAULT_THROW))
                {
                    // Get target(s) in range of somersault throw.
                    target_entity = findtarget(player_entity, ANI_DRAGON_SOMERSAULT_THROW);

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
                            dc_set_attack(player_entity, ANI_DRAGON_SOMERSAULT_THROW);

                            // Nothing else to do, so escape script.
                            return;
                        }
                    }
                }
            }
        }
    }

    // Hurricane Kick cancel
    // Moved to script to simplify checking for
    // the double team Hurricane Kick.
    if(player_key_press & KEY_ATTACK_3)
    {
        animation_id = get_animation(player_entity);

        // In a jump?
        if(animation_id == ANI_JUMP_VERTICAL || animation_id == ANI_JUMP_FORWARD)
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
                    if(animation_id == ANI_JUMP_VERTICAL || animation_id == ANI_JUMP_FORWARD)
                    {
                        // Run a range check.
                        in_range = checkrange(player_entity, target_entity, ANI_DRAGON_HURRICANE_KICK_DOUBLE_1);

                        // Is target in range of double hurricane kick?
                        if(in_range == BILLKEY_FLAG_TRUE)
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

                            dc_set_attack(player_entity, ANI_DRAGON_HURRICANE_KICK_DOUBLE_1);

                            changeentityproperty(target_entity, "velocity", 0, 0, 0);
                            changeentityproperty(target_entity, "tosstime", time_elapsed);

                            dc_set_attack(player_entity, ANI_DRAGON_HURRICANE_KICK_DOUBLE_2);

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
                dc_set_attack(player_entity, ANI_DRAGON_HURRICANE_KICK);
            }
            else
            {
                dc_set_animation(player_entity, ANI_DRAGON_JUMPING_SIDE_KICK);
            }

            // Nothing else to do, so escape script.
            return;
        }
    }
}

// Set animation assuming it exists.
int dc_set_animation(void entity, int animation)
{
    int is_valid;
    int vartype;
    int result;

    // Get entity vartype.
    vartype = typeof(entity);

    // If the entity is not a valid pointer, use self as default.
    if(vartype != openborconstant("VT_PTR"))
    {
        entity = getlocalvar("self");
    }

    // Entity valid?
    if(vartype == openborconstant("VT_PTR"))
    {
        // Get animation valid status.
        is_valid = getentityproperty(entity, "animvalid", animation);

        // Animation is valid?
        if(is_valid == 1)
        {
            // Switch to animation.
            changeentityproperty(entity, "animation", animation);
        }
    }

    return result;
}

int dc_set_attack(void entity, int animation)
{
    int is_valid;
    int vartype;
    int result;

    // Get entity vartype.
    vartype = typeof(entity);

    // If the entity is not a valid pointer, use self as default.
    if(vartype != openborconstant("VT_PTR"))
    {
        entity = getlocalvar("self");
    }

    // Entity valid?
    if(vartype == openborconstant("VT_PTR"))
    {
        // Get animation valid status.
        is_valid = getentityproperty(entity, "animvalid", animation);

        // Animation is valid?
        if(is_valid == 1)
        {
            // Switch using perform attack.
            result = performattack(entity, animation);
        }
    }

    return result;
}

int is_walking(void target)
{
    int result;
    int animation_id;

    animation_id = getentityproperty(target, "animationID");

    // Currently in walking animation?
    if (animation_id == openborconstant("ANI_IDLE")
        || animation_id == openborconstant("ANI_WALK")
        || animation_id == openborconstant("ANI_UP"))
    {
        result = BILLKEY_FLAG_TRUE;
    }
    else
    {
        result = BILLKEY_FLAG_FALSE;
    }

    // Return result.
    return result;
}
