#ifndef DC_DDR_STUN
#define DC_DDR_STUN 1

#define DC_DDR_STUN_FALSE   0
#define DC_DDR_STUN_TRUE    1


#define DC_DDR_VARTYPE_POINTER  openborconstant("VT_PTR")
#define DC_DDR_ANIMATION_STUN   openborconstant("ANI_PAIN2")

#endif // DC_DDR_STUN

void main()
{
    void self;
    void target;
    int  animation;
    char model;
    int target_type;
    int animation_valid;
    int target_hitpoints;
    float target_pos_y;
    float target_pos_b;

    self    = getlocalvar("self");
    target  = getlocalvar("damagetaker");

    animation = getentityproperty(self, "animationid");
    model   = getentityproperty(self, "model");

    // Stick weapon uses a three hit combo. It is not possible
    // for the combo to have good visual aesthetics while matching
    // the attack# and pain# based stun mechanics already set up in the
    // rest of the module. We'll fix it here. The third attack is
    // a mid level thrust. When it hits, we force the target
    // directly into the second frame of its secondary pain animation
    // for a visual mid hit that instantly crouch stuns.

    // Using the stick weapon?
    if(model == "bstick")
    {
        // In attack animation 3?
        if(animation == openborconstant("ANI_ATTACK3"))
        {
            // Target is valid?
            target_type = typeof(target);

            if(target_type == DC_DDR_VARTYPE_POINTER)
            {
                // Target has the needed pain animation?
                animation_valid = getentityproperty(target, "animvalid", DC_DDR_ANIMATION_STUN);

                if(animation_valid == DC_DDR_STUN_TRUE)
                {
                    // Will target be left standing? We'll need to make
                    // sure target is not in the air and will survive
                    // the attack so they don't get knocked into the
                    // air still in a crouch stun pose.
                    target_pos_y        = getentityproperty(target, "y");
                    target_pos_b        = getentityproperty(target, "base");
                    target_hitpoints    = getentityproperty(target, "health");

                    if(target_pos_b <= target_pos_y
                       && target_hitpoints > 6)
                    {
                        changeentityproperty(target, "animation", DC_DDR_ANIMATION_STUN);
                        changeentityproperty(target, "animpos", 1);
                    }
                }
            }
        }
    }
}
