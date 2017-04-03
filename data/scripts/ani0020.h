#include "data/scripts/ani0009.h"

#include "data/scripts/animation.h"
#include "data/scripts/key.h"

#ifndef ANI0020

#define ANI0020 1


#endif // ANI0020

int ani0020(int iAni, int iTAni){

	/*
	ani0020
	Damon Vaughn Caskey
	Perform alternate animation if target is within range and in specified animation.

	iAni:	Alternate attack.
	iTAni:	Target animation.
	*/

    void vSelf      = getlocalvar("self");					//Caller.
    void vOpp       = findtarget(vSelf, iAni);				//Nearest target in range of alternate attack.

	if (vOpp)												//Found a target?
	{
		if(getentityproperty(vOpp, "animationID") == iTAni)	//Animation match?
		{
			ani0009(vSelf, iAni, 0);						//Perform alternate attack.
			return 1;										//Return 1.
		}
	}

	return 0;												//Return 0.
}

void bind(int null, float x, float z, float y, int dir){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	if(null == 1)
	{
		bindentity(opp, self, x, z, y, dir, 0);
	}
	else if(null == 0)
	{
		bindentity(opp, NULL());
	}
}

void bind2(int null, float x, float z, float y, int dir){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "grabbing");
	if(null == 1)
	{
		bindentity(opp, self, x, z, y, dir, 0);
	}
	else if(null == 0)
	{
		bindentity(opp, NULL());
	}
}

void forceanim(int anim){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	changeentityproperty(opp, "animation", anim);
}

void forceanim2(int anim){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "grabbing");
	changeentityproperty(opp, "animation", anim);
}

void beidle()
{// Go to IDLE animation!
    void self = getlocalvar("self");

    setidle(self);
}

void block(int Flag)
{// Turns blocking status
    void self = getlocalvar("self");
    changeentityproperty(self, "aiflag", "blocking", Flag);
}

void Join(int Flag)
{// Turns Join status
    changeopenborvariant("nojoin", Flag);
}

void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void stwall(int Ratio, int Ratio2, int Ratio3)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "subject_to_wall", Ratio);
    changeentityproperty(self, "subject_to_hole", Ratio2);
    changeentityproperty(self, "subject_to_gravity", Ratio3);
}

void blink()
{// Changes antigravity effect
    void self = getlocalvar("self");
    int eTime = openborvariant("elapsed_time");
    changeentityproperty(self, "invincible", 1);
    changeentityproperty(self, "invinctime", eTime + 340);
    changeentityproperty(self, "blink", 1);
}

void direc(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "direction", Ratio);
}

void move(int dx, int dz,int da)
{ // Moves entity freely or ignores obstacles
    void self = getlocalvar("self");
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int z = getentityproperty(self,"z"); //Get character's z coordinate
    int a = getentityproperty(self,"a"); //Get character's a coordinate
    int dir = getentityproperty(self,"direction"); //Get character's facing direction

     if(dir==0){ // Facing left?
      changeentityproperty(self, "position", x-dx, z+dz, a+da); //Move
     }
     else if(dir==1){ // Facing right?
      changeentityproperty(self, "position", x+dx, z+dz, a+da); //Move
     }
}

void camera()
{ // Spawn and bind other entity
   void self = getlocalvar("self");
   void P1 = getplayerproperty(0, "entity");
   void P2 = getplayerproperty(1, "entity");
   void vAniID1 = getentityproperty(P1,"animationID");
   void vAniID2 = getentityproperty(P2,"animationID");
   int Offset1 = getentityproperty(P1,"base");
   int Offset2 = getentityproperty(P2,"base");
   int Offset3 = getentityproperty(P1,"a");

   if(P2){
     changelevelproperty("camerazoffset", -100 - Offset2);
   }

   if(P1){
     changelevelproperty("camerazoffset", -100 - Offset1);
   }

   if(P1 != NULL() && getentityproperty(P1,"exists") && P2 != NULL() && getentityproperty(P2,"exists") && vAniID1 == openborconstant("ANI_IDLE") || vAniID1 == openborconstant("ANI_JUMPLAND")){
     changelevelproperty("camerazoffset", -100 - Offset1);
   }else if(P1 != NULL() && getentityproperty(P1,"exists") && P2 != NULL() && getentityproperty(P2,"exists") && vAniID1 == openborconstant("ANI_FOLLOW22") || vAniID1 == openborconstant("ANI_FOLLOW23")){
     changelevelproperty("camerazoffset", -100 - Offset3);
   }
}

void camera2()
{ // Spawn and bind other entity
   void P1 = getplayerproperty(0, "entity");
   void P2 = getplayerproperty(1, "entity");
   int Offset1 = getentityproperty(P1,"a");
   int Offset2 = getentityproperty(P2,"a");

   if(P2){
     changelevelproperty("camerazoffset", -100 - Offset2);
   }else if(P2 && P1 != NULL() && getentityproperty(P1,"exists")){
     changelevelproperty("scrollspeed", 1);
   }

   if(P1){
     changelevelproperty("camerazoffset", -100 - Offset1);
   }else if(P1 && P2 != NULL() && getentityproperty(P2,"exists")){
     changelevelproperty("camerazoffset", -100 - Offset1);
   }
}

void slamstart()
{ // Slam Starter
// Use finish after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // Slam Starter
   }
}

void slamstart2()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // Slam Starter
   }
}

void slamstart3()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL8")); // Slam Starter
   }
}

void position(int Frame, float dx, float dy, float dz, int face)
{ // Modify grabbed entity's position relative to grabber
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     updateframe(target, Frame);
     bindentity(target, self, dx, dz, dy, face, 0);
   }
}

void slamstart4(int dx, int dy, int dz)
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }

   if(target!=NULL()){
     int Tx = getentityproperty(target, "x");
     int Tz = getentityproperty(target, "z");
     int Ty = getentityproperty(target, "a");
     changeentityproperty(self, "position", Tx+dx, Tz+dz, Ty+dy); //Teleport to target!
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL8")); // Slam Starter
   }
}

void depost(int Gr)
{// Release grabbed entity
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());

     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
     }
   }
}

void depost2(int Damage, int Type, int Gr, int Stay)
{// Release grabbed entity
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());

     if(Type==1)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL11")); // 1st Finisher
     }

     if(Type==2)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL12")); // 1st Finisher
     }

     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
       changeentityproperty(target, "staydown", "rise", Stay);
     }
   }
}

void antiwall2(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if (Direction == 0){ //Is entity facing left?
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "position", x, z-Distz);
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
   }

   if(H > 0)
   {
     changeentityproperty(self, "position", x+Move);
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
   }
}

void antiwall3(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if(Direction == 0){ //Is entity facing left?
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > y)
   {
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > y)
   {
     changeentityproperty(self, "position", x+Move);
   }
}

