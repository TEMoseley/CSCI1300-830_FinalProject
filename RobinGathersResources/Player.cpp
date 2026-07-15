#include <string>
#include <vector>
#include <iostream>

#include "Player.h"

using namespace std;

Player::Player(Location sL) : currentLocation(sL) {
    currentLocation = sL;
    money = 10;
    kryptonite = 0;
    velocitySerum = 0;
    cementBags = 0;
    lassoOfTruth = 0;
}

MenuResult Player::displayCurrentInventory(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "Money in thousands: $" << money << endl;
    cout << "Kryptonite crystals: " << kryptonite << endl;
    cout << "Vials of Velocity Serum: " << velocitySerum << endl;
    cout << "Bags of cement: " << cementBags << endl;
    cout << "Lasso of Truth: " << lassoOfTruth << endl;

    while (true){
        if (promptInt("When ready to return, press 1: ") == 1){
            break;
        }
    }
    return displayMainMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
}

Location Player::getCurrentLocation(){
    return currentLocation;
}

void Player::setCurrentLocation(Location nL){
    currentLocation = nL;
}