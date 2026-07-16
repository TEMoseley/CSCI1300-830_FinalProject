#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include <iostream>

#include "Game.h"
class Player;
class Hero;
class Villain;
struct ReturnStruct;

class Location {
private:
    std::string name;
    int locationNumber;
    std::string description;


public:
    Location(std::string n, int lN, std::string d);
    std::string getName();
    int getLocationNumber();
    std::string getDescription();
};

ReturnStruct displayLocationMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
ReturnStruct displayGothamMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
ReturnStruct displayCentralCityMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
ReturnStruct displayMetropolisMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
ReturnStruct displayThemiscyraMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);

#endif