void antiwall4(int Dist, void Ani)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;

   if(Direction == 0){ //Is entity facing left?
      Dist = -Dist; //Reverse Dist to match facing
   }

   H = checkwall(x+Dist,z);

   if(H >= y)

   {
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
     changeentityproperty(self, "animation", openborconstant(Ani));
   }
}

void antiwall5(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if(Direction == 0){ //Is entity facing left?
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "velocity", 0, 0, 0);
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > 0)
   {
     changeentityproperty(self, "velocity", 0, 0, 0);
     changeentityproperty(self, "position", x+Move);
   }
}

void finish(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as slam or throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL")); // 1st Finisher
     }

     if(Type==2)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL9")); // 2nd Finisher
     }

     tossentity(target, y, x, z); // Toss opponent ;)
     changeentityproperty(target, "direction", MDir);
   }
}

void throw(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL5")); // 1st throw type
     }

     if(Type==2)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // 2nd throw type
     }

     if(Type==3)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL")); // 3rd throw type
     }

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);
     tossentity(target, y, x, z); // Toss opponent ;)
   }
}

void slammed(int Damage)
{ // Hurt self
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health"); //Get entity's health
    if(Health >= Damage){
      damageentity(self, self, Damage, 1, openborconstant("ATK_NORMAL9")); // Damage is inserted here
    } else if(Health > 0 && Health < Damage){
      damageentity(self, self, Health, 1, openborconstant("ATK_NORMAL9")); // Damage self to death
    }
    tossentity(self, 0, 0, 0);
}

void stop()
{// Stop hero's movement!
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
}

void stopz()
{// Dash with previously attained speed + flying speed
// Used by Jetpacks to prevent diving to ground and to fly back up
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vy = getlocalvar("y"+self);
    changeentityproperty(self, "velocity", Vx, 0, Vy); //Stop moving!
}

void stopz2()
{// Dash with previously attained speed + flying speed
// Used by Jetpacks to prevent diving to ground and to fly back up
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vy = getlocalvar("y"+self);
    changeentityproperty(self, "velocity", Vx, 0, 1); //Stop moving!
}

void leaper( float Vx, float Vy, float Vz )
{// Leap with desired speed!
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    tossentity(self, Vy, Vx, Vz); //Leap!
}

void nomoveidle2(void Ani)
{// Revert to idle if left and right are not pressed
// Goes to other animation than IDLE
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKeyL = playerkeys(iPIndex, 0, "moveleft");
    void iRKeyR = playerkeys(iPIndex, 0, "moveright");

    if (!iRKeyL&&!iRKeyR){
      stop();
      performattack(self, openborconstant(Ani));
    }
}

void clearL()
{// Clears all local variables
     clearlocalvar();
}

void dasher( float Vx, float Vy, float Vz )
{// Dash with desired speed!
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    changeentityproperty(self, "velocity", Vx, Vz, Vy); //Move!
}

void dasherClimbLR( float Vx, float Vy, float Vz )
{// Dash with desired speed!
    void self = getlocalvar("self");

    changeentityproperty(self, "velocity", Vx, Vz, Vy); //Move!
}

void hurt4(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
    void self = getlocalvar("self");
    int Health = getentityproperty(self,"health");

    changeentityproperty(self, "health", Health - Damage); //Damage target with desired damage
}

void hurt6(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
    void self = getlocalvar("self");
    void target = getlocalvar("Target" + self);
    int Health = getentityproperty(self,"health");
    int AniPos = getentityproperty(self,"animpos"); //Get target's animation frame

    damageentity(self, target, Damage, 0, openborconstant("ATK_NORMAL19")); // Damage target with desired damage
    updateframe(self, AniPos);
}

void hurt7(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
    void self = getlocalvar("self");
    void target = getlocalvar("Target" + self);
    int Health = getentityproperty(self,"health");
    int AniPos = getentityproperty(self,"animpos"); //Get target's animation frame

    damageentity(self, target, Damage, 0, openborconstant("ATK_NORMAL20")); // Damage target with desired damage
    updateframe(self, AniPos);
}

void hurt8(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
    void self = getlocalvar("self");
    void target = getlocalvar("Target" + self);
    int Health = getentityproperty(self,"health");
    int AniPos = getentityproperty(self,"animpos"); //Get target's animation frame

    damageentity(self, target, Damage, 0, openborconstant("ATK_NORMAL21")); // Damage target with desired damage
    updateframe(self, AniPos);
}

void dash(int X, int Y)
{// Dash with previously attained speed!
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vy = getlocalvar("y"+self);

    if( X==1 ){
      Vy = 0;
    } else if( Y==1 ){
      Vx = 0;
    }

    changeentityproperty(self, "velocity", Vx, 0, Vy);
}

void finisher(void AniP, void Ani , int RxMin, int RxMax, int Rz, int Type, int Flag)
{// Checks closest enemy's animation & range
// If it's accepted, change animation
// AniP  : Enemy's animation
// Ani   : Animation to change to
// RxMin : Minimum x range
// RxMax : Maximum x range
// Rz    : z range
// Type  : 0 = non targetted , 1 = for targetting, 2 = for grabbing
// Flag  : 0 = facing direction not necessary , 1 = facing direction must be opposite

/*Originally smartbomb by
    Damon Vaughn Caskey
    07152008*/

    void self = getlocalvar("self");			//Caller.
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");
    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity type.
    int  iMax      = openborvariant("ent_max");         //Entity count.

     //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iType   = getentityproperty(vEntity, "type"); //Get target type.

      //Enemy type?
      if (iType == openborconstant("TYPE_ENEMY")){
        float Tx = getentityproperty(vEntity, "x");
	float Tz = getentityproperty(vEntity, "z");
        int Anti = getentityproperty(vEntity, "antigrab");
        int Edir = getentityproperty(vEntity, "direction");
	void EAnim = getentityproperty(vEntity, "animationID");

        if(EAnim == openborconstant(AniP)){
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1 ) // Target within range on right facing?
      {
        if(Type == 2){
          if(((Flag == 1 && Edir == 0) || Flag == 0) && Anti < 10){
            dasher(0,0,0);
            setlocalvar("Target" + self, vEntity);
            performattack(self, openborconstant(Ani));
          }
        } else {
          if((Flag == 1 && Edir == 0) || Flag == 0){
            if(Type == 1){
              dasher(0,0,0);
              setlocalvar("Target" + self, vEntity);
            }
            performattack(self, openborconstant(Ani));
          }
        }
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0) // Target within range on left facing?
      {
        if(Type == 2){
          if(((Flag == 1 && Edir == 1) || Flag == 0) && Anti < 10){
            dasher(0,0,0);
            setlocalvar("Target" + self, vEntity);
            performattack(self, openborconstant(Ani));
          }
        } else {
          if((Flag == 1 && Edir == 1) || Flag == 0){
            if(Type == 1){
              dasher(0,0,0);
              setlocalvar("Target" + self, vEntity);
            }
            performattack(self, openborconstant(Ani));
          }
        }
      }
        }
      }
    }
}

