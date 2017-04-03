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

void elev2(int RxMin, int RxMax, int Rz, void Ani)
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
        if(vAniID == openborconstant("ANI_FOLLOW1")){
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
        if(vAniID == openborconstant("ANI_FOLLOW4")){
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
