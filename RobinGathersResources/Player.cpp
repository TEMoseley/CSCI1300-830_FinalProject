#include <string>
#include <vector>
#include <iostream>

#include "Player.h"

using namespace std;

Player::Player(Location sL) : currentLocation(sL) {
    currentLocation = sL;
    money = 30;
    kryptonite = 3;
    velocitySerum = 2;
    cementBags = 30;
    lassoOfTruth = 0;
    arrestedClayface = false;
    arrestedReverseFlash = false;
    arrestedLexLuthor = false;
}

MenuResult Player::displayCurrentInventory(Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
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
    return displayMainMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
}

Location Player::getCurrentLocation(){
    return currentLocation;
}

void Player::setCurrentLocation(Location nL){
    currentLocation = nL;
}

int Player::getMoney(){
    return money;
}

int Player::getKryptonite(){
    return kryptonite;
}

int Player::getVelocitySerum(){
    return velocitySerum;
}

int Player::getCementBags(){
    return cementBags;
}

int Player::getLassoOfTruth(){
    return lassoOfTruth;
}

void Player::setMoney(int m){
    money = m;
}

void Player::setKryptonite(int k){
    kryptonite = k;
}

void Player::setVelocitySerum(int vS){
    velocitySerum = vS;
}

void Player::setCementBags(int cB){
    cementBags = cB;
}

void Player::setLassoOfTruth(int lOT){
    lassoOfTruth = lOT;
}

void Player::setArrestedClayface(bool aC){}
void Player::setArrestedReverseFlash(bool aRF){}
void Player::setArrestedLexLuthor(bool aLL){}

bool Player::getArrestedClayface(){
    return arrestedClayface;
}

bool Player::getArrestedReverseFlash(){
    return arrestedReverseFlash;
}

bool Player::getArrestedLexLuthor(){
    return arrestedLexLuthor;
}
