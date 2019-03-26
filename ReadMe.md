# Battleship game

Written using TDD.
Uses SFML library.

Under construction.

## Compilation

I use g++ compiler under Linux. You may compile it the way you like. 
g++ -std=c++17 -Wall app/main.cpp src/battleship.cpp src/battleshipComputer.cpp src/gui.cpp -lsfml-graphics -lsfml-window -lsfml-system

## Testing

Tests made using google test. Need to add appropriate google test data.

## Planned Updates

- [x] hide computer's field
- [ ] improove computer's shooting logic
- [ ] get info with size of shot ship
- [x] implement graphical interface
- [ ] improve graphic
  - [ ] Add background
  - [ ] Add nicer sea
  - [ ] Add welcome screen
  - [ ] Add graphic winner screen
- [ ] add cMake file
- [ ] refactor: Player's Logic and Board Logic

