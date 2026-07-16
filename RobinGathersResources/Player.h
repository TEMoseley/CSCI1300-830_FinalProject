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
    int getMoney();
    int getKryptonite();
    int getVelocitySerum();
    int getCementBags();
    int getLassoOfTruth();
    void setMoney(int m);
    void setKryptonite(int k);
    void setVelocitySerum(int vS);
    void setCementBags(int cB);
    void setLassoOfTruth(int lOT);
    void setArrestedClayface(bool aC);
    void setArrestedReverseFlash(bool aRF);
    void setArrestedLexLuthor(bool aLL);
    bool getArrestedClayface();
    bool getArrestedReverseFlash();
    bool getArrestedLexLuthor();
    MenuResult displayCurrentInventory(Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
};


#endif