void keyclimb(void Key, void Ani)
{// Performs climb ladder animation if allowed & required key is held
    void self = getlocalvar("self");
    float y = getentityproperty(self, "a");
    int iPIndex = getentityproperty(self,"playerindex");
    void iRKey;

    if(Key=="U"){
      iRKey = playerkeys(iPIndex, 0, "moveup"); // "Up"

      if(iRKey){
        climber(Ani);
      }
    } else if(Key=="D"){
      climberD(Ani);
    }
}

void climber(int Rx, int Rz, void Ani)
{// Performs climb ladder up animation if ClimbSpot is found within defined range
// Rx = x distance to find ClimbSpot
// Rz = z distance to find ClimbSpot
// Ani = Animation to climb
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");

    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.

    float Tx;
    float Ty;
    float Tz;
    int THealth;
    int TDir;
    int Type;
    float Disx;
    float Disz;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iName   = getentityproperty(vEntity, "defaultname"); //Get target name

      if(iName == "ClimbSpot" || iName == "ClimbSpot2"){
        Tx = getentityproperty(vEntity, "x");
        Ty = getentityproperty(vEntity, "a");
        Tz = getentityproperty(vEntity, "z");
        THealth = getentityproperty(vEntity,"health");
        Disx = Tx - x;
        Disz = Tz - z;

        if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && y < Ty + THealth-43){
          TDir = getentityproperty(vEntity,"direction");
          Type = getentityvar(vEntity, 1);

          if(Type == NULL()){
            Type = 0;
          }

          dasher(0,0,0);
          setentityvar(self, 4, THealth);
          setentityvar(self, 5, Ty);
          setentityvar(self, 6, Type);
          changeentityproperty(self, "antigravity", 1);
          changeentityproperty(self, "position", Tx, Tz, Ty+1);
          changeentityproperty(self, "direction", TDir);
          performattack(self, openborconstant(Ani));
        }
      }
    }
}

void climber3(int Rx, int Rz, void Ani)
{// Performs climb ladder up animation if ClimbSpot is found within defined range
// Rx = x distance to find ClimbSpot3
// Rz = z distance to find ClimbSpot3
// Ani = Animation to climb
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");

    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.

    float Tx;
    float Ty;
    float Tz;
    int THealth;
    int TDir;
    int Type;
    float Disx;
    float Disz;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iName   = getentityproperty(vEntity, "defaultname"); //Get target name

      if(iName == "ClimbSpot3"){
        Tx = getentityproperty(vEntity, "x");
        Ty = getentityproperty(vEntity, "a");
        Tz = getentityproperty(vEntity, "z");
        THealth = getentityproperty(vEntity,"health");
        Disx = Tx - x;
        Disz = Tz - z;

        if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && y < Ty + THealth-20){
          TDir = getentityproperty(vEntity,"direction");
          Type = getentityvar(vEntity, 1);

          if(Type == NULL()){
            Type = 0;
          }

          dasher(0,0,0);
          setentityvar(self, 4, THealth);
          setentityvar(self, 5, Ty);
          setentityvar(self, 6, Type);
          changeentityproperty(self, "antigravity", 1);
          changeentityproperty(self, "direction", TDir);
          performattack(self, openborconstant(Ani));
        }
      }
    }
}

void spikeh(int RxMin, int RxMax, int Rz, int RyMin, int RyMax, void Ani)
{// Performs climb ladder up animation if ClimbSpot is found within defined range
// Rx = x distance to find spikeh
// Rz = z distance to find spikeh
// Ani = Animation to change
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");

    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.

    float Tx;
    float Ty;
    float Tz;
    int TDir;
    int Type;
    float Disx;
    float Disz;
    float Disy;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iName   = getentityproperty(vEntity, "defaultname"); //Get target name

      if(iName == "spikeh"){
        Tx = getentityproperty(vEntity, "x");
        Ty = getentityproperty(vEntity, "a");
        Tz = getentityproperty(vEntity, "z");
        Disx = Tx - x;
        Disz = Tz - z;
        Disy = Ty - y;

        if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax){
          TDir = getentityproperty(vEntity,"direction");
          Type = getentityvar(vEntity, 1);

          if(Type == NULL()){
            Type = 0;
          }

          changeentityproperty(self, "animation", openborconstant(Ani));
        }
      }
    }
}

void knife(int Rx, int Rz, int RyMin, int RyMax, void Ani)
{// Performs climb ladder up animation if ClimbSpot is found within defined range
// Rx = x distance to find knife1
// Rz = z distance to find knife1
// Ani = Animation to change
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");
    int Dir = getentityproperty(self, "direction");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.
    int TDir;

    float Tx;
    float Ty;
    float Tz;
    float Disx;
    float Disz;
    float Disy;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iName   = getentityproperty(vEntity, "defaultname"); //Get target name
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iName == "knife1" || iName == "knife2" || iName == "dynam"){
        if(vAniID != openborconstant("ANI_FOLLOW2")){
          Tx = getentityproperty(vEntity, "x");
          Ty = getentityproperty(vEntity, "a");
          Tz = getentityproperty(vEntity, "z");
          TDir = getentityproperty(vEntity, "direction");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;

          if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && Dir != TDir){
            changeentityproperty(vEntity, "velocity", 0, 0, 0);
            changeentityproperty(vEntity, "animation", openborconstant(Ani));
          }
        }
      }
    }
}

void climberD(int Rx, int Rz, void Ani)
{// Performs climb ladder down animation if ClimbSpot is found within defined range
// Rx = x distance to find ClimbSpot
// Rz = z distance to find ClimbSpot
// Ani = Animation to climb
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");
    int iPIndex = getentityproperty(self,"playerindex");
    void iRKey = playerkeys(iPIndex, 0, "movedown");

    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.

    float Tx;
    float Ty;
    float Tz;
    int THealth;
    int TDir;
    int Type;
    float Disx;
    float Disz;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iName   = getentityproperty(vEntity, "defaultname"); //Get target name

      if(iName == "ClimbSpot" && iRKey){
        Tx = getentityproperty(vEntity, "x");
        Ty = getentityproperty(vEntity, "a");
        Tz = getentityproperty(vEntity, "z");
        THealth = getentityproperty(vEntity,"health");
        Disx = Tx - x;
        Disz = Tz - z;

        if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && y >= Ty + THealth){
          TDir = getentityproperty(vEntity,"direction");
          Type = getentityvar(vEntity, 1);

          if(Type == NULL()){
            Type = 0;
          }

          dasher(0,0,0);
          setentityvar(self, 4, THealth);
          setentityvar(self, 5, Ty);
          setentityvar(self, 6, Type);

          changeentityproperty(self, "Subject_to_Platform", 0);
          changeentityproperty(self, "antigravity", 1);
          changeentityproperty(self, "position", Tx, Tz, Ty+THealth-43);
          changeentityproperty(self, "direction", TDir);
          performattack(self, openborconstant(Ani));
        }
      }
    }
}

