void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void anichange(void Ani)
{// Animation changer
    void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
}

void move(int dx, int dz,int da)
{ // Moves entity freely or ignores obstacles
    void self = getlocalvar("self");
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int z = getentityproperty(self,"z"); //Get character's z coordinate
    int a = getentityproperty(self,"a"); //Get character's a coordinate
    int dir = getentityproperty(self,"direction"); //Get character's facing direction

     if(dir==0){ // Facing left?
      changeentityproperty(self, "position", x-dx, z+dz, a+da); //Move
     }
     else if(dir==1){ // Facing right?
      changeentityproperty(self, "position", x+dx, z+dz, a+da); //Move
     }
}

void basechange(void Ani)
{// Check altitude. If bomb is on base, change animation!

    void self = getlocalvar("self");
    int y = getentityproperty(self,"a"); //Get bomb's altitude
    int b = getentityproperty(self, "base"); //Get base

    if( y <= 1+b ){ // On base?
      performattack(self, openborconstant(Ani)); //Change the animation
    }
}

void antiwall4(int Dist, int Move)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move;
   }

   H = checkwall(x+Dist,z);

   if(H >= y)

   {
     changeentityproperty(self, "position", x+Move);
   }
}

void antiwall5(int Dist, void Ani)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
   }

   H = checkwall(x+Dist,z);

   if(H >= y)

   {
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
     changeentityproperty(self, "animation", openborconstant(Ani));
   }
}

void antiwall6(int Dist, void Ani)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
   }

   H = checkwall(x+Dist,z);

   if(H > y)

   {
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
     changeentityproperty(self, "animation", openborconstant(Ani));
   }
}
