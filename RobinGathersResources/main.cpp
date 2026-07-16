#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "ReturnStruct.h"
#include "Location.h"
#include "Player.h"
#include "Hero.h"
#include "Villain.h"

using namespace std;

int main(){
    Game game(1);

    Location gotham("Gotham", 0, "Gotham, home of the Batman.");
    Location centralCity("Central City", 1, "Central City, home of The Flash. Here you can find Velocity Serum.");
    Location metropolis("Metropolis", 2, "Metropolis, home of Superman. Here you can find kryptonite.");
    Location themiscyra("Themiscyra", 3, "Themiscyra, home of Wonder Woman. Here you can find the Lasso of Truth.");

    Hero batman("Batman", 0);
    Hero flash("The Flash", 1);
    Hero superman("Superman", 2);
    Hero wonderWoman("Wonder Woman", 3);

    Villain clayface("Clayface", 0);
    Villain reverseFlash("Reverse Flash", 1);
    Villain lexLuthor("Lex Luthor", 2);

    Player player(gotham);

    cout << "Batman: \"Robin, I have a new mission for you." << endl;
    cout << "Over the next several days, I need you to collect" << endl;
    cout << "15 kryptonite crystals, 20 vials of Velocity" << endl;
    cout << "Serum, and 300 bags of cement. This will all be" << endl;
    cout << "used to construct a new Justice League headquarters" << endl;
    cout << "in outer space, in Earth's orbit. Talk to Superman" << endl;
    cout << "and he'll fly the deposited resources up. Also, I owe" << endl;
    cout << "Superman $60,000. I don't have time to deliver the" << endl;
    cout << "cash myself. I'll give you $30,000 a day to spend." << endl;
    cout << "You have 8 hours a day before you must come back to" << endl;
    cout << "Gotham to sleep. I'll also start you off with a few" << endl;
    cout << "bags of cement. Carrying them builds character.\"" << endl;


    while (true){
        if (promptInt("To start the game, press 1: ") == 1){
            break;
        }
    }

    while (true){
        if(displayMainMenu(CONTINUE, game, player, gotham, centralCity, metropolis, themiscyra, batman, flash, superman, wonderWoman, clayface, reverseFlash, lexLuthor).mR >= END){
            break;
        }
        else{
            if (game.getTime() >= 8){
                game.setTime(1);
                game.setDay(game.getDay() + 1);
                player.setCurrentLocation(gotham);
                player.setMoney(player.getMoney() + 30);
                cout << "It's a new day. You are now on day " << game.getDay() << endl;
                cout << "Batman gave you another $30k for today. Spend it wisely." << endl;
            }
        }
    }
    
    if (game.getCompletionPercent() == 100){
        game.displayWinStats(batman, flash, superman, wonderWoman, clayface, reverseFlash, lexLuthor);
        while (true){
            if (promptInt("To quit the game, press 1: ") == 1){
                break;
            }
        }
    }

    return 0;
}