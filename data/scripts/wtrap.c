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

void wtrap(int RxMin, int RxMax, int RzMin, int RzMax, int RyMin, int RyMax)
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
    int Ivic;

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
      Ivic  = getentityproperty(vEntity,"invincible");

      if(iType == openborconstant("TYPE_ENEMY") || iType == openborconstant("TYPE_PLAYER")){
        if(vAniID == openborconstant("ANI_FALL24") || vAniID == openborconstant("ANI_SPAWN") || vAniID == openborconstant("ANI_RESPAWN")
          || vAniID == openborconstant("ANI_DIE") || vAniID == openborconstant("ANI_DIE11") || vAniID == openborconstant("ANI_DIE14")
          || vAniID == openborconstant("ANI_DIE15") || vAniID == openborconstant("ANI_DIE16") || vAniID == openborconstant("ANI_DIE17")
          || vAniID == openborconstant("ANI_DIE18") || vAniID == openborconstant("ANI_DIE19") || vAniID == openborconstant("ANI_DIE27")
          || vAniID == openborconstant("ANI_RISE") || vAniID == openborconstant("ANI_RISE7") || vAniID == openborconstant("ANI_RISE10")
          || vAniID == openborconstant("ANI_RISE12") || vAniID == openborconstant("ANI_RISE14") || vAniID == openborconstant("ANI_RISE15")
          || vAniID == openborconstant("ANI_RISE17") || vAniID == openborconstant("ANI_RISE18") || vAniID == openborconstant("ANI_RISE20")
          || vAniID == openborconstant("ANI_RISE21") || vAniID == openborconstant("ANI_SHOCK")){
          if(Ivic == 0){
            Tx = getentityproperty(vEntity, "x");
            Ty = getentityproperty(vEntity, "a");
            Tz = getentityproperty(vEntity, "z");
            TDir = getentityproperty(vEntity, "direction");
            Disx = Tx - x;
            Disz = Tz - z;
            Disy = Ty - y;

            if(Disx >= RxMin && Disx <= RxMax && Disz <= RzMin && Disz <= RzMax && Disy >= RyMin && Disy <= RyMax && TDir == 1){
              changeentityproperty(vEntity, "direction", 1);
            }else if(Disx >= RxMin && Disx <= RxMax && Disz <= RzMin && Disz <= RzMax && Disy >= RyMin && Disy <= RyMax && TDir == 0){
              changeentityproperty(vEntity, "direction", 0);
            }
          }
        }else if(vAniID != openborconstant("ANI_FALL24") || vAniID != openborconstant("ANI_SPAWN") || vAniID != openborconstant("ANI_RESPAWN")
          || vAniID != openborconstant("ANI_DIE") || vAniID != openborconstant("ANI_DIE11") || vAniID != openborconstant("ANI_DIE14")
          || vAniID != openborconstant("ANI_DIE15") || vAniID != openborconstant("ANI_DIE16") || vAniID != openborconstant("ANI_DIE17")
          || vAniID != openborconstant("ANI_DIE18") || vAniID != openborconstant("ANI_DIE19") || vAniID != openborconstant("ANI_DIE27")
          || vAniID != openborconstant("ANI_RISE") || vAniID != openborconstant("ANI_RISE7") || vAniID != openborconstant("ANI_RISE10")
          || vAniID != openborconstant("ANI_RISE12") || vAniID != openborconstant("ANI_RISE14") || vAniID != openborconstant("ANI_RISE15")
          || vAniID != openborconstant("ANI_RISE17") || vAniID != openborconstant("ANI_RISE18") || vAniID != openborconstant("ANI_RISE20")
          || vAniID != openborconstant("ANI_RISE21") || vAniID != openborconstant("ANI_SHOCK")){
          if(Ivic == 0){
            Tx = getentityproperty(vEntity, "x");
            Ty = getentityproperty(vEntity, "a");
            Tz = getentityproperty(vEntity, "z");
            TDir = getentityproperty(vEntity, "direction");
            Disx = Tx - x;
            Disz = Tz - z;
            Disy = Ty - y;

            if(Disx >= RxMin && Disx <= RxMax && Disz <= RzMin && Disz <= RzMax && Disy >= RyMin && Disy <= RyMax && TDir == 1){
              damageentity(vEntity, vself, 28, 1, openborconstant("ATK_NORMAL24"));
              changeentityproperty(vEntity, "direction", 0);
              tossentity(vEntity, 6, -1.6, 0);
            }else if(Disx >= RxMin && Disx <= RxMax && Disz <= RzMin && Disz <= RzMax && Disy >= RyMin && Disy <= RyMax && TDir == 0){
              damageentity(vEntity, vself, 28, 1, openborconstant("ATK_NORMAL24"));
              changeentityproperty(vEntity, "direction", 0);
              tossentity(vEntity, 6, -1.6, 0);
            }
          }
        }
      }
    }
}

