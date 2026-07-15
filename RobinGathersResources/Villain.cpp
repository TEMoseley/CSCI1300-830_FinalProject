#include <string>
#include <vector>
#include <iostream>

#include "Game.h"
#include "Player.h"
#include "Character.h"
#include "Villain.h"

using namespace std;

Villain::Villain(string n, int vN) : Character(n), villainNumber(vN){
    riskLevel = 0;
}

MenuResult displayClayfaceMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    return CONTINUE;
}

MenuResult displayReverseFlashMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    return CONTINUE;
}

MenuResult displayLexLuthorMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    return CONTINUE;
}