void climbEnd(void Key, void Ani)
{// Ends climb ladder animation if allowed based on defined key
    void self = getlocalvar("self");
    float y = getentityproperty(self, "a");
    int LHeight = getentityvar(self, 4);
    int LZero = getentityvar(self, 5);
    int LType = getentityvar(self, 6);

    if(Key=="U" && y >= LZero + LHeight-43){ //Reached top of ladder
      dasher(0,0,0);

      if(LType != 1){
        performattack(self, openborconstant(Ani));
      }
    } else if(Key=="D" && y <= LZero){ //Reached bottom of ladder
      dasher(0,0,0);
      changeentityproperty(self, "Subject_to_Platform", 1);
      changeentityproperty(self, "antigravity", 0);
      changeentityproperty(self, "position", NULL(), NULL(), LZero+1);
      setidle(self, openborconstant("ANI_IDLE"));
    }
}

void climber2(int Rx, int Rz, void Ani)
{// Performs climb ladder up animation if ClimbSpot is found within defined range & there's opponent above
// Rx = x distance to find ClimbSpot
// Rz = z distance to find ClimbSpot
// Ani = Animation to climb
    void self = getlocalvar("self");
    void target = findtarget(self);
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");

    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.

    float Disx;
    float Disz;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iName   = getentityproperty(vEntity, "defaultname"); //Get target name

      if(iName == "ClimbSpot" || iName == "ClimbSpot2" && target!=NULL()){
        float Tx = getentityproperty(vEntity, "x");
        float Ty = getentityproperty(vEntity, "a");
        float Tz = getentityproperty(vEntity, "z");
        float Py = getentityproperty(target, "a");
        int THealth = getentityproperty(vEntity,"health");
        int Type = getentityvar(vEntity, 1);
        Disx = Tx - x;
        Disz = Tz - z;

        if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && y < Ty + THealth-43 && y >= Ty && Py - y >= THealth && Type != 1){
          int TDir = getentityproperty(vEntity,"direction");

          dasher(0,0,0);
          setentityvar(self, 1, THealth);
          setentityvar(self, 3, Ty);
          changeentityproperty(self, "antigravity", 1);
          changeentityproperty(self, "position", Tx, Tz, Ty+1);
          changeentityproperty(self, "direction", TDir);
          performattack(self, openborconstant(Ani));
        }
      }
    }
}

void climberD2(int Rx, int Rz, void Ani)
{// Performs climb ladder down animation if ClimbSpot is found within defined range & there's opponent below
// Rx = x distance to find ClimbSpot
// Rz = z distance to find ClimbSpot
// Ani = Animation to climb
    void self = getlocalvar("self");
    void target = findtarget(self);
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");

    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.

    float Disx;
    float Disz;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iName   = getentityproperty(vEntity, "defaultname"); //Get target name

      if(iName == "ClimbSpot" && target!=NULL()){
        float Tx = getentityproperty(vEntity, "x");
        float Ty = getentityproperty(vEntity, "a");
        float Tz = getentityproperty(vEntity, "z");
        float Py = getentityproperty(target, "a");
        int THealth = getentityproperty(vEntity,"health");
        Disx = Tx - x;
        Disz = Tz - z;

        if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && y >= Ty + THealth && Py - y <= -THealth){
          int TDir = getentityproperty(vEntity,"direction");

          dasher(0,0,0);
          setentityvar(self, 1, THealth);
          setentityvar(self, 3, Ty);

          changeentityproperty(self, "Subject_to_Platform", 0);
          changeentityproperty(self, "antigravity", 1);
          changeentityproperty(self, "position", Tx, Tz, Ty+THealth-43);
          changeentityproperty(self, "direction", TDir);
          performattack(self, openborconstant(Ani));
        }
      }
    }
}

void climbEnd2(void Key, void Ani)
{// Ends climb ladder animation if allowed based on defined key
    void self = getlocalvar("self");
    float y = getentityproperty(self, "a");
    int LHeight = getentityvar(self, 1);
    int LZero = getentityvar(self, 3);

    if(Key=="U" && y >= LZero + LHeight-43){ //Reached top of ladder
      dasher(0,0,0);
      performattack(self, openborconstant(Ani));
    } else if(Key=="D" && y <= LZero){ //Reached bottom of ladder
      dasher(0,0,0);
      changeentityproperty(self, "Subject_to_Platform", 1);
      changeentityproperty(self, "antigravity", 0);
      changeentityproperty(self, "position", NULL(), NULL(), LZero+1);
      setidle(self, openborconstant("ANI_IDLE"));
    }
}

void willych(int Rx, int Rz, void Ani)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.

    float Tx;
    float Tz;
    float Disx;
    float Disz;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iName   = getentityproperty(vEntity, "defaultname"); //Get target name

      if(iName == "wilend"){
        Tx = getentityproperty(vEntity, "x");
        Tz = getentityproperty(vEntity, "z");
        Disx = Tx - x;
        Disz = Tz - z;

        if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz){
          changeentityproperty(vEntity, "animation", openborconstant(Ani));
        }
      }
    }
}

void shoot(void Shot, float dx, float dy, float dz)
{ // Shooting projectile
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   void vShot;

   if (Direction == 0){ //Is entity facing left?
      dx = -dx; //Reverse X direction to match facing
   }

   vShot = projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
   return vShot;
}

void keyflip()
{// Change hero's facing direction if left or right is pressed
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index

    if (playerkeys(iPIndex, 0, "moveleft")){ // Left is pressed?
      changeentityproperty(self, "direction", 0); //Face left
    } else if (playerkeys(iPIndex, 0, "moveright")){ // Right is pressed?
      changeentityproperty(self, "direction", 1); //Face right
    }
}

