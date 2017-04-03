void kill(int Rx, int Rz, int Ry)
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
    int TDir;
    int Vx;

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
        if(vAniID == openborconstant("ANI_WALKOFF") || vAniID == openborconstant("ANI_FOLLOW25") || vAniID == openborconstant("ANI_FOLLOW37") || vAniID == openborconstant("ANI_FOLLOW38") || vAniID == openborconstant("ANI_FORWARDJUMP") || vAniID == openborconstant("ANI_FREESPECIAL9") || vAniID == openborconstant("ANI_FALL") || vAniID == openborconstant("ANI_FREESPECIAL25")  || vAniID == openborconstant("ANI_FREESPECIAL17") || vAniID == openborconstant("ANI_FOLLOW48")  || vAniID == openborconstant("ANI_FOLLOW19")  || vAniID == openborconstant("ANI_FALL5") || vAniID == openborconstant("ANI_FALL10") || vAniID == openborconstant("ANI_FALL14") || vAniID == openborconstant("ANI_FALL15") || vAniID == openborconstant("ANI_FALL20") || vAniID == openborconstant("ANI_FALL21") || vAniID == openborconstant("ANI_FALL23")){
          Tx = getentityproperty(vEntity, "x");
          Tz = getentityproperty(vEntity, "z");
          Ty = getentityproperty(vEntity, "a");
          TDir = getentityproperty(vEntity, "direction");
          Vx = getentityproperty(vEntity, "xdir");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;

          if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && Disy >= -Ry && Disy <= Ry && Vx > 0){
            damageentity(vEntity, self, 300, 1, openborconstant("ATK_NORMAL27"));
            changeentityproperty(vEntity, "direction", 1);
            changeentityproperty(vEntity, "velocity", Vx, 0, -2);
          }else if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && Disy >= -Ry && Disy <= Ry && Vx < 0){
            damageentity(vEntity, self, 300, 1, openborconstant("ATK_NORMAL27"));
            changeentityproperty(vEntity, "direction", 0);
            changeentityproperty(vEntity, "velocity", Vx, 0, -2);
          }else if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && Disy >= -Ry && Disy <= Ry && Vx == 0){
            damageentity(vEntity, self, 300, 1, openborconstant("ATK_NORMAL27"));
            changeentityproperty(vEntity, "direction", TDir);
            changeentityproperty(vEntity, "velocity", 0, 0, -2);
          }
        }
      }else if(iType == openborconstant("TYPE_ENEMY")){
        Tx = getentityproperty(vEntity, "x");
        Tz = getentityproperty(vEntity, "z");
        Ty = getentityproperty(vEntity, "a");
        TDir = getentityproperty(vEntity, "direction");
        Vx = getentityproperty(vEntity, "xdir");
        Disx = Tx - x;
        Disz = Tz - z;
        Disy = Ty - y;

        if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && Disy >= -Ry && Disy <= Ry && Vx > 0){
          damageentity(vEntity, self, 300, 1, openborconstant("ATK_NORMAL4"));
          changeentityproperty(vEntity, "direction", 1);
          changeentityproperty(vEntity, "velocity", 1.5, 0, -2);
        }else if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && Disy >= -Ry && Disy <= Ry && Vx < 0){
          damageentity(vEntity, self, 300, 1, openborconstant("ATK_NORMAL4"));
          changeentityproperty(vEntity, "direction", 0);
          changeentityproperty(vEntity, "velocity", -1.5, 0, -2);
        }else if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && Disy >= -Ry && Disy <= Ry && Vx == 0){
          damageentity(vEntity, self, 300, 1, openborconstant("ATK_NORMAL4"));
          changeentityproperty(vEntity, "direction", TDir);
          changeentityproperty(vEntity, "velocity", 0, 0, -2);
        }
      }else if(iType == openborconstant("TYPE_ITEM") || iType == openborconstant("TYPE_NPC") || iType == openborconstant("TYPE_NONE")){
        if(vAniID != openborconstant("ANI_FOLLOW10")){
          Tx = getentityproperty(vEntity, "x");
          Tz = getentityproperty(vEntity, "z");
          Ty = getentityproperty(vEntity, "a");
          TDir = getentityproperty(vEntity, "direction");
          Vx = getentityproperty(vEntity, "xdir");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;

          if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && Disy >= -Ry && Disy <= Ry && Vx > 0){
            changeentityproperty(vEntity, "animation", openborconstant("ANI_FOLLOW10"));
          }else if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && Disy >= -Ry && Disy <= Ry && Vx < 0){
            changeentityproperty(vEntity, "animation", openborconstant("ANI_FOLLOW10"));
          }else if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && Disy >= -Ry && Disy <= Ry && Vx == 0){
            changeentityproperty(vEntity, "animation", openborconstant("ANI_FOLLOW10"));
          }
        }
      }
    }
}
