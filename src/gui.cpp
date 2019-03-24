#include "../include/gui.hpp"


Gui::Gui( Battleship computer, Battleship player)
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
                            computer.shoot(x,y);
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
        if (computer.checkIfWon()) std::cout <<" won" << std::endl;
        if (player.checkIfWon() && userSet == true) userWon = true;
        app.display();
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




