void killerkill(int Rx, int Rz)
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

      if(iName == "killer"){
        Tx = getentityproperty(vEntity, "x");
        Tz = getentityproperty(vEntity, "z");
        Disx = Tx - x;
        Disz = Tz - z;

        if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz){
          killentity(vEntity);
        }
      }
    }
}