#ifndef HERO_H
#define HERO_H

#include <string>
#include <vector>
#include <iostream>

#include "Game.h"
#include "Character.h"
struct ReturnStruct;

class Hero : public Character {
private:
    int heroNumber;
    int relationshipLevel;
public:
    Hero(std::string n, int hN);
    void setRelationshipLevel(int rL);
    int getRelationshipLevel();
};

ReturnStruct displayBatmanMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
ReturnStruct displayFlashMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
ReturnStruct displaySupermanMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
ReturnStruct displayWonderWomanMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);

#endif