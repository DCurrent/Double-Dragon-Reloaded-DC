#define MAX_ALTITUDE 5000
void main() {
    void self = getlocalvar("self");
    void P1 = getplayerproperty(0, "entity");
    void P2 = getplayerproperty(1, "entity");

    set_coordsP1_predeath(self);
    set_coordsP1(self);
    set_coordsP2_predeath(self);
    set_coordsP2(self);
}

int set_coordsP1(void P1) {
    if ( getentityproperty(P1, "animationid") == openborconstant("ANI_RESPAWN") ) {
        int x3 = getentityproperty(P1, "x");
        int y3 = getentityproperty(P1, "a");
        int z3 = getentityproperty(P1, "z");
        float x1,z1,a1;
        float Hz1;
        float Hz3;
        float Hz5;
        int t;

        Hz1 = checkwall(x3,z3-10);
        Hz3 = checkwall(x3,z3-10);
        Hz5 = checkhole(x3+10,z3);

        x1 = getglobalvar("P1"+"respawn_x");
        z1 = getglobalvar("P1"+"respawn_z");
        a1 = getglobalvar("P1"+"respawn_a");

        if ( x1 != NULL() && z1 != NULL() && a1 != NULL() && Hz1 > y3 ) {
            changeentityproperty(P1, "position", x1-30, z1+10, a1);
        }else if ( x1 != NULL() && z1 != NULL() && a1 != NULL() && Hz3 < y3 ) {
            changeentityproperty(P1, "position", x1-30, z1+10, a1);
        }else if ( x1 != NULL() && z1 != NULL() && a1 != NULL() && Hz5 > y3 ) {
            changeentityproperty(P1, "position", x1-60, z1+10, a1);
        }else if ( x1 != NULL() && z1 != NULL() && a1 != NULL() && Hz5 < y3 ) {
            changeentityproperty(P1, "position", x1-30, z1, a1);
        }else if ( x1 != NULL() && z1 != NULL() && a1 != NULL() ) {
            changeentityproperty(P1, "position", x1, z1, a1);
        }
    }
}

int set_coordsP1_predeath(void P1) {
    int frames = 2, mem_frames = 2; // 150
    int refresh_time = openborvariant("elapsed_time")%frames;
    int anim_id = getentityproperty(P1, "animationid");

    if ( refresh_time == 0 && anim_id != openborconstant("ANI_RESPAWN") ) {
        float x1 = getentityproperty(P1, "x");
        float z1 = getentityproperty(P1, "z");
        float a1 = getentityproperty(P1, "a");
        float base1 = getentityproperty(P1, "base");

        if ( ( anim_id == openborconstant("ANI_IDLE") || anim_id == openborconstant("ANI_RUN") || anim_id == openborconstant("ANI_WALK") || anim_id == openborconstant("ANI_LAND")
            || anim_id == openborconstant("ANI_GET") || anim_id == openborconstant("ANI_BLOCK") || anim_id == openborconstant("ANI_UP") || anim_id == openborconstant("ANI_DOWN")
            || anim_id == openborconstant("ANI_JUMPLAND") )
            && checkhole(x1,z1) == 0 && (a1 == base1) ) {

            setglobalvar("P1"+"respawn_x", x1+30);
            setglobalvar("P1"+"respawn_z", z1-10);
            setglobalvar("P1"+"respawn_a", a1);
        }
    }
}

int set_coordsP2(void P2) {
    if ( getentityproperty(P2, "animationid") == openborconstant("ANI_RESPAWN") ) {
        int x4 = getentityproperty(P2, "x");
        int y4 = getentityproperty(P2, "a");
        int z4 = getentityproperty(P2, "z");
        float x2,z2,a2;
        float Hz2;
        float Hz4;
        float Hz6;
        int t;

        Hz2 = checkwall(x4,z4-10);
        Hz4 = checkwall(x4,z4-10);
        Hz6 = checkhole(x4+10,z4);

        x2 = getglobalvar("P2"+"respawn_x");
        z2 = getglobalvar("P2"+"respawn_z");
        a2 = getglobalvar("P2"+"respawn_a");

        if ( x2 != NULL() && z2 != NULL() && a2 != NULL() && Hz2 > y4 ) {
            changeentityproperty(P2, "position", x2-30, z2+10, a2);
        }else if ( x2 != NULL() && z2 != NULL() && a2 != NULL() && Hz4 < y4 ) {
            changeentityproperty(P2, "position", x2-30, z2+10, a2);
        }else if ( x2 != NULL() && z2 != NULL() && a2 != NULL() && Hz6 > y4 ) {
            changeentityproperty(P2, "position", x2-60, z2+10, a2);
        }else if ( x2 != NULL() && z2 != NULL() && a2 != NULL() && Hz6 < y4 ) {
            changeentityproperty(P2, "position", x2-30, z2, a2);
        }else if ( x2 != NULL() && z2 != NULL() && a2 != NULL() ) {
            changeentityproperty(P2, "position", x2, z2, a2);
        }
    }
}

int set_coordsP2_predeath(void P2) {
    int frames = 2, mem_frames = 2; // 150
    int refresh_time = openborvariant("elapsed_time")%frames;
    int anim_id = getentityproperty(P2, "animationid");

    if ( refresh_time == 0 && anim_id != openborconstant("ANI_RESPAWN") ) {
        float x2 = getentityproperty(P2, "x");
        float z2 = getentityproperty(P2, "z");
        float a2 = getentityproperty(P2, "a");
        float base2 = getentityproperty(P2, "base");

        if ( ( anim_id == openborconstant("ANI_IDLE") || anim_id == openborconstant("ANI_RUN") || anim_id == openborconstant("ANI_WALK") || anim_id == openborconstant("ANI_LAND")
            || anim_id == openborconstant("ANI_GET") || anim_id == openborconstant("ANI_BLOCK") || anim_id == openborconstant("ANI_UP") || anim_id == openborconstant("ANI_DOWN")
            || anim_id == openborconstant("ANI_JUMPLAND") )
            && checkhole(x2,z2) == 0 && (a2 == base2) ) {

            setglobalvar("P2"+"respawn_x", x2+30);
            setglobalvar("P2"+"respawn_z", z2-10);
            setglobalvar("P2"+"respawn_a", a2);
        }
    }
}
