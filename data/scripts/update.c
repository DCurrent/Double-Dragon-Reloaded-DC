void main()
{// Update script for displaying current HP from each player with health blocks
    void P1 = getplayerproperty(0, "entity");
    void P2 = getplayerproperty(1, "entity");
    void Health = getglobalvar("health");
    void Health2 = getglobalvar("health2");
    void Bar = getglobalvar("Bar");

//    float x = getentityproperty(P1, "x");
//    drawstring(50,150,4, x);

//    void Model = getentityproperty(P1, "model"); // Temp

//    drawstring(50,150,4, Model);
//    drawstring(50,150,4, openborvariant("count_players"));

    if(openborvariant("in_level")==1){
      if(P1){
        int HP1 = getentityproperty(P1, "health");

        float velocity_y = getentityproperty(P1, "tossv");

        void opp = getentityproperty(P1, "opponent");
        int  oHP = getentityproperty(opp, "health");

        settextobj(1,
           15,
            35,
            1,
            -1,
            oHP);


/*
        void animation_handle   = getentityproperty(P1, "animation.handle", openborconstant("ANI_ATTACK2"));
        void attack_frame       = get_animation_property(animation_handle, openborconstant("ANI_PROP_ATTACK"));
        void attack_collection  = get_attack_collection(attack_frame, 1);
        void attack_instance    = get_attack_instance(attack_collection, 0);
        int  attack_force;
        if(attack_instance)
        {
            attack_force       = get_attack_property(attack_instance, openborconstant("ATTACK_PROP_DAMAGE_FORCE"));
        }

        //velocity_y = get_animation_property(animation_handle, 1, openborconstant("ANI_PROP_BBOX"));
        //velocity_y = animation_handle; //openborconstant("ANI_PROP_NUMFRAMES");

        settextobj(1,
           15,
            35,
            1,
            -1,
            attack_force);

        void body_frame       = get_animation_property(animation_handle, openborconstant("ANI_PROP_BODY_COLLISION"));
        void body_collection  = get_body_collision_collection(body_frame, 1);
        void body_instance    = get_body_collision_instance(body_collection, 0);
        int  body_size_x;
        if(body_instance)
        {
            body_size_x       = get_body_collision_property(body_instance, openborconstant("BODY_COLLISION_PROP_POSITION_X"));
        }

        settextobj(2,
           15,
            55,
            1,
            -1,
            body_size_x);

        drawsprite(Bar, 100, 461, 2500);
*/
        if(HP1>0 && HP1<10){
          drawsprite(Health, 103, 463, 11000);
        } else if(HP1>=10 && HP1<20){
          drawsprite(Health, 103, 463, 11000);
        } else if(HP1>=20){
          drawsprite(Health, 103, 463, 11000);
        }

        if(HP1>=20 && HP1<30){
          drawsprite(Health, 123, 463, 11000);
        } else if(HP1>=30 && HP1<40){
          drawsprite(Health, 123, 463, 11000);
        } else if(HP1>=40){
          drawsprite(Health, 123, 463, 11000);
        }

        if(HP1>=40 && HP1<50){
          drawsprite(Health, 143, 463, 11000);
        } else if(HP1>=50 && HP1<60){
          drawsprite(Health, 143, 463, 11000);
        } else if(HP1>=60){
          drawsprite(Health, 143, 463, 11000);
        }

        if(HP1>=60 && HP1<70){
          drawsprite(Health, 163, 463, 11000);
        } else if(HP1>=70 && HP1<80){
          drawsprite(Health, 163, 463, 11000);
        } else if(HP1>=80){
          drawsprite(Health, 163, 463, 11000);
        }

        if(HP1>=80 && HP1<90){
          drawsprite(Health, 183, 463, 11000);
        } else if(HP1>=90 && HP1<100){
          drawsprite(Health, 183, 463, 11000);
        } else if(HP1==100){
          drawsprite(Health, 183, 463, 11000);
        }
      }

      if(P2){
        int HP2 = getentityproperty(P2, "health");
        drawsprite(Bar, 500, 461, 2500);

        if(HP2>0 && HP2<10){
          drawsprite(Health2, 503, 463, 11000);
        } else if(HP2>=10 && HP2<20){
          drawsprite(Health2, 503, 463, 11000);
        } else if(HP2>=20){
          drawsprite(Health2, 503, 463, 11000);
        }

        if(HP2>=20 && HP2<30){
          drawsprite(Health2, 523, 463, 11000);
        } else if(HP2>=30 && HP2<40){
          drawsprite(Health2, 523, 463, 11000);
        } else if(HP2>=40){
          drawsprite(Health2, 523, 463, 11000);
        }

        if(HP2>=40 && HP2<50){
          drawsprite(Health2, 543, 463, 11000);
        } else if(HP2>=50 && HP2<60){
          drawsprite(Health2, 543, 463, 11000);
        } else if(HP2>=60){
          drawsprite(Health2, 543, 463, 11000);
        }

        if(HP2>=60 && HP2<70){
          drawsprite(Health2, 563, 463, 11000);
        } else if(HP2>=70 && HP2<80){
          drawsprite(Health2, 563, 463, 11000);
        } else if(HP2>=80){
          drawsprite(Health2, 563, 463, 11000);
        }

        if(HP2>=80 && HP2<90){
          drawsprite(Health2, 583, 463, 11000);
        } else if(HP2>=90 && HP2<100){
          drawsprite(Health2, 583, 463, 11000);
        } else if(HP2==100){
          drawsprite(Health2, 583, 463, 11000);
        }
      }
    }
}

void oncreate()
{
    void Health;
    void Health2;
    void Bar;

    if(!Health){
      Health = loadsprite("data/sprites/health.png");
      Health2 = loadsprite("data/sprites/health2.png");
      Bar = loadsprite("data/sprites/lifebar.png");
      setglobalvar("health", Health);
      setglobalvar("health2", Health2);
      setglobalvar("Bar", Bar);
    }
}

void ondestroy(){
    void Health = getglobalvar("health");
    void Health2 = getglobalvar("health2");
    void Bar = getglobalvar("Bar");

    if(Health){
      free(Health);
      free(Health2);
      free(Bar);

      setglobalvar("health", NULL());
      setglobalvar("health2", NULL());
      setglobalvar("Bar", NULL());
    }
}
