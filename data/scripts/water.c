void water(int RxMin, int RxMax, int Rz, void Ani)
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
    int  iType;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.

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

      if(iType == openborconstant("TYPE_ENEMY") || iType == openborconstant("TYPE_PLAYER") || iType == openborconstant("TYPE_ITEM") || iType == openborconstant("TYPE_NPC") || iType == openborconstant("TYPE_NONE")){
        if(vAniID != openborconstant("ANI_FOLLOW49")){
          Tx = getentityproperty(vEntity, "x");
          Ty = getentityproperty(vEntity, "a");
          Tz = getentityproperty(vEntity, "z");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;

          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && y > Ty+80){
            changeentityproperty(vEntity, "animation", openborconstant(Ani));
          }
        }
      }
    }
}
