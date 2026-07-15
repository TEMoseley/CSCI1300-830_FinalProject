#include <string>
#include <vector>
#include <iostream>

#include "Game.h"
#include "Player.h"
#include "Character.h"
#include "Hero.h"

using namespace std;

Hero::Hero(string n, int hN) : Character(n), heroNumber(hN){
    relationshipLevel = 0;
}

MenuResult displayBatmanMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "\"Robin, what do you want?\"" << endl;
    return CONTINUE;
}

MenuResult displayFlashMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "\"Hey Robin, what's up?\"" << endl;
    return CONTINUE;
}

MenuResult displaySupermanMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "\"Hi Robin! To what do I owe the pleasure, bud?\"" << endl;
    return CONTINUE;
}

MenuResult displayWonderWomanMenu(Game g, Player p, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "\"Hello Robin, what a pleasant surprise.\"" << endl;
    return CONTINUE;
}