void wtrap2(int RxMin, int RxMax, int Rz, int RyMin, int RyMax)
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
    int Ivic;

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
      Ivic  = getentityproperty(vEntity,"invincible");

      if(iType == openborconstant("TYPE_ENEMY") || iType == openborconstant("TYPE_PLAYER")){
        if(vAniID == openborconstant("ANI_BURN") || vAniID == openborconstant("ANI_SPAWN") || vAniID == openborconstant("ANI_RESPAWN")
          || vAniID == openborconstant("ANI_DIE") || vAniID == openborconstant("ANI_DIE11") || vAniID == openborconstant("ANI_DIE14")
          || vAniID == openborconstant("ANI_DIE15") || vAniID == openborconstant("ANI_DIE16") || vAniID == openborconstant("ANI_DIE17")
          || vAniID == openborconstant("ANI_DIE18") || vAniID == openborconstant("ANI_DIE19") || vAniID == openborconstant("ANI_DIE27")
          || vAniID == openborconstant("ANI_RISE") || vAniID == openborconstant("ANI_RISE7") || vAniID == openborconstant("ANI_RISE10")
          || vAniID == openborconstant("ANI_RISE12") || vAniID == openborconstant("ANI_RISE14") || vAniID == openborconstant("ANI_RISE15")
          || vAniID == openborconstant("ANI_RISE17") || vAniID == openborconstant("ANI_RISE18") || vAniID == openborconstant("ANI_RISE20")
          || vAniID == openborconstant("ANI_RISE21")){
          if(Ivic == 0){
            Tx = getentityproperty(vEntity, "x");
            Ty = getentityproperty(vEntity, "a");
            Tz = getentityproperty(vEntity, "z");
            TDir = getentityproperty(vEntity, "direction");
            Disx = Tx - x;
            Disz = Tz - z;
            Disy = Ty - y;

            if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && TDir == 1){
              changeentityproperty(vEntity, "direction", 1);
            }else if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && TDir == 0){
              changeentityproperty(vEntity, "direction", 0);
            }
          }
        }else if(vAniID != openborconstant("ANI_BURN") || vAniID != openborconstant("ANI_SPAWN") || vAniID != openborconstant("ANI_RESPAWN")
          || vAniID != openborconstant("ANI_DIE") || vAniID != openborconstant("ANI_DIE11") || vAniID != openborconstant("ANI_DIE14")
          || vAniID != openborconstant("ANI_DIE15") || vAniID != openborconstant("ANI_DIE16") || vAniID != openborconstant("ANI_DIE17")
          || vAniID != openborconstant("ANI_DIE18") || vAniID != openborconstant("ANI_DIE19") || vAniID != openborconstant("ANI_DIE27")
          || vAniID != openborconstant("ANI_RISE") || vAniID != openborconstant("ANI_RISE7") || vAniID != openborconstant("ANI_RISE10")
          || vAniID != openborconstant("ANI_RISE12") || vAniID != openborconstant("ANI_RISE14") || vAniID != openborconstant("ANI_RISE15")
          || vAniID != openborconstant("ANI_RISE17") || vAniID != openborconstant("ANI_RISE18") || vAniID != openborconstant("ANI_RISE20")
          || vAniID != openborconstant("ANI_RISE21")){
          if(Ivic == 0){
            Tx = getentityproperty(vEntity, "x");
            Ty = getentityproperty(vEntity, "a");
            Tz = getentityproperty(vEntity, "z");
            TDir = getentityproperty(vEntity, "direction");
            Disx = Tx - x;
            Disz = Tz - z;
            Disy = Ty - y;

            if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && TDir == 1){
              damageentity(vEntity, vself, 12, 1, openborconstant("ATK_BURN"));
              changeentityproperty(vEntity, "direction", 1);
              tossentity(vEntity, 3.7, -1.8, 0);
            }else if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && TDir == 0){
              damageentity(vEntity, vself, 12, 1, openborconstant("ATK_BURN"));
              changeentityproperty(vEntity, "direction", 1);
              tossentity(vEntity, 3.7, -1.8, 0);
            }
          }
        }
      }
    }
}