void keyint2(void Ani, int Frame, void Key, int Hflag)
{// Change current animation if proper key is pressed or released
    void self = getlocalvar("self");
    int Dir = getentityproperty(self, "direction");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKey;

      if (Key=="U"){ //Up Required?
        iRKey = playerkeys(iPIndex, 0, "moveup"); // "Up"
	} else if (Key=="D"){ //Down Required?
        iRKey = playerkeys(iPIndex, 0, "movedown"); // "Down"
	} else if (Key=="L"){ //Left Required?
        iRKey = playerkeys(iPIndex, 0, "moveleft"); // "Left"
	} else if (Key=="R"){ //Right Required?
        iRKey = playerkeys(iPIndex, 0, "moveright"); // "Right"
	} else if (Key=="F"){ //Forward Required?
          if (Dir == 0){ // Facing Left?
            iRKey = playerkeys(iPIndex, 0, "moveleft"); // "Left"
          } else { // Facing Right
            iRKey = playerkeys(iPIndex, 0, "moveright"); // "Right"
          }
        } else if (Key=="B"){ //Back Required?
          if (Dir == 1){ // Facing Right?
            iRKey = playerkeys(iPIndex, 0, "moveleft"); // "Left"
          } else { // Facing Left
            iRKey = playerkeys(iPIndex, 0, "moveright"); // "Right"
          }
        } else if (Key=="J"){ //Jump Required?
        iRKey = playerkeys(iPIndex, 0, "jump"); // "Jump"
	} else if (Key=="A"){ //Attack Required?
        iRKey = playerkeys(iPIndex, 0, "attack"); // "Attack"
	} else if (Key=="A2"){ //Attack2 Required?
        iRKey = playerkeys(iPIndex, 0, "attack2"); // "Attack2"
	} else if (Key=="S"){ //Special Required?
        iRKey = playerkeys(iPIndex, 0, "special"); // "Special"
	} else if (Key=="A4"){ //Attack4 Required?
        iRKey = playerkeys(iPIndex, 0, "attack4"); // "Attack4"
	}

      if (Hflag==1){ //Not holding the button case?
        iRKey = !iRKey; //Take the opposite condition
	}

      if (iRKey){
//        performattack(self, openborconstant(Ani));
//        updateframe(self, Frame);
        changeentityproperty(self, "animation", openborconstant(Ani),2);
        changeentityproperty(self, "animpos", Frame);
      }
}

void kickObject(void Ani, int RxMin, int RxMax, int Rz)
{// Checks closest weapon & range
// If it's accepted, perform the animation
/*Originally smartbomb by
    Damon Vaughn Caskey
    07152008*/

    void self = getlocalvar("self");			//Caller.
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float b = getentityproperty(self, "base");
    int dir = getentityproperty(self, "direction");
    int iPIndex = getentityproperty(self,"playerindex");
    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity type.
    int  iMax      = openborvariant("ent_max");         //Entity count

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iType   = getentityproperty(vEntity, "type"); //Get target type.

      //Weapon type?
      if (iType == openborconstant("TYPE_ITEM")){
        float Tx = getentityproperty(vEntity, "x");
        float Ty = getentityproperty(vEntity, "a");
	float Tz = getentityproperty(vEntity, "z");
	void IName = getentityproperty(vEntity, "name");

        if((IName == "barel" || IName == "box" || IName == "rock" || IName == "wood" || IName == "boxx" || IName == "ball") && Ty == b){
          float Disx = Tx - x;
          float Disz = Tz - z;

          if(Disz < 0){
            Disz = -Disz;
          }

          if( (Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1) || (Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0)){
            dasher(0,0,0);
            setlocalvar("Object" + self, vEntity);
            setlocalvar("Target" + self, IName);
            performattack(self, openborconstant(Ani));
          }
        }
      }
    }
}

void shootObject(float fX, float fY, float fZ, float Vx, float Vy, float Vz)
{// Shoots Object from leg after kickObject function
    void self = getlocalvar("self");
    void Object = getlocalvar("Object" + self);
    void Name = getlocalvar("Target" + self);
    void Shot;

    if(Name == "barel"){
      Shot = "barel2";
    } else if(Name == "box"){
      Shot = "box2";
    } else if(Name == "rock"){
      Shot = "rock2";
    } else if(Name == "wood"){
      Shot = "wood2";
    } else if(Name == "boxx"){
      Shot = "boxx2";
    } else if(Name == "ball"){
      Shot = "ball2";
    }

    shooter2(Shot, fX, fY, fZ, Vx, Vy, Vz);
    killentity(Object);

    setlocalvar("Object" + self, NULL());
    setlocalvar("Target" + self, NULL());
}

void keyint(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKey;

      if (Key=="U"){ //Up Required?
       iRKey = playerkeys(iPIndex, 0, "moveup"); // "Up"
	}

      if (Key=="D"){ //Down Required?
        iRKey = playerkeys(iPIndex, 0, "movedown"); // "Down"
	}

      if (Key=="J"){ //Jump Required?
        iRKey = playerkeys(iPIndex, 0, "jump"); // "Jump"
	}

      if (Key=="A"){ //Attack Required?
        iRKey = playerkeys(iPIndex, 0, "attack"); // "Attack"
	}

      if (Key=="S"){ //Special Required?
        iRKey = playerkeys(iPIndex, 0, "special"); // "Special"
	}

      if (Key=="A2"){ //Attack2 Required?
        iRKey = playerkeys(iPIndex, 0, "attack2"); // "Attack2"
	}

      if (Key=="UA"){ //Up and Attack Required?
        iRKey = playerkeys(iPIndex, 0, "moveup", "Attack"); // "Up" + "Attack"
	}

      if (Key=="DA"){ //Down and Attack Required?
        iRKey = playerkeys(iPIndex, 0, "movedown", "Attack"); // "Down" + "Attack"
	}

      if (Hflag==1){ //Not holding the button case?
        iRKey = !iRKey; //Take the opposite condition
	}

      if ((Health > Limit)&&iRKey){
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
        changeentityproperty(self, "animpos", Frame);

        if (Key=="UA"){
          // This is copy of dethrown
          changeentityproperty(self, "attacking", 0);
          changeentityproperty(self, "damage_on_landing", 0);
          changeentityproperty(self, "projectile", 0);
        }

        if (Key=="DA"){
          // This is copy of dethrown
          changeentityproperty(self, "attacking", 0);
          changeentityproperty(self, "damage_on_landing", 0);
          changeentityproperty(self, "projectile", 0);
        }
      }
}

