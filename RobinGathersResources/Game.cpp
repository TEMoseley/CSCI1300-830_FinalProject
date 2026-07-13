#include <string>
#include <vector>
#include <iostream>

#include "Game.h"
#include "Location.h"
#include "Player.h"

using namespace std;

Game::Game(int d){
    day = d;
    time = 1;
    completionPercent = 0.0;
    map = "";
}

void Game::displayMap(){
    cout << endl << map << endl;
}

double Game::getCompletionPercent(){
    return 0.0;
}

void Game::setCompletionPercent(double cP){
    completionPercent = cP;
}

MenuResult displayMainMenu(Player p){
    cout << "Press 1 to view statistics." << endl;
    cout << "Press 2 to travel." << endl;
    cout << "Press 3 to display map." << endl;
    cout << "Press 4 to view location description." << endl;
    cout << "Press 5 to return to game." << endl;
    cout << "Press 6 to quit." << endl;

    switch (promptInt("Select option: ")) {
        case 1:
            cout << "Work In Progress." << endl;
            return displayMainMenu(p);
        case 2:
            cout << "Work In Progress." << endl;
            return displayMainMenu(p);
        case 3:
            cout << "Work In Progress." << endl;
            return displayMainMenu(p);
        case 4: 
            cout << p.getCurrentLocation().getDescription() << endl;
            while (true){
                if (promptInt("When ready to return, press 1: ") == 1){
                    break;
                }
            }
            return displayMainMenu(p);
        case 5:
            return Location::printLocationMenu(p.getCurrentLocation());
        case 6:
            if (promptInt("Are you sure? Press 1 for yes, anything else for no: ") == 1){
                return END;
            }
            else {
                return displayMainMenu(p);
            }
        default:
            cout << "Unrecognized value." << endl;
            return displayMainMenu(p);
    }

    return CONTINUE;
}

string promptString(string prompt){
    string userInput;
    cout << prompt;
    cin >> userInput;
    return userInput;
}

int promptInt(string prompt){
    int userInput;
    cout << prompt;
    cin >> userInput;
    return userInput;
}

