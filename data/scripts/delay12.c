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

      if ( vEnemy <= 3 ) {
         killentity(self);
      }
   }
}
