// 2016-09-13
// Caskey, Damon
//
// Universal animation constants.


#ifndef ANIMATION

#define ANIMATION 1

#define ANI_JUMP_VERTICAL           openborconstant("ANI_JUMP")
#define ANI_JUMP_FORWARD            openborconstant("ANI_FORWARDJUMP")
#define ANI_JUMP_RUNNING            openborconstant("ANI_RUNJUMP")
#define ANI_PAIN_STUN_BACK          openborconstant("ANI_PAIN15")
#define ANI_PAIN_STUN_FRONT         openborconstant("ANI_PAIN2")

// Function macros
#define get_animation(entity)               getentityproperty(entity, "animationID")
#define get_animation_frame(entity)         getentityproperty(entity, "animpos")
#define set_animation(entity, animation)    changeentityproperty(entity, "animation", animation)
#define set_animation_frame(entity, frame)  changeentityproperty(entity, "animpos", frame)

#endif // ANIMATION

