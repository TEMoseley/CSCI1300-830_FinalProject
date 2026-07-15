#include <string>
#include <vector>
#include <iostream>
#include <fstream>

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
    Location Themiscyra("Themiscyra", 3, "Themiscyra, home of Wonder Woman. Here you can find the Lasso of Truth.");

    Hero batman("Batman", 0);
    Hero flash("The Flash", 1);
    Hero superman("Superman", 2);
    Hero wonderWoman("Wonder Woman", 3);

    Villain clayface("Clayface", 0);
    Villain reverseFlash("Reverse Flash", 1);
    Villain lexLuthor("Lex Luthor", 2);

    Player player(gotham);

    // Start of game message

    while (true){
        if(displayMainMenu(game, player, batman, flash, superman, wonderWoman, clayface, reverseFlash, lexLuthor) >= END){
            break;
        }
        else{
            cout << "It's a new day. You are now on day " << game.getDay() << endl;
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