#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>

#include "Location.h"
#include "Game.h"
#include "Hero.h"
#include "Villain.h"

class Player
{
private:
    Location currentLocation;
    int money;
    int kryptonite;
    int velocitySerum;
    int cementBags;
    int lassoOfTruth;
    bool arrestedClayface;
    bool arrestedReverseFlash;
    bool arrestedLexLuthor;
public:
    Player(Location sL);
    Location getCurrentLocation();
    void setCurrentLocation(Location nL);
    MenuResult displayCurrentInventory(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
};


#endif