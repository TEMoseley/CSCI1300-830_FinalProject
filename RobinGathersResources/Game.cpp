#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "ReturnStruct.h"
#include "Game.h"
#include "Location.h"
#include "Player.h"
#include "Hero.h"
#include "Villain.h"

using namespace std;



string readMap(string filename){
    ifstream inFile(filename);
    string map;
    string line;

    bool firstLine = true;
    while (getline(inFile, line)){
        if (!firstLine){
            map += "\n";
        }
        map += line;
        firstLine = false;
    }

    inFile.close();
    return map;
}

Game::Game(int d){
    day = d;
    time = 1;
    moneyDeposited = 0;
    kryptoniteDeposited = 0;
    velocitySerumDeposited = 0;
    cementBagsDeposited = 0;
    moneyStillNeeded = 60;
    kryptoniteStillNeeded = 15;
    velocitySerumStillNeeded = 20;
    cementBagsStillNeeded = 300;
    completionPercent = 0;
    map = readMap("map.txt");
}

ReturnStruct Game::displayMap(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << endl << map << endl;
    cout << "You are in: " << p.getCurrentLocation().getName() << endl;
    while (true){
        if (promptInt("To return to main menu, press 1: ") == 1){
            break;
        }
    }
    return displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
}

int Game::getTime(){
    return time;
}

int Game::getDay(){
    return day;
}

void Game::setTime(int t){
    time = t;
}

void Game::setDay(int d){
    day = d;
}


void Game::setMoneyDeposited(int mD){
    moneyDeposited = mD;
}

void Game::setKryptoniteDeposited(int kD){
    kryptoniteDeposited = kD;
}

void Game::setVelocitySerumDeposited(int vSD){
    velocitySerumDeposited = vSD;
}

void Game::setCementBagsDeposited(int cBD){
    cementBagsDeposited = cBD;
}

void Game::setMoneyStillNeeded(int mSN){
    if (mSN < 0){
        moneyStillNeeded = 0;
    }
    else{
        moneyStillNeeded = mSN;
    }
}

void Game::setKryptoniteStillNeeded(int kSN){
    if (kSN < 0){
        kryptoniteStillNeeded = 0;
    }
    else{
        kryptoniteStillNeeded = kSN;
    }
}

void Game::setVelocitySerumStillNeeded(int vSSN){
    if (vSSN < 0){
        velocitySerumStillNeeded = 0;
    }
    else{
        velocitySerumStillNeeded = vSSN;
    }
}

void Game::setCementBagsStillNeeded(int cBSN){
    if (cBSN < 0){
        cementBagsStillNeeded = 0;
    }
    else{
        cementBagsStillNeeded = cBSN;
    }
}


int Game::getMoneyDeposited(){
    return moneyDeposited;
}

int Game::getKryptoniteDeposited(){
    return kryptoniteDeposited;
}

int Game::getVelocitySerumDeposited(){
    return velocitySerumDeposited;
}

int Game::getCementBagsDeposited(){
    return cementBagsDeposited;
}

int Game::getMoneyStillNeeded(){
    return moneyStillNeeded;
}

int Game::getKryptoniteStillNeeded(){
    return kryptoniteStillNeeded;
}

int Game::getVelocitySerumStillNeeded(){
    return velocitySerumStillNeeded;
}

int Game::getCementBagsStillNeeded(){
    return cementBagsStillNeeded;
}


int Game::getCompletionPercent(){
    int completed = moneyDeposited + kryptoniteDeposited + velocitySerumDeposited + cementBagsDeposited;
    int needed = moneyStillNeeded + kryptoniteStillNeeded + velocitySerumStillNeeded + cementBagsStillNeeded;
    int total = needed + completed;
    if (total == 0){
        completionPercent = 0;
    }
    else {
        completionPercent = (completed * 100) / total;
    }
    return completionPercent;
}

ReturnStruct Game::displayGameStats(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "Money still needed: $" << moneyStillNeeded << "k" << endl;
    cout << "Kryptonite crystals still needed: " << kryptoniteStillNeeded << endl;
    cout << "Vials of velocity serum still needed: " << velocitySerumStillNeeded << endl;
    cout << "Bags of cement still needed: " << cementBagsStillNeeded << endl;
    cout << "Completion percent: " << g.getCompletionPercent() << "%" << endl;

    while (true){
        if (promptInt("To return to main menu, press 1: ") == 1){
            break;
        }
    }
    return displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
}

void Game::displayWinStats(Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "The headquarters has all the necessary resources!" << endl;
    cout << "It took you " << day << " days." << endl;
    
    if (h0.getRelationshipLevel() >= 1){
        cout << "Batman is proud of you for arresting Clayface." << endl;
    }
    else{
        cout << "Batman thinks you did an acceptable job." << endl;
    }

    if (h1.getRelationshipLevel() >= 1){
        cout << "The Flash is amazed that you arrested Reverse Flash." << endl;
    }
    else{
        cout << "The Flash wants to hang out sometime." << endl;
    }

    if (h2.getRelationshipLevel() >= 1){
        cout << "Superman is grateful for your arrest of Lex Luthor." << endl;
    }
    else{
        cout << "Superman thinks you're a darling kid." << endl;
    }

    if (h3.getRelationshipLevel() >= 1){
        cout << "Wonder Woman invested $20k in Crypto the Super Dogecoin." << endl;
    }
    else{
        cout << "Wonder Woman is strapped for cash." << endl;
    }

    cout << "You collaborated with villains " << totalRisk(v0, v1, v2) << " times!" << endl;

    if (totalRisk(v0, v1, v2) <= 0){
        cout << "What a good egg!" << endl;
    }
    else if (totalRisk(v0, v1, v2) <= 5){
        cout << "The supervillains are still a bit short on cash." << endl;
    }
    else if (totalRisk(v0, v1, v2) <= 10){
        cout << "Oh my, the Legion of Doom is rolling in the dough." << endl;
    }
    else if (totalRisk(v0, v1, v2) <= 15){
        cout << "At this point you're basically a supervillain yourself." << endl;
    }
    else{
        cout << "The Justice League has fallen, thanks to your treachery." << endl;
    }

    cout << "Thanks for playing!" << endl; 
}

