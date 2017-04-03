void clear(int RxMin, int RxMax, int Rz, int RyMin, int RyMax)
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
    void P1;
    void P2;
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

      if(iType == openborconstant("TYPE_PLAYER")){
        Tx = getentityproperty(vEntity, "x");
        Ty = getentityproperty(vEntity, "a");
        Tz = getentityproperty(vEntity, "z");
        P1 = getplayerproperty(0, "entity");
        P2 = getplayerproperty(1, "entity");
        TDir = getentityproperty(vEntity, "direction");
        Disx = Tx - x;
        Disz = Tz - z;
        Disy = Ty - y;

        if(P1){
          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax){
            changeentityproperty(P1, "noaicontrol", 1);
            changeentityproperty(P1, "velocity", 0);
            performattack(P1, openborconstant("ANI_FOLLOW54"));
          }
        }

        if(P2){
          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax){
            changeentityproperty(P2, "noaicontrol", 1);
            changeentityproperty(P2, "velocity", 0);
            performattack(P2, openborconstant("ANI_FOLLOW55"));
          }
        }

        if(P1 != NULL() && getentityproperty(P1,"exists") && P2 != NULL() && getentityproperty(P2,"exists")){
          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax){
            changeentityproperty(P1, "noaicontrol", 1);
            changeentityproperty(P1, "velocity", 0);
            performattack(P1, openborconstant("ANI_FOLLOW54"));
            changeentityproperty(P2, "noaicontrol", 1);
            changeentityproperty(P2, "velocity", 0);
            performattack(P2, openborconstant("ANI_FOLLOW55"));
          }
        }
      }
    }
}

void candam(int Rx, int Rz)
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

      if(iName == "ball3" || iName == "barel3" || iName == "box3" || iName == "boxx3" || iName == "rock3" || iName == "wood3"
        || iName == "ball" || iName == "barel" || iName == "box" || iName == "boxx" || iName == "rock" || iName == "wood"
        || iName == "knife2" || iName == "dynam2" || iName == "bomb" || iName == "bomb2"){
        Tx = getentityproperty(vEntity, "x");
        Tz = getentityproperty(vEntity, "z");
        Disx = Tx - x;
        Disz = Tz - z;

        if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz){
          changeentityproperty(vEntity, "candamage", openborconstant("TYPE_ENEMY"));
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
