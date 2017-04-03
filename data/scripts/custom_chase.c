void main()
{
    void self = getlocalvar("self");
    void target = findtarget(self); // locked opponent
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self,"direction");

    if( target != NULL() && getentityproperty(target,"exists")){
      int tdir = getentityproperty(target,"direction");
      float tx = getentityproperty(target, "x");
      float tz = getentityproperty(target, "z");
      int vEnemy = openborvariant("count_enemies");
      float Disx = tx - x;
      float Disz = tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if ( vEnemy > 1 ) {
         if ( dir != tdir && Disz < 55 ) {
             changeentityproperty(self, "aimove", openborconstant("AIMOVE1_NORMAL"));
         } else if ( dir != tdir && Disz > 55 ) {
	     changeentityproperty(self, "aimove", openborconstant("AIMOVE1_CHASEZ"));
         } else if ( dir == tdir ) {
	     changeentityproperty(self, "aimove", openborconstant("AIMOVE1_CHASE"));
         }

      } else if ( vEnemy == 1 ) {
         changeentityproperty(self, "aimove", openborconstant("AIMOVE1_CHASE"));
      }
   }
}