void kickreact(int RxMin, int RxMax, int Ry, int Rz, void EAni)
{// Animation change if nearby opponent is kicking
// RxMin : Minimum x range
// RxMax : Maximum x range
// Ry : Altitude difference
// Rz : Z range
// EAni : Enemy's animation to change to
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");
    void target = findtarget(self); //Get nearest opponent

    if(target!=NULL()){
      void PAnim = getentityproperty(target, "animationID");
      float Tx = getentityproperty(target, "x");
      float Ty = getentityproperty(target, "a");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disy = Ty - y;
      float Disz = Tz - z;

      if(Disy < 0){
        Disy = -Disy;
      }

      if(Disz < 0){
        Disz = -Disz;
      }

      if(PAnim == openborconstant("ANI_FOLLOW46") || PAnim == openborconstant("ANI_FOLLOW47") || PAnim == openborconstant("ANI_PAIN7") || PAnim == openborconstant("ANI_PAIN17") || PAnim == openborconstant("ANI_PAIN18") || PAnim == openborconstant("ANI_PAIN19") || PAnim == openborconstant("ANI_FREESPECIAL22") || PAnim == openborconstant("ANI_FREESPECIAL23")){
        if( Disx >= RxMin && Disx <= RxMax && Disy <= Ry && Disz <= Rz && dir == 1){
          performattack(self, openborconstant(EAni)); //Change the animation
        } else if(Disx >= -RxMax && Disx <= -RxMin && Disy <= Ry && Disz <= Rz && dir == 0){
          performattack(self, openborconstant(EAni)); //Change the animation
        }
      }
    }
}

void nograb(int Flag)
{// Turns grabbable status
    void self = getlocalvar("self");
    changeentityproperty(self, "nograb", Flag);
}

void anichange(void Ani)
{// Animation changer
    void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
}

void hurt(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     void THealth = getentityproperty(target,"health"); //Get target's health
     if(THealth > Damage)
     {
       changeentityproperty(target, "health", THealth - Damage); //Damage target with desired damage
     } else {
       changeentityproperty(target, "health", 1); //Damage target with less damage
     }
   }
}

void hurt2(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int THealth = getentityproperty(target,"health"); //Get target's health
     int TAniPos = getentityproperty(target,"animpos"); //Get target's animation frame
     if(THealth > Damage)
     {
       damageentity(target, self, Damage, 0, openborconstant("ATK_NORMAL7")); // Damage target with desired damage
       updateframe(target, TAniPos);
     } else {
       int Damage2 = THealth - 1;
       damageentity(target, self, Damage2, 0, openborconstant("ATK_NORMAL7")); //Damage target with less damage
       updateframe(target, TAniPos);
     }
   }
}

void hurt3(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int THealth = getentityproperty(target,"health"); //Get target's health
     int TAniPos = getentityproperty(target,"animpos"); //Get target's animation frame
     if(THealth > Damage)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL")); // Damage target with desired damage
       updateframe(target, TAniPos);
     } else {
       int Damage2 = THealth - 1;
       damageentity(target, self, Damage2, 1, openborconstant("ATK_NORMAL")); //Damage target with less damage
       updateframe(target, TAniPos);
     }
   }
}

void hurt5(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int THealth = getentityproperty(target,"health"); //Get target's health
     int TAniPos = getentityproperty(target,"animpos"); //Get target's animation frame
     if(THealth > Damage)
     {
       damageentity(target, self, Damage, 0, openborconstant("ATK_NORMAL13")); // Damage target with desired damage
       updateframe(target, TAniPos);
     } else {
       int Damage2 = THealth - 1;
       damageentity(target, self, Damage2, 0, openborconstant("ATK_NORMAL13")); //Damage target with less damage
       updateframe(target, TAniPos);
     }
   }
}

void hurt9(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     void THealth = getentityproperty(target,"health"); //Get target's health
     if(THealth > Damage)
     {
       changeentityproperty(target, "health", THealth - Damage); //Damage target with desired damage
     } else {
       changeentityproperty(target, "health", THealth - Damage);
       changeentityproperty(self, "animation", openborconstant("ANI_FREESPECIAL16"));
     }
   }
}

void hurt10(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     void THealth = getentityproperty(target,"health"); //Get target's health
     if(THealth > Damage)
     {
       changeentityproperty(target, "health", THealth - Damage); //Damage target with desired damage
     } else {
       changeentityproperty(target, "health", THealth - Damage);
       changeentityproperty(self, "animation", openborconstant("ANI_FREESPECIAL24"));
     }
   }
}

void keymove(float V)
{// Move hero if direction button is pressed
      void self = getlocalvar("self");
      int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	float xdir = 0;
	float zdir = 0;

      if (playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
	  xdir = -V;
	} else if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
	  xdir = V;
      }

	if(playerkeys(iPIndex, 0, "moveup")){// Up is pressed?
	  zdir = -V/2;
	} else if(playerkeys(iPIndex, 0, "movedown")){// Down is pressed?
	  zdir = V/2;
      }

	changeentityproperty(self, "velocity", xdir, zdir);
}

void spawn01(void vName, float fX, float fY, float fZ)
{
	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?
          fX = -fX; //Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.

	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

	return vSpawn; //Return spawn.
}

void spawnbind(void Name, float dx, float dy, float dz)
{ // Spawn and bind other entity
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, 0);
   bindentity(Spawn, self, dx, dz, dy, 0, 0);
}

void spawnbind2(void Name1, void Name2, float dx, float dy, float dz)
{ // Spawn and bind other entity
   void P1 = getplayerproperty(0, "entity");
   void P2 = getplayerproperty(1, "entity");
   void vAniID1 = getentityproperty(P1,"animationID");
   void vAniID2 = getentityproperty(P2,"animationID");
   void Spawn;

   if(P1 && vAniID1 == openborconstant("ANI_SPAWN") || vAniID1 == openborconstant("ANI_RESPAWN") || vAniID1 == openborconstant("ANI_FREESPECIAL26") || vAniID1 == openborconstant("ANI_FREESPECIAL27") || vAniID1 == openborconstant("ANI_FREESPECIAL28") || vAniID1 == openborconstant("ANI_FREESPECIAL29") || vAniID1 == openborconstant("ANI_FREESPECIAL30") || vAniID1 == openborconstant("ANI_FREESPECIAL31") || vAniID1 == openborconstant("ANI_FREESPECIAL32") || vAniID1 == openborconstant("ANI_FREESPECIAL33") || vAniID1 == openborconstant("ANI_FREESPECIAL34")){
     Spawn = spawn01(Name1, dx, dy, 0);
     bindentity(Spawn, P1, dx, dz, dy, 0, 0);
   }

   if(P2 && vAniID2 == openborconstant("ANI_SPAWN") || vAniID2 == openborconstant("ANI_RESPAWN") || vAniID2 == openborconstant("ANI_FREESPECIAL26") || vAniID2 == openborconstant("ANI_FREESPECIAL27") || vAniID2 == openborconstant("ANI_FREESPECIAL28") || vAniID2 == openborconstant("ANI_FREESPECIAL29") || vAniID2 == openborconstant("ANI_FREESPECIAL30") || vAniID2 == openborconstant("ANI_FREESPECIAL31") || vAniID2 == openborconstant("ANI_FREESPECIAL32") || vAniID2 == openborconstant("ANI_FREESPECIAL33") || vAniID2 == openborconstant("ANI_FREESPECIAL34")){
     Spawn = spawn01(Name2, dx, dy, 0);
     bindentity(Spawn, P2, dx, dz, dy, 0, 0);
   }
}

