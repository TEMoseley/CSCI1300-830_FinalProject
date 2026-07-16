#include <string>
#include <vector>
#include <iostream>

#include "ReturnStruct.h"
#include "Game.h"
#include "Location.h"
#include "Player.h"
#include "Hero.h"
#include "Villain.h"

using namespace std;

ReturnStruct displayGothamMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    
    if (p.getArrestedClayface() == false){
        cout << "Press 1 to view main menu." << endl;
        cout << "Press 2 to talk to Batman." << endl;
        cout << "Press 3 to talk to Clayface." << endl;

        switch (promptInt("Select option: ")) {
            case 1:
                return displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            case 2:
                return displayBatmanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            case 3:
                return displayClayfaceMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            default:
                cout << "Unrecognized value." << endl;
                ReturnStruct result = displayGothamMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
        }
    }
    else{
        cout << "Press 1 to view main menu." << endl;
        cout << "Press 2 to talk to Batman." << endl;

        switch (promptInt("Select option: ")) {
            case 1:
                return displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            case 2:
                return displayBatmanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            default:
                cout << "Unrecognized value." << endl;
                ReturnStruct result = displayGothamMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
        }
    }

    ReturnStruct returnStruct{CONTINUE, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
    return returnStruct;
}

ReturnStruct displayCentralCityMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){

    if (p.getArrestedReverseFlash() == false){
        cout << "Press 1 to view main menu." << endl;
        cout << "Press 2 to talk to The Flash." << endl;
        cout << "Press 3 to talk to Reverse Flash." << endl;

        switch (promptInt("Select option: ")) {
            case 1:
                return displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            case 2:
                return displayFlashMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            case 3:
                return displayReverseFlashMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            default:
                cout << "Unrecognized value." << endl;
                ReturnStruct result = displayCentralCityMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
        }
    }
    else{
        cout << "Press 1 to view main menu." << endl;
        cout << "Press 2 to talk to The Flash." << endl;

        switch (promptInt("Select option: ")) {
            case 1:
                return displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            case 2:
                return displayFlashMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            default:
                cout << "Unrecognized value." << endl;
                ReturnStruct result = displayCentralCityMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
        }
    }

    ReturnStruct returnStruct{CONTINUE, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
    return returnStruct;
}

ReturnStruct displayMetropolisMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){

    if (p.getArrestedLexLuthor() == false){
        cout << "Press 1 to view main menu." << endl;
        cout << "Press 2 to talk to Superman." << endl;
        cout << "Press 3 to talk to Lex Luthor." << endl;

        switch (promptInt("Select option: ")) {
            case 1:
                return displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            case 2:
                return displaySupermanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            case 3:
                return displayLexLuthorMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            default:
                cout << "Unrecognized value." << endl;
                ReturnStruct result = displayMetropolisMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
        }
    }
    else{
        cout << "Press 1 to view main menu." << endl;
        cout << "Press 2 to talk to Superman." << endl;

        switch (promptInt("Select option: ")) {
            case 1:
                return displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            case 2:
                return displaySupermanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            default:
                cout << "Unrecognized value." << endl;
                ReturnStruct result = displayMetropolisMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
        }
    }

    ReturnStruct returnStruct{CONTINUE, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
    return returnStruct;
}

ReturnStruct displayThemiscyraMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){

    cout << "Press 1 to view main menu." << endl;
    cout << "Press 2 to talk to Wonder Woman." << endl;

    switch (promptInt("Select option: ")) {
        case 1:
            return displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        case 2:
            return displayWonderWomanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        default:
            cout << "Unrecognized value." << endl;
            ReturnStruct result = displayThemiscyraMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
    }

    ReturnStruct returnStruct{CONTINUE, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
    return returnStruct;
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

ReturnStruct displayLocationMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    
    switch (p.getCurrentLocation().getLocationNumber()) {
        case 0:
            return displayGothamMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        case 1:
            return displayCentralCityMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        case 2:
            return displayMetropolisMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        case 3: 
            return displayThemiscyraMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
    }

    ReturnStruct returnStruct{CONTINUE, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
    return returnStruct;
}

