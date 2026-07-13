#include <string>
#include <vector>
#include <iostream>

#include "Game.h"
#include "Location.h"
class Player;

using namespace std;

/*
MenuResult printGothamMenu(){

    return CONTINUE;
}

MenuResult printCentralCityMenu(){

    return CONTINUE;
}

MenuResult printMetropolisMenu(){

    return CONTINUE;
}

MenuResult printThemiscyraMenu(){

    return CONTINUE;
}
*/

Location::Location(std::string n, int lN, std::string d){
    name = n;
    locationNumber = lN;
    description = d;
}

string Location::getName(){
    return name;
}

int Location::getLocationNumber(){
    return locationNumber;
}

string Location::getDescription(){
    return description;
}

MenuResult Location::printLocationMenu(Location cL){
    cout << "Work In Progress" << endl;
    return CONTINUE;
    
    //switch (cL.getLocationNumber()) {
        //case 0:
            //return printGothamMenu();
        //case 1:
            //return printCentralCityMenu();
        //case 2:
            //return printMetropolisMenu();
        //case 3: 
            //return printThemiscyraMenu();
    //}

    //return CONTINUE;
}

