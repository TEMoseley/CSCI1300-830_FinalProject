#include <string>
#include <vector>
#include <iostream>
#include <fstream>

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
    moneyDonated = 0;
    kryptoniteDonated = 0;
    velocitySerumDonated = 0;
    cementBagsDonated = 0;
    moneyStillNeeded = 100;
    kryptoniteStillNeeded = 15;
    velocitySerumStillNeeded = 20;
    cementBagsStillNeeded = 10;
    completionPercent = 0;
    map = readMap("map.txt");
}

MenuResult Game::displayMap(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << endl << map << endl;
    cout << "You are in: " << p.getCurrentLocation().getName() << endl;
    while (true){
        if (promptInt("To return to main menu, press 1: ") == 1){
            break;
        }
    }
    return displayMainMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
}

int Game::getDay(){
    return day;
}

int Game::getCompletionPercent(){
    int completed = moneyDonated + kryptoniteDonated + velocitySerumDonated + cementBagsDonated;
    int needed = moneyDonated + kryptoniteDonated + velocitySerumDonated + cementBagsDonated;
    int total = needed + completed;
    if (total == 0){
        completionPercent = 0;
    }
    else {
        completionPercent = (completed / total) * 100;
    }
    return completionPercent;
}

MenuResult Game::displayGameStats(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "Money in thousands still needed: $" << moneyStillNeeded << endl;
    cout << "Kryptonite crystals still needed: " << kryptoniteStillNeeded << endl;
    cout << "Vials of Velocity Serum still needed: " << velocitySerumStillNeeded << endl;
    cout << "Bags of cement still needed: " << cementBagsStillNeeded << endl;
    cout << "Completion percent: " << g.getCompletionPercent() << "%" << endl;

    while (true){
        if (promptInt("To return to main menu, press 1: ") == 1){
            break;
        }
    }
    return displayMainMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
}

void Game::displayWinStats(Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "The headquarters has all the necessary resources!" << endl;
    cout << "Risk and relationship endings are a work in progress." << endl;
    cout << "Thanks for playing!" << endl;
     
}

MenuResult displayMainMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "Press 1 to view time, day, and completion." << endl;
    cout << "Press 2 to view inventory." << endl;
    cout << "Press 3 to travel." << endl;
    cout << "Press 4 to display map." << endl;
    cout << "Press 5 to view location description." << endl;
    cout << "Press 6 to return to game." << endl;
    cout << "Press 7 to quit." << endl;

    switch (promptInt("Select option: ")) {
        case 1:
            return g.displayGameStats(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 2:
            return p.displayCurrentInventory(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 3:
            cout << "Work In Progress." << endl;
            return displayMainMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 4:
            return g.displayMap(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 5: 
            cout << p.getCurrentLocation().getDescription() << endl;
            while (true){
                if (promptInt("To return to main menu, press 1: ") == 1){
                    break;
                }
            }
            return displayMainMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 6:
            return displayLocationMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
        case 7:
            if (promptInt("Are you sure? Press 1 for yes, anything else for no: ") == 1){
                return END;
            }
            else {
                return displayMainMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
            }
        default:
            cout << "Unrecognized value." << endl;
            return displayMainMenu(g, p, h0, h1, h2, h3, v0, v1, v2);
    }

    return CONTINUE;
}

int promptInt(string prompt){
    int userInput;
    cout << prompt;
    cin >> userInput;
    return userInput;
}

