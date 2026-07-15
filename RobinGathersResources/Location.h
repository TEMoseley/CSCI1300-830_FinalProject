#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include <iostream>

#include "Game.h"
class Player;


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

MenuResult displayLocationMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
MenuResult displayGothamMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
MenuResult displayCentralCityMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
MenuResult displayMetropolisMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
MenuResult displayThemiscyraMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);

#endif