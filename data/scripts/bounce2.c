void main()
{
    void self = getlocalvar("self");
    int Dir = getentityproperty(self, "direction");
    int x = getentityproperty(self, "x");
    int y = getentityproperty(self, "a");
    int z = getentityproperty(self, "z");
    int Vx = getentityproperty(self, "xdir");
    int C;
    int D;

    if(Dir == 1){
      C = 15;
      D = 0;
    } else {
      C = -15;
      D = 1;
    }

    if(y < checkwall(x+C,z) && Dir == 0)
    {
      changeentityproperty(self, "direction", 1);
      changeentityproperty(self, "velocity", -Vx);
    }else if(y < checkwall(x+C,z) && Dir == 1)
    {
      changeentityproperty(self, "direction", 0);
      changeentityproperty(self, "velocity", -Vx);
    }
}
