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

void Villain::setRiskLevel(int rL){
    riskLevel = rL;
}

int Villain::getRiskLevel(){
    return riskLevel;
}

MenuResult displayClayfaceMenu(Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
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
                    return NEW_DAY;
                }
                else{
                    return displayClayfaceMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                }
            }
            else{
                cout << "Not enough cement bags." << endl;
                return displayClayfaceMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            }
        case 2:
            if (p.getLassoOfTruth() >= 1){
                p.setCementBags(p.getCementBags() + 15);
                p.setMoney(p.getMoney() + 6);
                p.setArrestedClayface(true);
                h0.setRelationshipLevel(h0.getRelationshipLevel() + 1);
                return displayGothamMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            }
            else{
                cout << "Need Lasso of Truth." << endl;
                return displayClayfaceMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            }
        case 3:
            return displayGothamMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        default:
            cout << "Unrecognized value." << endl;
            return displayClayfaceMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
    }

    return CONTINUE;
}

MenuResult displayReverseFlashMenu(Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
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
                    return NEW_DAY;
                }
                else{
                    return displayReverseFlashMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                }
            }
            else{
                cout << "Not enough Velocity Serum." << endl;
                return displayReverseFlashMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            }
        case 2:
            if (p.getLassoOfTruth() >= 1){
                p.setVelocitySerum(p.getVelocitySerum() + 2);
                p.setMoney(p.getMoney() + 10);
                p.setArrestedReverseFlash(true);
                h1.setRelationshipLevel(h1.getRelationshipLevel() + 1);
                return displayCentralCityMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            }
            else{
                cout << "Need Lasso of Truth." << endl;
                return displayReverseFlashMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            }
        case 3:
            return displayCentralCityMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        default:
            cout << "Unrecognized value." << endl;
            return displayReverseFlashMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
    }

    return CONTINUE;
}

MenuResult displayLexLuthorMenu(Game g, Player p, Location l0, Location l1, Location l2, Location l3, Hero h0, Hero h1, Hero h2, Hero h3, Villain v0, Villain v1, Villain v2){
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
                    return NEW_DAY;
                }
                else{
                    return displayLexLuthorMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
                }
            }
            else{
                cout << "Not enough kryptonite." << endl;
                return displayLexLuthorMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            }
        case 2:
            if (p.getLassoOfTruth() >= 1){
                p.setKryptonite(p.getKryptonite() + 2);
                p.setMoney(p.getMoney() + 12);
                p.setArrestedLexLuthor(true);
                h2.setRelationshipLevel(h2.getRelationshipLevel() + 1);
                return displayMetropolisMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            }
            else{
                cout << "Need Lasso of Truth." << endl;
                return displayLexLuthorMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
            }
        case 3:
            return displayMetropolisMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
        default:
            cout << "Unrecognized value." << endl;
            return displayLexLuthorMenu(g, p, l0, l1, l2, l3, h0, h1, h2, h3, v0, v1, v2);
    }

    return CONTINUE;
}

int totalRisk(Villain v0, Villain v1, Villain v2){
    int totalRisk = v0.getRiskLevel() + v1.getRiskLevel() + v2.getRiskLevel();
    return totalRisk;
}