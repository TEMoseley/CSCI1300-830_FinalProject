#include <string>
#include <vector>
#include <iostream>

#include "Location.h"
#include "Player.h"


using namespace std;

Player::Player(Location sL) : currentLocation(sL) {
    currentLocation = sL;
    money = 10;
    kryptonite = 0;
    velocitySerum = 0;
    cementBags = 0;
}

Location Player::getCurrentLocation(){
    return currentLocation;
}

void Player::setCurrentLocation(Location nL){
    currentLocation = nL;
}