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


#ifndef JIMKEY

#define JIMKEY 1

#define JIMKEY_FLAG_FALSE            0
#define JIMKEY_FLAG_TRUE             1

#define JIMKEY_JUMP_VERTICAL           openborconstant("ANI_JUMP")
#define JIMKEY_JUMP_FORWARD            openborconstant("ANI_FORWARDJUMP")

#define JIMKEY_JUMPING_BACK_KICK       openborconstant("ANI_freespecial21")
#define JIMKEY_JUMPING_SIDE_KICK       openborconstant("ANI_freespecial8")
#define JIMKEY_JUMPING_SPIN_KICK       openborconstant("ANI_freespecial17")
#define JIMKEY_SOMERSAULT_JUMP         openborconstant("ANI_freespecial35")
#define JIMKEY_SOMERSAULT_KICK         openborconstant("ANI_freespecial36")
#define JIMKEY_SOMERSAULT_THROW        openborconstant("ANI_follow57")
#define JIMKEY_HURRICANE_KICK          openborconstant("ANI_follow58")
#define JIMKEY_HURRICANE_KICK_DOUBLE_1 openborconstant("ANI_follow59")
#define JIMKEY_HURRICANE_KICK_DOUBLE_2 openborconstant("ANI_follow60")

// System key flags.
#define JIMKEY_KEY_ATTACK            openborconstant("FLAG_ATTACK")      // Attack 1.
#define JIMKEY_KEY_ATTACK_2          openborconstant("FLAG_ATTACK2")     // Attack 2.
#define JIMKEY_KEY_ATTACK_3          openborconstant("FLAG_ATTACK3")     // Attack 3.
#define JIMKEY_KEY_ATTACK_4          openborconstant("FLAG_ATTACK4")     // Attack 4.
#define JIMKEY_KEY_ESCAPE            openborconstant("FLAG_ESC")         // Escape.
#define JIMKEY_KEY_JUMP              openborconstant("FLAG_JUMP")        // Jump.
#define JIMKEY_KEY_MOVE_LEFT         openborconstant("FLAG_MOVELEFT")    // Left.
#define JIMKEY_KEY_MOVE_RIGHT        openborconstant("FLAG_MOVERIGHT")   // Right.
#define JIMKEY_KEY_SCREENSHOT        openborconstant("FLAG_SCREENSHOT")  // Screen shot.
#define JIMKEY_KEY_SPECIAL           openborconstant("FLAG_SPECIAL")     // Special.

// Custom key combos.
#define JIMKEY_KEY_ATTACK_2_AND_JUMP   (player_key_press & JIMKEY_KEY_ATTACK_2 && player_key_hold & JIMKEY_KEY_JUMP) || (player_key_hold & JIMKEY_KEY_ATTACK_2 && player_key_press & JIMKEY_KEY_JUMP)
#define JIMKEY_KEY_ATTACK_3_AND_JUMP   (player_key_press & JIMKEY_KEY_ATTACK_3 && player_key_hold & JIMKEY_KEY_JUMP) || (player_key_hold & JIMKEY_KEY_ATTACK_3 && player_key_press & JIMKEY_KEY_JUMP)
#define JIMKEY_KEY_ATTACK_3_ATTACK_2   (player_key_press & JIMKEY_KEY_ATTACK_3 && player_key_hold & JIMKEY_KEY_ATTACK_2) || (player_key_hold & JIMKEY_KEY_ATTACK_3 && player_key_press & JIMKEY_KEY_ATTACK_2)

// Function macros
#define get_animation(entity)         getentityproperty(entity, "animationID")

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
    if(JIMKEY_KEY_ATTACK_2_AND_JUMP == JIMKEY_FLAG_TRUE)
    {
        walking = is_walking(player_entity);

        if(walking == JIMKEY_FLAG_TRUE)
        {
            changeentityproperty(player_entity, "velocity", 0, 0, 0);
            performattack(player_entity, JIMKEY_JUMPING_BACK_KICK);

            // Nothing else to do, so escape script.
            return;
        }
    }

    // Jumping spin kick.
    if(KEY_ATTACK_3_AND_JUMP == JIMKEY_FLAG_TRUE)
    {
        walking = is_walking(player_entity);

        if(walking == JIMKEY_FLAG_TRUE)
        {
            changeentityproperty(player_entity, "velocity", 0, 0, 0);
            performattack(player_entity, JIMKEY_JUMPING_SPIN_KICK);

            // Nothing else to do, so escape script.
            return;
        }
    }

    // Somersault kick cancel.
    // This cancel has to be from script to preserve momentum
    // without complex workarounds.
    if(player_key_press & JIMKEY_KEY_ATTACK_2)
    {
        animation_id = get_animation(player_entity);

        // In Somersault?
        if(animation_id == JIMKEY_SOMERSAULT_JUMP)
        {
            // At peak or below of jump and not landed?
            vel_y = getentityproperty(player_entity, "tossv");

            if(vel_y < 0)
            {
                performattack(player_entity, JIMKEY_SOMERSAULT_KICK);

                // Nothing else to do, so escape script.
                return;
            }
        }
    }

    // Somersault throw cancel.
    if(player_key_press & JIMKEY_KEY_ATTACK)
    {
        animation_id = get_animation(player_entity);

        // In Somersault?
        if(animation_id == JIMKEY_SOMERSAULT_JUMP)
        {
            // Have left ground but not at peak of jump?
            vel_y = getentityproperty(player_entity, "tossv");

            if(vel_y > 0)
            {
                // Get target(s) in range of somersault throw.
                target_entity = findtarget(player_entity, JIMKEY_SOMERSAULT_THROW);

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
                        performattack(player_entity, JIMKEY_SOMERSAULT_THROW);

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
    if(player_key_press & JIMKEY_KEY_ATTACK_3)
    {
        animation_id = get_animation(player_entity);

        // In a jump?
        if(animation_id == JIMKEY_JUMP_VERTICAL || animation_id == JIMKEY_JUMP_FORWARD)
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
                    if(animation_id == JIMKEY_JUMP_VERTICAL || animation_id == JIMKEY_JUMP_FORWARD)
                    {
                        // Run a range check.
                        in_range = checkrange(player_entity, target_entity, JIMKEY_HURRICANE_KICK_DOUBLE_1);

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
                            performattack(player_entity, JIMKEY_HURRICANE_KICK_DOUBLE_1);

                            changeentityproperty(target_entity, "velocity", 0, 0, 0);
                            changeentityproperty(target_entity, "tosstime", time_elapsed);
                            performattack(target_entity, JIMKEY_HURRICANE_KICK_DOUBLE_2);

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
                performattack(player_entity, JIMKEY_HURRICANE_KICK);
            }
            else
            {
                changeentityproperty(player_entity, "animation", JIMKEY_JUMPING_SIDE_KICK);
            }

            // Nothing else to do, so escape script.
            return;
        }
    }
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
        result = JIMKEY_FLAG_TRUE;
    }
    else
    {
        result = JIMKEY_FLAG_FALSE;
    }

    // Return result.
    return result;
}
