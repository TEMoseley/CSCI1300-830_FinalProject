\# CSCI 1300 Final Project



\## Theme

Based around the Justice League from DC Comics, and the player plays as Robin. The "plot" is that Batman uses Robin to handle the gathering of some materials necessary for the construction of a new Justice League headquarters, which will be an orbiting space station (this is canonically a thing). 

\## Goal

Build a new Justice League orbiting headquarters.

\## Planned limited resource

Money, and the player receives a small amount of money daily.

\## Plan for handling time

Every transactional choice, such as gathering a resource, take one hour. Every travel between named locations takes one hour. After 8 hours, a day passes and Robin's position resets to Gotham.

\## Classes

Player - it stores the player's curent location and inventory, as well as bools to track player actions.

Game - Tracks time mechanics, objective completion, and stores the map.

Character - it stores the character's name.

Hero - derived class of Character, includes a relationship score for use in the game ending display.

Villain - derived class of Character, includes a risk score to be used by a Villain method that sums the total risk level across all villain characters and uses that to display one unified ending for all the villains.

Location - Stores the name, a brief description, and a location number for ease of use.



