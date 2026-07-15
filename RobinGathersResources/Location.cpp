#include <string>
#include <vector>
#include <iostream>

#include "Game.h"
#include "Location.h"
#include "Player.h"
#include "Hero.h"
#include "Villain.h"

using namespace std;

MenuResult displayGothamMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){

    cout << "Press 1 to view main menu." << endl;
    cout << "Press 2 to talk to Batman." << endl;
    cout << "Press 3 to talk to Clayface." << endl;

    switch (promptInt("Select option: ")) {
        case 1:
            return displayMainMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 2:
            return displayBatmanMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 3:
            return displayClayfaceMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        default:
            cout << "Unrecognized value." << endl;
            return displayGothamMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
    }

    return CONTINUE;
}

MenuResult displayCentralCityMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){

    cout << "Press 1 to view main menu." << endl;
    cout << "Press 2 to talk to The Flash." << endl;
    cout << "Press 3 to talk to Reverse Flash." << endl;

    switch (promptInt("Select option: ")) {
        case 1:
            return displayMainMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 2:
            return displayFlashMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 3:
            return displayReverseFlashMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        default:
            cout << "Unrecognized value." << endl;
            return displayCentralCityMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
    }

    return CONTINUE;
}

MenuResult displayMetropolisMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){

    cout << "Press 1 to view main menu." << endl;
    cout << "Press 2 to talk to Superman." << endl;
    cout << "Press 3 to talk to Lex Luthor." << endl;

    switch (promptInt("Select option: ")) {
        case 1:
            return displayMainMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 2:
            return displaySupermanMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 3:
            return displayLexLuthorMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        default:
            cout << "Unrecognized value." << endl;
            return displayMetropolisMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
    }

    return CONTINUE;
}

MenuResult displayThemiscyraMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){

    cout << "Press 1 to view main menu." << endl;
    cout << "Press 2 to talk to Wonder Woman." << endl;

    switch (promptInt("Select option: ")) {
        case 1:
            return displayMainMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 2:
            return displayWonderWomanMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        default:
            cout << "Unrecognized value." << endl;
            return displayThemiscyraMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
    }

    return CONTINUE;
}

Location::Location(string n, int lN, string d){
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

MenuResult displayLocationMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    
    switch (p.getCurrentLocation().getLocationNumber()) {
        case 0:
            return displayGothamMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 1:
            return displayCentralCityMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 2:
            return displayMetropolisMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 3: 
            return displayThemiscyraMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
    }

    return CONTINUE;
}

