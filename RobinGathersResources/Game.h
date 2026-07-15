#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Player;
class Hero;
class Villain;

enum MenuResult : int { CONTINUE, NEW_DAY, END, WIN };

class Game
{
private:
    int time;
    int day;
    int moneyDonated;
    int kryptoniteDonated;
    int velocitySerumDonated;
    int cementBagsDonated;
    int moneyStillNeeded;
    int kryptoniteStillNeeded;
    int velocitySerumStillNeeded;
    int cementBagsStillNeeded;
    int completionPercent;
    std::string map;

public:
    Game(int d);
    MenuResult displayMap(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
    MenuResult displayGameStats(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
    void displayWinStats(Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
    int getDay();
    int getCompletionPercent();
};

MenuResult displayMainMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
int promptInt(std::string prompt);
std::string readMap(std::string filename);

#endif