void adjustX()
{// Special script for Air throw
// It moves Billy right to enemy's head
    void self = getlocalvar("self");
    void target = getlocalvar("Target" + self);

    if(target==NULL())
    {
      target = getentityproperty(self, "opponent");
      setlocalvar("Target" + self, target);
    }

    if(target!=NULL())
    {
      int x = getentityproperty(target,"x"); //Get target's x coordinate
      int y = getentityproperty(target,"a"); //Get target's y coordinate
      int z = getentityproperty(target,"z"); //Get target's z coordinate

      changeentityproperty(self, "position", x, z, y); //Grounding to current base
    }
}

void entergrab()
{// Script to change jumping state to grabattacking state
// Used in air grabs
    void self = getlocalvar("self");

    changeentityproperty(self, "aiflag", "jumping", 0); // Disable jumping status
    changeentityproperty(self, "aiflag", "attacking", 1); // Enable attacking status

    changeentityproperty(self, "takeaction", "common_grabattack"); // Enters grabattack
}

void shooter2(void vName, float fX, float fY, float fZ, float Vx, float Vy, float Vz)
{//Spawns projectile next to caller and move it with speed
 //vName: Model name of entity to be spawned in
 //fX: X location adjustment
 //fY: Y location adjustment
 //fZ: Z location adjustment
 //Vx: X speed
 //Vy: Y speed
 //Vz: Z speed

   void self = getlocalvar("self"); //Get calling entity
   int Direction = getentityproperty(self, "direction");
   void vSpawn; //Spawn object.

   vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in projectile
   if (Direction == 0){ //Is entity facing left?
      Vx = -Vx; //Reverse Vx direction to match facing
   }

   changeentityproperty(vSpawn, "velocity", Vx, Vz, Vy);
}

void basechange(void Ani)
{// Check altitude. If bomb is on base, change animation!

    void self = getlocalvar("self");
    int y = getentityproperty(self,"a"); //Get bomb's altitude
    int b = getentityproperty(self, "base"); //Get base

    if( y <= 1+b ){ // On base?
      performattack(self, openborconstant(Ani)); //Change the animation
    }
}

