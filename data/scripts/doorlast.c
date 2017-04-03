void dooropen(int RxMin, int RxMax, int RzMin, int RzMax, int RyMin, int RyMax, void EAni)
{// Performs climb ladder up animation if ClimbSpot is found within defined range
// Rx = x distance to find type
// Rz = z distance to find type
// Ani = Animation to change
    void vself = getlocalvar("self");
    float x = getentityproperty(vself, "x");
    float y = getentityproperty(vself, "a");
    float z = getentityproperty(vself, "z");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity name.
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
      iType   = getentityproperty(vEntity, "type"); //Get target name
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iType == openborconstant("TYPE_ENEMY")){
        if(vAniID != openborconstant("ANI_FOLLOW43") || vAniID != openborconstant("ANI_FOLLOW44") || vAniID != openborconstant("ANI_FOLLOW47")){
          Tx = getentityproperty(vEntity, "x");
          Ty = getentityproperty(vEntity, "a");
          Tz = getentityproperty(vEntity, "z");
          TDir = getentityproperty(vEntity, "direction");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;

          if(Disx >= RxMin && Disx <= RxMax && Disz <= -RzMin && Disz <= RzMax && Disy >= RyMin && Disy <= RyMax && TDir == 1){
            changeentityproperty(vEntity, "velocity", 0);
            changeentityproperty(vEntity, "direction", 1);
            changeentityproperty(vEntity, "animation", openborconstant(EAni));
          }else if(Disx >= RxMin && Disx <= RxMax && Disz <= -RzMin && Disz <= RzMax && Disy >= RyMin && Disy <= RyMax && TDir == 0){
            changeentityproperty(vEntity, "velocity", 0);
            changeentityproperty(vEntity, "direction", 1);
            changeentityproperty(vEntity, "animation", openborconstant(EAni));
          }
        }
      }
    }
}

void dooropen2(int RxMin, int RxMax, int RzMin, int RzMax, int RyMin, int RyMax, void Ani, void EAni)
{// Performs climb ladder up animation if ClimbSpot is found within defined range
// Rx = x distance to find type
// Rz = z distance to find type
// Ani = Animation to change
    void vself = getlocalvar("self");
    float x = getentityproperty(vself, "x");
    float y = getentityproperty(vself, "a");
    float z = getentityproperty(vself, "z");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity name.
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
      iType   = getentityproperty(vEntity, "type"); //Get target name
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iType == openborconstant("TYPE_ENEMY")){
        if(vAniID != openborconstant("ANI_FOLLOW43") || vAniID != openborconstant("ANI_FOLLOW44")){
          Tx = getentityproperty(vEntity, "x");
          Ty = getentityproperty(vEntity, "a");
          Tz = getentityproperty(vEntity, "z");
          TDir = getentityproperty(vEntity, "direction");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;

          if(Disx >= RxMin && Disx <= RxMax && Disz <= -RzMin && Disz <= RzMax && Disy >= RyMin && Disy <= RyMax && TDir == 1){
            changeentityproperty(vEntity, "velocity", 0);
            changeentityproperty(vEntity, "direction", 1);
            changeentityproperty(vEntity, "animation", openborconstant(EAni));
            changeentityproperty(vself, "animation", openborconstant(Ani));
          }else if(Disx >= RxMin && Disx <= RxMax && Disz <= -RzMin && Disz <= RzMax && Disy >= RyMin && Disy <= RyMax && TDir == 0){
            changeentityproperty(vEntity, "velocity", 0);
            changeentityproperty(vEntity, "direction", 1);
            changeentityproperty(vEntity, "animation", openborconstant(EAni));
            changeentityproperty(vself, "animation", openborconstant(Ani));
          }
        }
      }
    }
}

void dooropen3(int RxMin, int RxMax, int Rz, int RyMin, int RyMax, void Ani)
{// Performs climb ladder up animation if ClimbSpot is found within defined range
// Rx = x distance to find type
// Rz = z distance to find type
// Ani = Animation to change
    void vself = getlocalvar("self");
    float x = getentityproperty(vself, "x");
    float y = getentityproperty(vself, "a");
    float z = getentityproperty(vself, "z");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    void vAniID2;
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity name.
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
      iType   = getentityproperty(vEntity, "type"); //Get target name
      vAniID  = getentityproperty(vself,"animationID");
      vAniID2  = getentityproperty(vEntity,"animationID");

      if(iType == openborconstant("TYPE_PLAYER")){
        if(vAniID != openborconstant("ANI_FOLLOW2") || vAniID != openborconstant("ANI_FOLLOW2") && vAniID2 != openborconstant("ANI_FALL27") || vAniID2 != openborconstant("ANI_DIE27")){
          Tx = getentityproperty(vEntity, "x");
          Ty = getentityproperty(vEntity, "a");
          Tz = getentityproperty(vEntity, "z");
          TDir = getentityproperty(vEntity, "direction");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;

          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && TDir == 1){
            changeentityproperty(vself, "animation", openborconstant(Ani));
          }else if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && TDir == 0){
            changeentityproperty(vself, "animation", openborconstant(Ani));
          }
        }
      }
    }
}

void elev(int RxMin, int RxMax, int Rz, void Ani)
{// Performs climb ladder up animation if ClimbSpot is found within defined range
// Rx = x distance to find water
// Rz = z distance to find water
// Ani = Animation to change
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.
    int TDir;
    int TVx;

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

      if(iName == "bilend3" || iName == "bilend4"){
        if(vAniID == openborconstant("ANI_ATTACK1")){
          Tx = getentityproperty(vEntity, "x");
          Ty = getentityproperty(vEntity, "a");
          Tz = getentityproperty(vEntity, "z");
          TVx = getentityproperty(vEntity, "xdir");
          TDir = getentityproperty(vEntity, "direction");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;

          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz){
            performattack(vEntity, openborconstant(Ani));
          }
        }
      }
    }
}

void elev3(int RxMin, int RxMax, int Rz, void Ani)
{// Performs climb ladder up animation if ClimbSpot is found within defined range
// Rx = x distance to find water
// Rz = z distance to find water
// Ani = Animation to change
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.
    int TDir;
    int TVx;

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

      if(iName == "bilend3" || iName == "bilend4"){
        if(vAniID == openborconstant("ANI_FOLLOW8")){
          Tx = getentityproperty(vEntity, "x");
          Ty = getentityproperty(vEntity, "a");
          Tz = getentityproperty(vEntity, "z");
          TVx = getentityproperty(vEntity, "xdir");
          TDir = getentityproperty(vEntity, "direction");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;

          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz){
            performattack(vEntity, openborconstant(Ani));
          }
        }
      }
    }
}

void spawn01(void vName, float fX, float fY, float fZ, int iDirection)
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
