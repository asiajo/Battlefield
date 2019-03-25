#include "../include/gui.hpp"


Gui::Gui (BattleshipComputer& computer, Battleship& player)
{
    
    sf::RenderWindow app(sf::VideoMode(w*12*2, w*12), "Battleship");
    sf::Texture t;
    t.loadFromFile("images/tiles.jpg");
    sf::Sprite s(t);
    
    bool userSet = false;
    int userShips = 0;
    bool userWon = false;
    

    while (app.isOpen() && !(computer.checkIfWon() || userWon))
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
                            {
                                if(computer.getFieldInfo(x,y)<=1)
                                {
                                    std::pair <int, int> shipPos = computer.computerShot(player);
                                    computer.shoot(x,y);
                                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                                    player.shoot(shipPos.first, shipPos.second);
                                }
                            }
                }
                else if(x>12 && userSet == false)
                    if (e.key.code == sf::Mouse::Left) 
                            if (player.pushShip(x-12, y))
                                userShips++;
            }
            if (userShips == 20)
                userSet = true;
        }

        app.clear(sf::Color::White);
        setGraphic(s, app, computer, 0);
        setGraphic(s, app, player, 12);
        app.display();
        if (computer.checkIfWon()) alert("You won!");
        if (player.checkIfWon() && userSet == true) 
        {
            userWon = true;
            alert("You lost!");
        }
    }
}

void Gui::setGraphic(sf::Sprite& s, sf::RenderWindow& app, Battleship& player, int move)
{
    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
        {
            s.setTextureRect(sf::IntRect(
            player.getFieldInfo(i, j)*w,0,w,w));
            s.setPosition((i+move)*w, j*w);
            app.draw(s);
        }
}

void Gui::alert(std::string text)
{
    sf::RenderWindow alrt(sf::VideoMode(200, 200), text);
    sf::Texture t;
    t.loadFromFile("images/tiles.jpg");
    sf::Sprite s(t);
    while (alrt.isOpen()){
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



