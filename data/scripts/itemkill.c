void kill(int Rx, int Rz, int Ry)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float y = getentityproperty(self, "a");

    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.
    int TDir;

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

      if(iType == openborconstant("TYPE_ITEM")){
        Tx = getentityproperty(vEntity, "x");
        Tz = getentityproperty(vEntity, "z");
        Ty = getentityproperty(vEntity, "a");
        TDir = getentityproperty(vEntity, "direction");
        Disx = Tx - x;
        Disz = Tz - z;
        Disy = Ty - y;

        if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && Disy >= -Ry && Disy <= Ry){
          killentity(vEntity);
        }
      }
    }
}

void kill2(int Rx, int Rz, int Ry)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float y = getentityproperty(self, "a");

    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;                                         //Entity name.
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
      iName   = getentityproperty(vEntity, "defaultname");

      if(iName == "ball" || iName == "ball1" || iName == "ball2" || iName == "ball3" || iName == "barel"  
        || iName == "barel1" || iName == "barel2" || iName == "barel3" || iName == "box" || iName == "box1"
        || iName == "box2" || iName == "box3" || iName == "boxx" || iName == "boxx1" || iName == "boxx2" || iName == "boxx3"
        || iName == "rock" || iName == "rock1" || iName == "rock2" || iName == "rock3" || iName == "wood"  || iName == "wood1"
        || iName == "wood2" || iName == "wood3"){
        Tx = getentityproperty(vEntity, "x");
        Tz = getentityproperty(vEntity, "z");
        Ty = getentityproperty(vEntity, "a");
        Disx = Tx - x;
        Disz = Tz - z;
        Disy = Ty - y;



        if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && Disy >= -Ry && Disy <= Ry){
          killentity(vEntity);
        }
      }
    }
}

void dragonkill(int Rx, int Rz, int Ry)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float y = getentityproperty(self, "a");

    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.
    int TDir;

    float Tx;
    float Tz;
    float Ty;
    float Disx;
    float Disz;
    float Disy;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iName   = getentityproperty(vEntity, "defaultname"); //Get target name

      if(iName == "dragon"){
        Tx = getentityproperty(vEntity, "x");
        Tz = getentityproperty(vEntity, "z");
        Ty = getentityproperty(vEntity, "a");
        TDir = getentityproperty(vEntity, "direction");
        Disx = Tx - x;
        Disz = Tz - z;
        Disy = Ty - y;

        if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && Disy >= -Ry && Disy <= Ry){
          killentity(vEntity);
        }
      }
    }
}