ReturnStruct displayMainMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    
    cout << "Press 1 to view time, day, and completion." << endl;
    cout << "Press 2 to view inventory." << endl;
    cout << "Press 3 to travel." << endl;
    cout << "Press 4 to display map." << endl;
    cout << "Press 5 to view location description." << endl;
    cout << "Press 6 to return to game." << endl;
    cout << "Press 7 to quit." << endl;

    switch (promptInt("Select option: ")) {
        case 1:
            return g.displayGameStats(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        case 2:
            return p.displayCurrentInventory(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        case 3:
            return displayTravelMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        case 4:
            return g.displayMap(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        case 5:{
            cout << p.getCurrentLocation().getDescription() << endl;
            while (true){
                if (promptInt("To return to main menu, press 1: ") == 1){
                    break;
                }
            }
            ReturnStruct result = displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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
        case 6:{
            return displayLocationMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        }
        case 7:{
            if (promptInt("Are you sure? Press 1 for yes, anything else for no: ") == 1){
                ReturnStruct returnStruct{END, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return returnStruct;
            }
            else {
                ReturnStruct result = displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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
        default:{
            cout << "Unrecognized value." << endl;
            ReturnStruct result = displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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

int promptInt(string prompt){
    string userString;
    int userInt;
    
    bool isValid = true;
    bool firstRun = true;

    while (!isValid || firstRun){
        cout << prompt;
        cin >> userString;
        isValid = true;

        for (int i = 0; i < static_cast<int>(userString.length()); i++) {
            char c = userString[i];

            // Check if digit
            if ((c < '0' || c > '9') && c != 10 && c != 13 && c != 23) {
                isValid = false;
                break;
            }
        }

        // Reject empty input
        if (static_cast<int>(userString.length()) == 0){
            isValid = false;
        }

        if (!isValid){
            cout << "That is not a valid integer." << endl;
        }

        firstRun = false;
    }

    userInt = stoi(userString);
    
    return userInt;
}

ReturnStruct displayTravelMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    if (p.getCurrentLocation().getLocationNumber() == 0){
        cout << "Press 1 to travel to Central City, costs 1 hour." << endl;
        cout << "Press 2 to return to main menu." << endl;

        switch (promptInt("Select option: ")) {
            case 1:
                p.setCurrentLocation(l1);
                g.setTime(g.getTime() + 1);
                if (g.getTime() > 8){
                    ReturnStruct returnStruct{NEW_DAY, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    return displayLocationMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                }
            case 2: 
                return displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            default:
                cout << "Unrecognized value." << endl;
                ReturnStruct result = displayTravelMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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

    if (p.getCurrentLocation().getLocationNumber() == 1){
        cout << "Press 1 to travel to Gotham, costs 1 hour." << endl;
        cout << "Press 2 to travel to Themiscyra, costs 1 hour." << endl;
        cout << "Press 3 to return to main menu." << endl;

        switch (promptInt("Select option: ")) {
            case 1:
                p.setCurrentLocation(l0);
                g.setTime(g.getTime() + 1);
                if (g.getTime() > 8){
                    ReturnStruct returnStruct{NEW_DAY, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    return displayLocationMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                }
            case 2:
                p.setCurrentLocation(l3);
                g.setTime(g.getTime() + 1);
                if (g.getTime() > 8){
                    ReturnStruct returnStruct{NEW_DAY, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    return displayLocationMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                }
            case 3: 
                return displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            default:
                cout << "Unrecognized value." << endl;
                ReturnStruct result = displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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

    if (p.getCurrentLocation().getLocationNumber() == 3){
        cout << "Press 1 to travel to Central City, costs 1 hour." << endl;
        cout << "Press 2 to travel to Metropolis, costs 1 hour." << endl;
        cout << "Press 3 to return to main menu." << endl;

        switch (promptInt("Select option: ")) {
            case 1:
                p.setCurrentLocation(l1);
                g.setTime(g.getTime() + 1);
                if (g.getTime() > 8){
                    ReturnStruct returnStruct{NEW_DAY, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    return displayLocationMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                }
            case 2:
                p.setCurrentLocation(l2);
                g.setTime(g.getTime() + 1);
                if (g.getTime() > 8){
                    ReturnStruct returnStruct{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    return displayLocationMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                }
            case 3: 
                return displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            default:
                cout << "Unrecognized value." << endl;
                ReturnStruct result = displayTravelMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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

    if (p.getCurrentLocation().getLocationNumber() == 2){
        cout << "Press 1 to travel to Themiscyra, costs 1 hour." << endl;
        cout << "Press 2 to return to main menu." << endl;

        switch (promptInt("Select option: ")) {
            case 1:
                p.setCurrentLocation(l3);
                g.setTime(g.getTime() + 1);
                if (g.getTime() > 8){
                    ReturnStruct returnStruct{NEW_DAY, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    return displayLocationMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                }
            case 2: 
                return displayMainMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            default:
                cout << "Unrecognized value." << endl;
                ReturnStruct result = displayTravelMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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
                return finalResult;;
        }
    }

    ReturnStruct returnStruct{CONTINUE, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
    return returnStruct;
}

