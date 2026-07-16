# CSCI1300-830_FinalProject



\## Theme

Based around the Justice League from DC Comics, and the player plays as Robin. The "plot" is that Batman uses Robin to handle the gathering of some materials necessary for the construction of a new Justice League headquarters, which will be an orbiting space station (this is canonically a thing). 

\## Goal

Build a new Justice League orbiting headquarters.

\## How to compile and run

Requires MSYS2 with the ucrt64 toolchain installed (pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gdb), installed at the default path C:\msys64. If you have a different toolchain (e.g. mingw64) or a custom install path, update the paths in .vscode/tasks.json and .vscode/launch.json accordingly.

\## How to play

Just enter numbers to traverse the menus as directed.

\## Classes

Player - it stores the player's prefered pronouns, their money, their inventory, their skill levels, and any temporary stat modifiers.

Game - player's current location, the hour, the day, the character list, the location list, the main menu, and pretty much anything else related to the game itself.

Item - it stores item name, item value, and stat modification if consumed.

Character - it stores character name, their location, relationship level, and the resource and/or item they provide.

Hero - derived class of Character

Villain - derived class of Character

Location - name, unlocked status, characters there, resources available.

\## Extra credit

None