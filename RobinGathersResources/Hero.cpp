#include <string>
#include <vector>
#include <iostream>

#include "ReturnStruct.h"
#include "Game.h"
#include "Player.h"
#include "Character.h"
#include "Hero.h"
#include "Villain.h"

using namespace std;

Hero::Hero(string n, int hN) : Character(n), heroNumber(hN){
    relationshipLevel = 0;
}

void Hero::setRelationshipLevel(int rL){
    relationshipLevel = rL;
}

int Hero::getRelationshipLevel(){
    return relationshipLevel;
}

ReturnStruct displayBatmanMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "\"Robin, what do you want?\"" << endl;
    cout << "Press 1 to get 20 cement, costs 1 hour and 1 kryptonite." << endl;
    cout << "Press 2 to stop talking to Batman." << endl; 

    switch (promptInt("Select option: ")) {
        case 1:
            if (p.getKryptonite() >= 1){
                p.setKryptonite(p.getKryptonite() - 1);
                p.setCementBags(p.getCementBags() + 20);
                g.setTime(g.getTime() + 1);
                if (g.getTime() > 8){
                    ReturnStruct returnStruct{NEW_DAY, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    ReturnStruct result = displayBatmanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                    mR = result.mR;
                    g = result.g;
                    p = result.p;
                    l0 = result.l0;
                    l1 = result.l1;
                    l2 = result.l2;
                    l3 = result.l3;
                    h0 = result.h0;
                    h1 = result.h1;
                    h2 = result.h2;
                    h3 = result.h3;
                    v0 = result.v0;
                    v1 = result.v1;
                    v2 = result.v2;
                    ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return finalResult;
                }
            }
            else{
                cout << "Not enough kryptonite." << endl;
                ReturnStruct result = displayBatmanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
            }
        case 2:
            return displayGothamMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        default:
            cout << "Unrecognized value." << endl;
            ReturnStruct result = displayBatmanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
    }

    ReturnStruct returnStruct{CONTINUE, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
    return returnStruct;
}

ReturnStruct displayFlashMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "\"Hey Robin, what's up?\"" << endl;
    cout << "Press 1 to get 4 velocity serum, costs 1 hour and $12k." << endl;
    cout << "Press 2 to stop talking to The Flash." << endl;

    switch (promptInt("Select option: ")) {
        case 1:
            if (p.getMoney() >= 12){
                p.setMoney(p.getMoney() - 12);
                p.setVelocitySerum(p.getVelocitySerum() + 4);
                g.setTime(g.getTime() + 1);
                if (g.getTime() > 8){
                    ReturnStruct returnStruct{NEW_DAY, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    ReturnStruct result = displayFlashMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
                }
            }
            else{
                cout << "Not enough money." << endl;
                ReturnStruct result = displayFlashMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
            }
        case 2:
            return displayCentralCityMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        default:
            cout << "Unrecognized value." << endl;
            ReturnStruct result = displayFlashMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
    }

    ReturnStruct returnStruct{CONTINUE, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
    return returnStruct;
}

ReturnStruct displaySupermanMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "\"Hi Robin! To what do I owe the pleasure, bud?\"" << endl;
    cout << "Press 1 to get 3 kryptonite, costs 1 hour and 4 Velocity Serum." << endl;
    cout << "Press 2 to deposit $10k." << endl;
    cout << "Press 3 to deposit 1 kryptonite." << endl;
    cout << "Press 4 to deposit 3 velocity serum." << endl;
    cout << "Press 5 to deposit 50 cement." << endl;
    cout << "Press 6 to stop talking to Superman." << endl;
    

    switch (promptInt("Select option: ")) {
        case 1:
            if (p.getVelocitySerum() >= 4){
                p.setVelocitySerum(p.getVelocitySerum() - 4);
                p.setKryptonite(p.getKryptonite() + 3);
                g.setTime(g.getTime() + 1);
                if (g.getTime() > 8){
                    ReturnStruct returnStruct{NEW_DAY, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    ReturnStruct result = displaySupermanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
                }
            }
            else{
                cout << "Not enough cement bags." << endl;
                ReturnStruct result = displaySupermanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
            }
        case 2:
            if (p.getMoney() >= 10){
                p.setMoney(p.getMoney() - 10);
                g.setMoneyDeposited(g.getMoneyDeposited() + 10);
                g.setMoneyStillNeeded(g.getMoneyStillNeeded() - 10);
                if (g.getCompletionPercent() == 100){
                    ReturnStruct returnStruct{WIN, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    ReturnStruct result = displaySupermanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
                }
            }
            else{
                cout << "Not enough money." << endl;
                ReturnStruct result = displaySupermanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
            }
        case 3:
            if (p.getKryptonite() >= 1){
                p.setKryptonite(p.getKryptonite() - 1);
                g.setKryptoniteDeposited(g.getKryptoniteDeposited() + 1);
                g.setKryptoniteStillNeeded(g.getKryptoniteStillNeeded() - 1);
                if (g.getCompletionPercent() == 100){
                    ReturnStruct returnStruct{WIN, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    ReturnStruct result = displaySupermanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
                }
            }
            else{
                cout << "Not enough kryptonite." << endl;
                ReturnStruct result = displaySupermanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
            }
        case 4:
            if (p.getVelocitySerum() >= 3){
                p.setVelocitySerum(p.getVelocitySerum() - 3);
                g.setVelocitySerumDeposited(g.getVelocitySerumDeposited() + 3);
                g.setVelocitySerumStillNeeded(g.getVelocitySerumStillNeeded() - 3);
                if (g.getCompletionPercent() == 100){
                    ReturnStruct returnStruct{WIN, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                   ReturnStruct result = displaySupermanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
                }
            }
            else{
                cout << "Not enough money." << endl;
                ReturnStruct result = displaySupermanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
            }
        case 5:
            if (p.getCementBags() >= 50){
                p.setCementBags(p.getCementBags() - 50);
                g.setCementBagsDeposited(g.getCementBagsDeposited() + 50);
                g.setCementBagsStillNeeded(g.getCementBagsStillNeeded() - 50);
                if (g.getCompletionPercent() == 100){
                    ReturnStruct returnStruct{WIN, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    ReturnStruct result = displaySupermanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
                }
            }
            else{
                cout << "Not enough money." << endl;
                ReturnStruct result = displaySupermanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
            }
        case 6:
            return displayMetropolisMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        default:
            cout << "Unrecognized value." << endl;
            ReturnStruct result = displaySupermanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
    }
    
    ReturnStruct returnStruct{CONTINUE, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
    return returnStruct;
}

ReturnStruct displayWonderWomanMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "\"Hello Robin, what a pleasant surprise.\"" << endl;
    if(p.getLassoOfTruth() == 0){
        cout << "Press 1 to get the Lasso of Truth (optional), costs 1 hour and $20k." << endl;
        cout << "Press 2 to stop talking to Wonder Woman." << endl;

        switch (promptInt("Select option: ")) {
            case 1:
                if (p.getMoney() >= 20){
                    p.setMoney(p.getMoney() - 20);
                    p.setLassoOfTruth(p.getLassoOfTruth() + 1);
                    h3.setRelationshipLevel(h3.getRelationshipLevel() + 1);
                    g.setTime(g.getTime() + 1);
                    if (g.getTime() > 8){
                        ReturnStruct returnStruct{NEW_DAY, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                        return returnStruct;
                    }
                    else{
                        ReturnStruct result = displayWonderWomanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                        mR = result.mR;
                        g = result.g;
                        p = result.p;
                        l0 = result.l0;
                        l1 = result.l1;
                        l2 = result.l2;
                        l3 = result.l3;
                        h0 = result.h0;
                        h1 = result.h1;
                        h2 = result.h2;
                        h3 = result.h3;
                        v0 = result.v0;
                        v1 = result.v1;
                        v2 = result.v2;
                        ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                        return finalResult;
                    }
                }
                else{
                    cout << "Not enough money." << endl;
                    ReturnStruct result = displayWonderWomanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                    mR = result.mR;
                    g = result.g;
                    p = result.p;
                    l0 = result.l0;
                    l1 = result.l1;
                    l2 = result.l2;
                    l3 = result.l3;
                    h0 = result.h0;
                    h1 = result.h1;
                    h2 = result.h2;
                    h3 = result.h3;
                    v0 = result.v0;
                    v1 = result.v1;
                    v2 = result.v2;
                    ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return finalResult;
                }
            case 2:
                return displayThemiscyraMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            default:
                cout << "Unrecognized value." << endl;
                ReturnStruct result = displayWonderWomanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
        }
    }
    else{
        cout << "You already bought the Lasso of Truth." << endl;
        cout << "Press 1 to stop talking to Wonder Woman." << endl;

        switch (promptInt("Select option: ")) {
            case 1:
                return displayThemiscyraMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            default:
                cout << "Unrecognized value." << endl;
                ReturnStruct result = displayWonderWomanMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                mR = result.mR;
                g = result.g;
                p = result.p;
                l0 = result.l0;
                l1 = result.l1;
                l2 = result.l2;
                l3 = result.l3;
                h0 = result.h0;
                h1 = result.h1;
                h2 = result.h2;
                h3 = result.h3;
                v0 = result.v0;
                v1 = result.v1;
                v2 = result.v2;
                ReturnStruct finalResult{mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                return finalResult;
        }
    }
    
    ReturnStruct returnStruct{CONTINUE, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
    return returnStruct;
}