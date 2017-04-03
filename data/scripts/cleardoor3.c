void main()
{
    void self = getlocalvar("self");
    void target = findtarget(self); // locked opponent
    int dir = getentityproperty(self, "direction");
    int vAniID = getentityproperty(target,"animationID");

    if( target != NULL() && getentityproperty(target,"exists")){
      int vEnemy = openborvariant("count_npcs");

      if ( vEnemy == 1 && vAniID == openborconstant("ANI_FOLLOW8")) {
         performattack(self, openborconstant("ANI_FOLLOW12"));
         performattack(target, openborconstant("ANI_FOLLOW10"));
      }else if ( vEnemy == 2 && vAniID == openborconstant("ANI_FOLLOW8")) {
         performattack(self, openborconstant("ANI_FOLLOW12"));
         performattack(target, openborconstant("ANI_FOLLOW10"));
      }else if ( vEnemy == 2 && vAniID != openborconstant("ANI_FOLLOW8")) {
         changeentityproperty(self, "direction", dir);
      }
   }
}
