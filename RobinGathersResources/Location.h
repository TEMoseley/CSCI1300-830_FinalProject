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
    static MenuResult printLocationMenu(Location cL);
};

MenuResult printGothamMenu();

MenuResult printCentralCityMenu();

MenuResult printMetropolisMenu();

MenuResult printThemiscyraMenu();

#endif