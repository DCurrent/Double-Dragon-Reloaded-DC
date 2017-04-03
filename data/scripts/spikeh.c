void spikeh(int RxMin, int RxMax, int Rz, void Ani)
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

      if(iName == "billy" || iName == "bbat" || iName == "bwhip" || iName == "bknife" || iName == "bdynam"  
        || iName == "roper" || iName == "broper" || iName == "williams" || iName == "batliams" || iName == "bolo"
        || iName == "bolo2" || iName == "linda" || iName == "linda2" || iName == "lindaw" || iName == "lindaw2"){
        if(vAniID != openborconstant("ANI_FOLLOW39")){
          Tx = getentityproperty(vEntity, "x");
          Ty = getentityproperty(vEntity, "a");
          Tz = getentityproperty(vEntity, "z");
          TVx = getentityproperty(vEntity, "xdir");
          TDir = getentityproperty(vEntity, "direction");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;

          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && y > Ty+5 && TVx > 0){
            changeentityproperty(vEntity, "direction", 1);
            changeentityproperty(vEntity, "animation", openborconstant(Ani));
          }else if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && y > Ty+5 && TVx < 0){
            changeentityproperty(vEntity, "direction", 0);
            changeentityproperty(vEntity, "animation", openborconstant(Ani));
          }else if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && y > Ty+5 && TVx == 0){
            changeentityproperty(vEntity, "animation", openborconstant(Ani));
          }
        }
      }
    }
}

void spikeh4er(int RxMin, int RxMax, int Rz, int RyMin, int RyMax)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float y = getentityproperty(self, "a");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.

    float Tx;
    float Tz;
    float Ty;
    float Disx;
    float Disz;
    float Disy;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iType   = getentityproperty(vEntity, "type");
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iType == openborconstant("TYPE_PLAYER")){
        if(vAniID == openborconstant("ANI_FOLLOW20") || vAniID == openborconstant("ANI_FOLLOW22") || vAniID == openborconstant("ANI_FOLLOW23") || vAniID == openborconstant("ANI_FOLLOW26")
        || vAniID == openborconstant("ANI_FOLLOW27") || vAniID == openborconstant("ANI_FOLLOW28") || vAniID == openborconstant("ANI_FOLLOW31") || vAniID == openborconstant("ANI_FOLLOW34")
        || vAniID == openborconstant("ANI_FOLLOW35") || vAniID == openborconstant("ANI_FOLLOW29") || vAniID == openborconstant("ANI_FOLLOW30")){
          Tx = getentityproperty(vEntity, "x");
          Tz = getentityproperty(vEntity, "z");
          Ty = getentityproperty(vEntity, "a");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;


          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax){
            changeentityproperty(vEntity, "direction", 1);
            changeentityproperty(vEntity, "animation", openborconstant("ANI_FOLLOW32"));
          }
        }
      }
    }
}