void wtrap3(int RxMin, int RxMax, int Rz, int RyMin, int RyMax, void Ani)
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
    int Ivic;

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
      Ivic  = getentityproperty(vEntity,"invincible");

      if(iType == openborconstant("TYPE_PLAYER")){
        if(vAniID == openborconstant("ANI_FALL24") || vAniID == openborconstant("ANI_SPAWN") || vAniID == openborconstant("ANI_RESPAWN")
          || vAniID == openborconstant("ANI_DIE") || vAniID == openborconstant("ANI_DIE11") || vAniID == openborconstant("ANI_DIE14")
          || vAniID == openborconstant("ANI_DIE15") || vAniID == openborconstant("ANI_DIE16") || vAniID == openborconstant("ANI_DIE17")
          || vAniID == openborconstant("ANI_DIE18") || vAniID == openborconstant("ANI_DIE19") || vAniID == openborconstant("ANI_DIE27")
          || vAniID == openborconstant("ANI_RISE") || vAniID == openborconstant("ANI_RISE7") || vAniID == openborconstant("ANI_RISE10")
          || vAniID == openborconstant("ANI_RISE12") || vAniID == openborconstant("ANI_RISE14") || vAniID == openborconstant("ANI_RISE15")
          || vAniID == openborconstant("ANI_RISE17") || vAniID == openborconstant("ANI_RISE18") || vAniID == openborconstant("ANI_RISE20")
          || vAniID == openborconstant("ANI_RISE21") || vAniID == openborconstant("ANI_SHOCK")){
          if(Ivic == 0){
            Tx = getentityproperty(vEntity, "x");
            Ty = getentityproperty(vEntity, "a");
            Tz = getentityproperty(vEntity, "z");
            TDir = getentityproperty(vEntity, "direction");
            Disx = Tx - x;
            Disz = Tz - z;
            Disy = Ty - y;

            if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && TDir == 1){
              changeentityproperty(vself, "direction", 1);
            }else if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && TDir == 0){
              changeentityproperty(vself, "direction", 1);
            }
          }
        }else if(vAniID != openborconstant("ANI_FALL24") || vAniID != openborconstant("ANI_SPAWN") || vAniID != openborconstant("ANI_RESPAWN")
          || vAniID != openborconstant("ANI_DIE") || vAniID != openborconstant("ANI_DIE11") || vAniID != openborconstant("ANI_DIE14")
          || vAniID != openborconstant("ANI_DIE15") || vAniID != openborconstant("ANI_DIE16") || vAniID != openborconstant("ANI_DIE17")
          || vAniID != openborconstant("ANI_DIE18") || vAniID != openborconstant("ANI_DIE19") || vAniID != openborconstant("ANI_DIE27")
          || vAniID != openborconstant("ANI_RISE") || vAniID != openborconstant("ANI_RISE7") || vAniID != openborconstant("ANI_RISE10")
          || vAniID != openborconstant("ANI_RISE12") || vAniID != openborconstant("ANI_RISE14") || vAniID != openborconstant("ANI_RISE15")
          || vAniID != openborconstant("ANI_RISE17") || vAniID != openborconstant("ANI_RISE18") || vAniID != openborconstant("ANI_RISE20")
          || vAniID != openborconstant("ANI_RISE21") || vAniID != openborconstant("ANI_SHOCK")){
          if(Ivic == 0){
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
}

void wtrap4(int RxMin, int RxMax, int Rz, int RyMin, int RyMax)
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
    int Ivic;

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
      Ivic  = getentityproperty(vEntity,"invincible");

      if(iType == openborconstant("TYPE_ENEMY") || iType == openborconstant("TYPE_PLAYER")){
        if(vAniID == openborconstant("ANI_SHOCK") || vAniID == openborconstant("ANI_SPAWN") || vAniID == openborconstant("ANI_RESPAWN")
          || vAniID == openborconstant("ANI_DIE") || vAniID == openborconstant("ANI_DIE11") || vAniID == openborconstant("ANI_DIE14")
          || vAniID == openborconstant("ANI_DIE15") || vAniID == openborconstant("ANI_DIE16") || vAniID == openborconstant("ANI_DIE17")
          || vAniID == openborconstant("ANI_DIE18") || vAniID == openborconstant("ANI_DIE19") || vAniID == openborconstant("ANI_DIE27")
          || vAniID == openborconstant("ANI_FALL24")){
          if(Ivic == 0){
            Tx = getentityproperty(vEntity, "x");
            Ty = getentityproperty(vEntity, "a");
            Tz = getentityproperty(vEntity, "z");
            TDir = getentityproperty(vEntity, "direction");
            Disx = Tx - x;
            Disz = Tz - z;
            Disy = Ty - y;

            if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && TDir == 1){
              changeentityproperty(vEntity, "direction", 1);
            }else if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && TDir == 0){
              changeentityproperty(vEntity, "direction", 0);
            }
          }
        }else if(vAniID != openborconstant("ANI_SHOCK") || vAniID != openborconstant("ANI_SPAWN") || vAniID != openborconstant("ANI_RESPAWN")
          || vAniID != openborconstant("ANI_DIE") || vAniID != openborconstant("ANI_DIE11") || vAniID != openborconstant("ANI_DIE14")
          || vAniID != openborconstant("ANI_DIE15") || vAniID != openborconstant("ANI_DIE16") || vAniID != openborconstant("ANI_DIE17")
          || vAniID != openborconstant("ANI_DIE18") || vAniID != openborconstant("ANI_DIE19") || vAniID != openborconstant("ANI_DIE27")
          || vAniID != openborconstant("ANI_FALL24")){
          if(Ivic == 0){
            Tx = getentityproperty(vEntity, "x");
            Ty = getentityproperty(vEntity, "a");
            Tz = getentityproperty(vEntity, "z");
            TDir = getentityproperty(vEntity, "direction");
            Disx = Tx - x;
            Disz = Tz - z;
            Disy = Ty - y;

            if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && TDir == 1){
              damageentity(vEntity, vself, 28, 1, openborconstant("ATK_SHOCK"));
              changeentityproperty(vEntity, "direction", 0);
              tossentity(vEntity, 6, -1.6, 0);
            }else if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && TDir == 0){
              damageentity(vEntity, vself, 28, 1, openborconstant("ATK_SHOCK"));
              changeentityproperty(vEntity, "direction", 0);
              tossentity(vEntity, 6, -1.6, 0);
            }
          }
        }
      }
    }
}
