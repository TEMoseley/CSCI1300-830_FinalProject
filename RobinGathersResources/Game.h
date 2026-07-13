#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <iostream>

class Player;

class Game
{
private:
    int time;
    int day;
    double completionPercent;
    std::string map;

public:
    Game(int d);
    void displayMap();
    double getCompletionPercent();
    void setCompletionPercent(double cP);

};

enum MenuResult : int { CONTINUE, NEW_DAY, WIN, END };
MenuResult displayMainMenu(Player p);
std::string promptString(std::string prompt);
int promptInt(std::string prompt);

#endif