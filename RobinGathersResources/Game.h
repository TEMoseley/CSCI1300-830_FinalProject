#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

struct ReturnStruct;
class Location;
class Player;
class Hero;
class Villain;


enum MenuResult { CONTINUE, NEW_DAY, END, WIN };

class Game{
private:
    int time;
    int day;
    int moneyDeposited;
    int kryptoniteDeposited;
    int velocitySerumDeposited;
    int cementBagsDeposited;
    int moneyStillNeeded;
    int kryptoniteStillNeeded;
    int velocitySerumStillNeeded;
    int cementBagsStillNeeded;
    int completionPercent;
    std::string map;

public:
    Game(int d);
    ReturnStruct displayMap(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
    ReturnStruct displayGameStats(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
    void displayWinStats(Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
    int getTime();
    int getDay();
    void setTime(int t);
    void setDay(int d);
    void setMoneyDeposited(int mD);
    void setKryptoniteDeposited(int kD);
    void setVelocitySerumDeposited(int vSD);
    void setCementBagsDeposited(int cBD);
    void setMoneyStillNeeded(int mSN);
    void setKryptoniteStillNeeded(int kSN);
    void setVelocitySerumStillNeeded(int vSSN);
    void setCementBagsStillNeeded(int cBSN);
    int getMoneyDeposited();
    int getKryptoniteDeposited();
    int getVelocitySerumDeposited();
    int getCementBagsDeposited();
    int getMoneyStillNeeded();
    int getKryptoniteStillNeeded();
    int getVelocitySerumStillNeeded();
    int getCementBagsStillNeeded();
    int getCompletionPercent();
};

ReturnStruct displayMainMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
int promptInt(std::string prompt);
std::string readMap(std::string filename);
ReturnStruct displayTravelMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);

#endif