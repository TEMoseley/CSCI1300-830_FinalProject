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

Villain::Villain(string n, int vN) : Character(n), villainNumber(vN){
    riskLevel = 0;
}

void Villain::setRiskLevel(int rL){
    riskLevel = rL;
}

int Villain::getRiskLevel(){
    return riskLevel;
}

ReturnStruct displayClayfaceMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "\"Robin, what do you want? I'm Batman, durrr!\"" << endl;
    cout << "Press 1 to get $12k, costs 1 hour and 30 cement, raises ending badness." << endl;
    cout << "Press 2 to use Lasso of Truth, get $6k and 15 cement, one time use." << endl;
    cout << "Press 3 to stop talking to Clayface." << endl;

    switch (promptInt("Select option: ")) {
        case 1:
            if (p.getCementBags() >= 30){
                p.setCementBags(p.getCementBags() - 30);
                p.setMoney(p.getMoney() + 12);
                g.setTime(g.getTime() + 1);
                v0.setRiskLevel(v0.getRiskLevel() + 1);
                if (g.getTime() > 8){
                    ReturnStruct returnStruct{NEW_DAY, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    ReturnStruct result = displayClayfaceMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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
                ReturnStruct result = displayClayfaceMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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
            if (p.getLassoOfTruth() >= 1){
                p.setCementBags(p.getCementBags() + 15);
                p.setMoney(p.getMoney() + 6);
                p.setArrestedClayface(true);
                h0.setRelationshipLevel(h0.getRelationshipLevel() + 1);
                return displayGothamMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            }
            else{
                cout << "Need Lasso of Truth." << endl;
                ReturnStruct result = displayClayfaceMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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
            return displayGothamMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        default:
            cout << "Unrecognized value." << endl;
            ReturnStruct result = displayClayfaceMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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

ReturnStruct displayReverseFlashMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "\"The Flash thinks speed is a gift. We both know it's a weapon.\"" << endl;
    cout << "Press 1 to get $20k, costs 1 hour and 5 Velocity Serum, raises ending badness." << endl;
    cout << "Press 2 to use Lasso of Truth, get $10k and 2 Velocity Serum, one time use." << endl;
    cout << "Press 3 to stop talking to Reverse Flash." << endl;

    switch (promptInt("Select option: ")) {
        case 1:
            if (p.getVelocitySerum() >= 5){
                p.setVelocitySerum(p.getVelocitySerum() - 5);
                p.setMoney(p.getMoney() + 20);
                g.setTime(g.getTime() + 1);
                v1.setRiskLevel(v1.getRiskLevel() + 1);
                if (g.getTime() > 8){
                    ReturnStruct returnStruct{NEW_DAY, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    ReturnStruct result = displayReverseFlashMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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
                cout << "Not enough Velocity Serum." << endl;
               ReturnStruct result = displayReverseFlashMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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
            if (p.getLassoOfTruth() >= 1){
                p.setVelocitySerum(p.getVelocitySerum() + 2);
                p.setMoney(p.getMoney() + 10);
                p.setArrestedReverseFlash(true);
                h1.setRelationshipLevel(h1.getRelationshipLevel() + 1);
                return displayCentralCityMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            }
            else{
                cout << "Need Lasso of Truth." << endl;
                ReturnStruct result = displayReverseFlashMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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
            return displayCentralCityMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        default:
            cout << "Unrecognized value." << endl;
            ReturnStruct result = displayReverseFlashMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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

ReturnStruct displayLexLuthorMenu(MenuResult mR, Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
    cout << "\"Well, well. A little bird in the big city.\"" << endl;
    cout << "Press 1 to get $24k, costs 1 hour and 4 kryptonite, raises ending badness." << endl;
    cout << "Press 2 to use Lasso of Truth, get $12k and 2 kryptonite, one time use." << endl;
    cout << "Press 3 to stop talking to Lex Luthor." << endl;

    switch (promptInt("Select option: ")) {
        case 1:
            if (p.getKryptonite() >= 4){
                p.setKryptonite(p.getKryptonite() - 4);
                p.setMoney(p.getMoney() + 24);
                g.setTime(g.getTime() + 1);
                v2.setRiskLevel(v2.getRiskLevel() + 1);
                if (g.getTime() > 8){
                    ReturnStruct returnStruct{NEW_DAY, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2};
                    return returnStruct;
                }
                else{
                    ReturnStruct result = displayLexLuthorMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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
                ReturnStruct result = displayLexLuthorMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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
            if (p.getLassoOfTruth() >= 1){
                p.setKryptonite(p.getKryptonite() + 2);
                p.setMoney(p.getMoney() + 12);
                p.setArrestedLexLuthor(true);
                h2.setRelationshipLevel(h2.getRelationshipLevel() + 1);
                return displayMetropolisMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            }
            else{
                cout << "Need Lasso of Truth." << endl;
                ReturnStruct result = displayLexLuthorMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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
            return displayMetropolisMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        default:
            cout << "Unrecognized value." << endl;
            ReturnStruct result = displayLexLuthorMenu(mR, g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
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

int totalRisk(Villain v0, Villain v1, Villain v2){
    int totalRisk = v0.getRiskLevel() + v1.getRiskLevel() + v2.getRiskLevel();
    return totalRisk;
}