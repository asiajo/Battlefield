battleship: app/main.cpp
	g++ -std=c++17 -Wall app/main.cpp src/Board.cpp src/BoardComputer.cpp src/ShootingActionComputer.cpp src/DisplayBoardsGui.cpp src/PlayGame.cpp src/BoardUser.cpp -lsfml-graphics -lsfml-window -lsfml-system
