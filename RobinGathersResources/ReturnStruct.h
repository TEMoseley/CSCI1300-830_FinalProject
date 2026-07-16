#ifndef RETURN_STRUCT_H
#define RETURN_STRUCT_H

#include "Game.h"
#include "Player.h"
#include "Hero.h"
#include "Villain.h"

struct ReturnStruct{ // A struct so I can permanently adjust class instances, fixing pass-by-value bug
    MenuResult mR;
    Game g;
    Player p;
    Location l0;
    Location l1;
    Location l2;
    Location l3;
    Hero h0;
    Hero h1;
    Hero h2;
    Hero h3;
    Villain v0;
    Villain v1;
    Villain v2;
};

#endif