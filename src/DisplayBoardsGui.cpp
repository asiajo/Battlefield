#include "../include/DisplayBoardsGui.hpp"


DisplayBoardsGui::DisplayBoardsGui(BoardComputer& computer, BoardUser& player, PlayGame& playGame)
{
    
    sf::RenderWindow app(sf::VideoMode(w*12*2, w*12), "Battleship");
    sf::Texture t;
    t.loadFromFile("images/tiles.jpg");
    sf::Sprite s(t);
    
    bool userSet = false;
    int userShips = 0;    

    while (app.isOpen() && !( playGame.checkIfWon(computer) || (playGame.checkIfWon(player)  && userSet == true )))
    {
        sf::Vector2i pos = sf::Mouse::getPosition(app);
        int x = pos.x/w;
        int y = pos.y/w;
        sf::Event e;

        while (app.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                app.close();

   			if (e.type == sf::Event::MouseButtonPressed)
            {
                if(x<12 && userSet == true)
                {
                    if (e.key.code == sf::Mouse::Left) 
                        playGame.shootingSession(x, y, computer, player);
                }
                else if(x>12 && userSet == false)
                    if (e.key.code == sf::Mouse::Left) 
                        if(playGame.pushShip(x-12, y, player))
                        {
                            userShips++;
                            if (userShips == 20)
                                userSet = true;
                        }
            }
            
        }

        app.clear(sf::Color::White);
        for (int i=1;i<=10;i++)
            for (int j=1;j<=10;j++)
            {
                s.setTextureRect(sf::IntRect(
                computer.getVisibleFieldInfo(i, j)*w,0,w,w));
                s.setPosition(i*w, j*w);
                app.draw(s);
            }
        for (int i=1;i<=10;i++)
            for (int j=1;j<=10;j++)
            {
                s.setTextureRect(sf::IntRect(
                player.getFieldInfo(i, j)*w,0,w,w));
                s.setPosition((i+12)*w, j*w);
                app.draw(s);
            }
        app.display();
        if (playGame.checkIfWon(computer)) 
            alert("You won!");
        if (playGame.checkIfWon(player) && userSet == true) 
            alert("You lost!");
    }
}


void DisplayBoardsGui::alert(std::string text)
{
    sf::RenderWindow alrt(sf::VideoMode(200, 200), text);
    sf::Texture t;
    t.loadFromFile("images/tiles.jpg");
    sf::Sprite s(t);
    while (alrt.isOpen())
    {
        alrt.clear(sf::Color::White);
        alrt.draw(s);

        sf::Event e;
        while (alrt.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                alrt.close();
        }

        alrt.display();
    }
}
