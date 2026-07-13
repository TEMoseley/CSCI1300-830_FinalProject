#include <string>
#include <vector>
#include <iostream>

#include "Location.h"
#include "Player.h"

using namespace std;



int main(){
    Game game(1);
    Location gotham("Gotham", 0, "Gotham, home of the Batman.");
    Location centralCity("Central City", 1, "Central City, home of The Flash.");
    Location metropolis("Metropolis", 2, "Metropolis, home of Superman.");
    Location Themiscyra("Themiscyra", 3, "Themiscyra, home of Wonder Woman");
    Player player(gotham);

    while (true){
        if(displayMainMenu(player) == END){
            break;
        }
    }
    
    

    

    return 0;
}