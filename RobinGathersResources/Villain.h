#ifndef VILLAIN_H
#define VILLAIN_H

#include <string>
#include <vector>
#include <iostream>

#include "Game.h"
#include "Character.h"

class Villain : public Character {
private:
    int villainNumber;
    int riskLevel;

public:
    Villain(std::string n, int vN);
};

MenuResult displayClayfaceMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
MenuResult displayReverseFlashMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);
MenuResult displayLexLuthorMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2);

#endif