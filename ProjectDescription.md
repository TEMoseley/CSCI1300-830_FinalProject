\# CSCI 1300 Final Project



\## Theme

Based around the Justice League from DC Comics, and the player plays as Robin.

\## Goal

Build a new Justice Leage headquarters.

\## Planned limited resource

Money, restored daily.

\## Plan for handling time

Every transactional choice, such as gathering a resource, take one hour. Every travel between named locations takes one hour. After 8 hours, a day passes and Robin's position resets to Gotham.

\## Classes

Player - it stores the player's prefered pronouns, their money, their inventory, their skill levels, and any temporary stat modifiers.

Game - player's current location, the hour, the day, the character list, the location list, the main menu, and pretty much anything else related to the game itself.

Item - it stores item name, item value, and stat modification if consumed.

Character - it stores character name, their location, if they are good or bad, relationship level, and the resource and/or item they provide.

Hero - derived class of Character

Villain - derived class of Character

Location - name, unlocked status, characters there, resources available.



