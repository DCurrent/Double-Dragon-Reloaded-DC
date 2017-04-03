// 2016-09-13
// Caskey, Damon
//
// Refined a bit from original code by magggas, which

// Universal animation constants and macros.
#include "data/scripts/animation.h"

// Universal key constants and macros.
#include "data/scripts/key.h"

// Billy & Jilly specific animations.
#include "data/chars/billy/animation.h"

// Really, the functions in ani020 should be broken down into
// separate files and imported here individually as needed. This
// would save a TON of memory, and is very easy to do when
// building a module from the beginning. Unfortunately for
// an already complete module it would mean going back over
// every single model and finding out what functions they
// use and setting up imports for all of them. I just don't feel
// like doing that right now. :P
#import "data/scripts/ani0020.h"


// Reverse direction
int dc_direction_flip(void entity)
{
    int vartype;    // Variable type.
    int pos_d;      // Position, facing.

    vartype = typeof(entity);

    // If no entity, then default to self.
    if(vartype == openborconstant("VT_EMPTY"))
    {
        entity = getlocalvar("self");
    }

    pos_d = getentityproperty(entity, "direction");

    // Reverse the direction variable.
    if(pos_d == 1)
    {
        pos_d = 0;
    }
    else
    {
        pos_d = 1;
    }

    // Apply new direction.
    changeentityproperty(entity, "direction", pos_d);
}
