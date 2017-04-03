void main()
{
    void self = getlocalvar("self");
    int Dir = getentityproperty(self, "direction");
    int x = getentityproperty(self, "x");
    int y = getentityproperty(self, "a");
    int z = getentityproperty(self, "z");
    int b = getentityproperty(self, "base");
    int Vx = getentityproperty(self, "xdir");
    int vAniID = getentityproperty(self,"animationID");
    int C;
    int C2;
    int D;

    if(Dir == 1){
      C = 15;
      D = 0;
    } else {
      C = -15;
      D = 1;
    }

    if(y < checkwall(x+C,z) && vAniID == openborconstant("ANI_SPAWN")){
      changeentityproperty(self, "velocity", 0, 0, 0);
      changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2"));
    }else if(checkhole(x,z,y) && (y > 41+b) && vAniID == openborconstant("ANI_SPAWN")){
      changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW11"));
    }else if(y < checkwall(x+C,z) && vAniID == openborconstant("ANI_FOLLOW11")){
      changeentityproperty(self, "velocity", -Vx);
    }else if(y == checkwall(x+C,z) && vAniID == openborconstant("ANI_FOLLOW11")){
      changeentityproperty(self, "velocity", Vx);
    }
}
