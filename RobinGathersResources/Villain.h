#ifndef VILLAIN_H
#define VILLAIN_H

#include <string>
#include <vector>
#include <iostream>

#include "Character.h"
#include "Game.h"
#include "Hero.h"
#include "Item.h"
#include "Location.h"
#include "Player.h"
#include "Villain.h"

class Villain : public Character {
private:
    int riskLevel;
};

#endif