void attack1(int RxMin, int RxMax, int Rz, void Ani)
{// Attack interruption with x and z range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1) // Target within range on right facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0) // Target within range on left facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}

void attack3(int RxMin, int RxMax, int RyMin, int RyMax, int Rz, void Ani)
{// Attack interruption with x, y and z range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Ty = getentityproperty(target, "a");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disy = Ty - y;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx >= RxMin && Disx <= RxMax && Disy >= RyMin && Disy <= RyMax && Disz <= Rz && dir == 1) // Target within range on right facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disy >= RyMin && Disy <= RyMax && Disz <= Rz && dir == 0) // Target within range on left facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}

void walljump(int C, int H, void Ani)
{// Checks if there's a wall in front of enemy
// Change animation if wall is jumpable
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");
    int x = getentityproperty(self, "x");
    int y = getentityproperty(self, "a");
    int z = getentityproperty(self, "z");

    if(dir==0){ // Facing left?
      C = -C;
    }

    if(y < checkwall(x+C,z) && y+H > checkwall(x+C,z)){
      dasher(0,0,0);
      performattack(self, openborconstant(Ani)); //Change the animation
    }
}

void teletarget(int dx, int dy, int dz)
{// Targetting opponent then teleport to target
    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");
    int dir = getentityproperty(self, "direction");

    if(dir==0){ // Facing left?
      dx = -dx ;
    }

    if(target!=NULL()){
      int Tx = getentityproperty(target, "x");
      int Tz = getentityproperty(target, "z");

      changeentityproperty(self, "position", Tx+dx, Tz+dz, dy); //Teleport to target!
    }
}

void attackoff(void Ani)
{// Cancels attack if targetted player is fallen on ground
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    int Dir = getentityproperty(self,"direction");
    int TDir = getentityproperty(target,"direction");

    if(target!=NULL()){
      void PAnim = getentityproperty(target, "animationID");

      if(PAnim == openborconstant("ANI_FOLLOW46") && Dir == 0){
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}

void attackoff2(void Ani)
{// Cancels attack if targetted player is fallen on ground
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    int Dir = getentityproperty(self,"direction");
    int TDir = getentityproperty(target,"direction");

    if(target!=NULL()){
      void PAnim = getentityproperty(target, "animationID");

      if(PAnim == openborconstant("ANI_FOLLOW46") || PAnim == openborconstant("ANI_FOLLOW47") || PAnim == openborconstant("ANI_PAIN7") || PAnim == openborconstant("ANI_PAIN17") || PAnim == openborconstant("ANI_PAIN18") || PAnim == openborconstant("ANI_PAIN19") && Dir == TDir){
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}

void attackgrd(int RxMin, int RxMax, int RaMin, int RaMax, int Rz, void Ani, void Ani2)
{// Attack interruption with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float a = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Ta = getentityproperty(target, "a");
      float Tz = getentityproperty(target, "z");
      float dir2 = getentityproperty(target, "direction");

      float Disx = Tx - x;
      float Disa = Ta - a;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( getentityproperty(target, "animationID") == openborconstant(Ani2) && Disx >= RxMin && Disx <= RxMax && Disa >= RaMin && Disa <= RaMax && Disz <= Rz && dir == 1 && dir2 == 0) // Target within range on right facing in animation "Ani2"
      {
        performattack(self, openborconstant(Ani)); //Change player animation


      } else if( getentityproperty(target, "animationID") == openborconstant(Ani2) && Disx >= -RxMax && Disx <= -RxMin && Disa >= RaMin && Disa <= RaMax && Disz <= Rz && dir == 0 && dir2 == 1) // Target within range on left facing in animation "Ani2"
      {
        performattack(self, openborconstant(Ani)); //Change player animation
      }
    }
}

void anti()
{ // Makes grabbed opponent slighty lifted to air
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     tossentity(target, 1, 0, 0); // Toss opponent a little ;)
   }
}

void grabcheckA(void Ani1, void Ani2, void Ani3)
{ // Hero's airgrab checker
// This script prevents hero from grabbing ground enemies, bikers, jetpacks, special enemies and non-enemy entities
//  Ani1 = Grab animation to play
//  Ani2 = Animation to play if hit enemy are bikers or jetpacks
//  Ani3 = Animation to play if hit opponent are not airborne enemies

    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");

    if(target!=NULL()){

      if(getentityproperty(target, "a") > 0){
        int Check = checkgrab(target);

        if(Check == 0)
        {
          changeentityproperty(self, "animation", openborconstant(Ani2));
        } else if(Check == 1){
          setlocalvar("Target" + self, target);
          changeentityproperty(self, "animation", openborconstant(Ani1));
        }
      } else {
        changeentityproperty(self, "animation", openborconstant(Ani3));
      }

    }
}

// Caskey, Damon V.
// 2016-09-14
//
// Verify target is on the ground, an enemy, and
// and facing same direction as player. This is
// for the suplex grab.
//
// I HATE these sorts of hard coded checks,
// but it's a quick and dirty solution to be compatible
// with rest of module without a total rewrite.
int grabcheck_back(int animation_success, int animation_alternate)
{
    void    entity;         // Caller entity.
    int     entity_pos_d;   // Entity position, direction.
    void    target;         // Target entity.
    int     target_pos_b;   // Target position, Base.
    int     target_pos_y;   // Target position, Y axis.
    int     target_pos_d;   // Target position, direction.
    int     var_type;       // Variable type.
    int     entity_type;    // type of entity.
    int     result;         // Final output.

    log("\n grabcheck_back");

    // Default result FALSE.
    result  = 0;

    // Get entities.
    entity  = getlocalvar("self");
    target  = getentityproperty(entity, "opponent");

    // Get variable type.
    var_type = typeof(target);

    // Is target a valid pointer?
    if(var_type == openborconstant("VT_PTR"))
    {
        log("\n grabcheck_back: Pointer");

        // Get target type.
        entity_type = getentityproperty(target, "type");

        // Is target an enemy?
        if(entity_type == openborconstant("TYPE_ENEMY"))
        {
            log("\n grabcheck_back: entity_type");

            // Get target position data.
            target_pos_b = getentityproperty(target, "base");
            target_pos_y = getentityproperty(target, "y");

            // Target at or below base?
            if(target_pos_y <= target_pos_b)
            {
                log("\n grabcheck_back: target_pos_y <= target_pos_b");

                // Get entity and target direction.
                entity_pos_d = getentityproperty(entity, "direction");
                target_pos_d = getentityproperty(target, "direction");

                // Target facing same direction as entity?
                if(target_pos_d == entity_pos_d)
                {
                    log("\n grabcheck_back: target_pos_d == entity_pos_d");

                    // Execute animation, set local target var, and return TRUE.
                    changeentityproperty(entity, "animation", animation_success);
                    setlocalvar("Target" + entity, target);
                    result = 1;
                }
            }
        }
    }

    // Return result.
    return result;
}

void grabcheckG(void Ani1, void Ani2, void Ani3)
{ // Hero's groundgrab checker
// This script prevents hero from grabbing airborne enemies, bikers, jetpacks, special enemies and non-enemy entities
//  Ani1 = Grab animation to play
//  Ani2 = Animation to play if hit enemy are bikers or jetpacks
//  Ani3 = Animation to play if hit opponent are not ground enemies

    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");
    int b = getentityproperty(target, "base"); //Get base
    int y = getentityproperty(target,"a"); //

    if(target!=NULL()){

      if(y == 0 || y <= 1+b){
        int Check = checkgrab(target);

        if(Check == 0)
        {
          changeentityproperty(self, "animation", openborconstant(Ani2));
        } else if(Check == 1){
          setlocalvar("Target" + self, target);
          changeentityproperty(self, "animation", openborconstant(Ani1));
        }
      } else {
        changeentityproperty(self, "animation", openborconstant(Ani3));
      }

    }
}

void checkgrab(void target)
{ // Opponent Checker
// This script checks hero's current opponent. If he/she/it is biker, jetpack, special enemy or non-enemy entity this function returns 0
// Otherwise it returns 1.

    if(getentityproperty(target, "type") == openborconstant("TYPE_ENEMY")){
      char Tname = getentityproperty(target, "defaultname");

      if(Tname == "bolo" || Tname == "bolo2" || Tname == "abobo" || Tname == "mibobo" || Tname == "mibobo2" || Tname == "chin" )
      { // Normal Bikers
        return 0;
      } else if(Tname == "oharra" || Tname == "oharra2" || Tname == "abore" || Tname == "burnov" || Tname == "burnov2" )
      { // Special Bikers
        return 0;
      } else if(Tname == "abore2" || Tname == "chin2" || Tname == "abobo2" || Tname == "abobo3" || Tname == "chin3" || Tname == "burnov3")
      { // Bonus Bikers, Candy & Dog
        return 0;
      } else if(Tname == "burnov4" || Tname == "burnov5" || Tname == "burnov6" || Tname == "burnov7" || Tname == "chin4" || Tname == "chin5")
      { // Jetpacks
        return 0;
      } else {
        return 1;
      }
    } else {
      return 0;
    }
}

void riseattack(int Rx, int Rz, void Ani)
{// Riseattack with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz ) // Target within range?
      {
        if(Tx < x){
          changeentityproperty(self, "direction", 0);
        } else {
          changeentityproperty(self, "direction", 1);
        }
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
      }
    }
}

void riseattack2(int Rx, int Rz, void Ani)
{// Riseattack with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz ) // Target within range?
      {
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
      }
    }
}

void riseattack3(int Rx, int Rz, void Ani)
{// Riseattack with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int Dir = getentityproperty(self,"direction");
    int TDir = getentityproperty(target,"direction");
    int b = getentityproperty(self, "base");
    int tb = getentityproperty(target, "base");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz && b == tb && Dir == TDir) // Target within range?
      {
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
      }
    }
}

void conditionalflip2()
{ // Flipping based on currently grabbed enemy
   void self = getlocalvar("self");
   void target = getentityproperty(self, "opponent");

   if(target)
   {
     int Direction = getentityproperty(self, "direction");
     int TDir = getentityproperty(target, "direction");

     if(TDir == 0 && Direction == 0){
       changeentityproperty(self, "direction", 1);
     } else if(TDir == 1 && Direction == 1){
       changeentityproperty(self, "direction", 0);
     }
   }
}

void conditionalflip3()
{ // Flipping based on currently grabbed enemy
   void self = getlocalvar("self");
   void target = getentityproperty(self, "opponent");

   if(target)
   {
     int Direction = getentityproperty(self, "direction");
     int TDir = getentityproperty(target, "direction");

     if(TDir == 1 && Direction == 1){
       changeentityproperty(self, "direction", 0);
     } else if(TDir == 0 && Direction == 0){
       changeentityproperty(self, "direction", 1);
     }
   }
}

void conditionalflip()
{
	void self = getlocalvar("self");
	int p = getentityproperty(self, "playerindex");
	int dir = getglobalvar("p"+p+"lastdir");
	int sdir = getentityproperty(self, "direction");
	int flip;
	if(dir!=NULL() && dir!=sdir)
	{
		flip = 0;
	}
	else
	{
		flip = 1;
	}

	if(flip) {
		changeentityproperty(self, "direction", !sdir);
	}

}
