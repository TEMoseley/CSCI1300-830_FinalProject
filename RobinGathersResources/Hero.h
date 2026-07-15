#ifndef HERO_H
#define HERO_H

#include <string>
#include <vector>
#include <iostream>

#include "Game.h"
#include "Character.h"

class Hero : public Character {
private:
    int heroNumber;
    int relationshipLevel;
public:
    Hero(std::string n, int hN);
};

MenuResult displayBatmanMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
MenuResult displayFlashMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
MenuResult displaySupermanMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
MenuResult displayWonderWomanMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);

#endif