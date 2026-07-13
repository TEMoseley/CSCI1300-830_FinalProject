#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>

#include "Location.h"

class Player
{
private:
    Location currentLocation;
    int money;
    int kryptonite;
    int velocitySerum;
    int cementBags;
public:
    Player(Location sL);
    Location getCurrentLocation();
    void setCurrentLocation(Location nL);
};


#endif