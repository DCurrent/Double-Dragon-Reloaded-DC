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
        || iName == "roper" || iName == "broper" || iName == "williams" || iName == "batliams" || iName == "bbox"
        || iName == "dynam2" || iName == "dynam" || iName == "box" || iName == "box1" || iName == "box2" || iName == "box3"
        || iName == "whip" || iName == "bat" || iName == "knife" || iName == "knife1" || iName == "knife2"  || iName == "jeff"
        || iName == "linda" || iName == "lindaw" || iName == "kroper" || iName == "kniliams"){
        if(vAniID != openborconstant("ANI_FOLLOW50")){
          Tx = getentityproperty(vEntity, "x");
          Ty = getentityproperty(vEntity, "a");
          Tz = getentityproperty(vEntity, "z");
          TVx = getentityproperty(vEntity, "xdir");
          TDir = getentityproperty(vEntity, "direction");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;

          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && y > Ty+2 && y < Ty+10 && TDir ==0){
            changeentityproperty(vEntity, "direction", 1);
            changeentityproperty(vEntity, "animation", openborconstant(Ani));
          }else if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && y > Ty+2 && y < Ty+10 && TDir ==1){
            changeentityproperty(vEntity, "direction", 1);
            changeentityproperty(vEntity, "animation", openborconstant(Ani));
          }
        }
      }
    }
}
