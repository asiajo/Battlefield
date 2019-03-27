#include "../include/DisplayBoardsGui.hpp"


DisplayBoardsGui::DisplayBoardsGui(BoardComputer& computer, BoardUser& player, PlayGame& playGame)
{
    
    sf::RenderWindow app(sf::VideoMode(w*12*2, w*12+w*4), "Battleship");
    sf::Texture background;
    background.loadFromFile("images/background.jpg");
    sf::Sprite sBackground(background);
    sf::Texture t;
    t.loadFromFile("images/tiles.jpg");
    sf::Sprite s(t);
    
    bool userSet = false;
    int userShips = 0;    
    sf::Event e;

    do
    {
        displayFields(computer, player, app, s, w, sBackground);
    } while (!(app.pollEvent(e)) && app.isOpen() );

    while (app.isOpen() && !( playGame.checkIfWon(computer) || (playGame.checkIfWon(player)  && userSet == true )))
    {
        sf::Vector2i pos = sf::Mouse::getPosition(app);
        int x = pos.x/w;
        int y = pos.y/w-4;

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
            
                displayFields(computer, player, app, s, w, sBackground);
                if (playGame.checkIfWon(computer)) 
                    alert("You won!");
                if (playGame.checkIfWon(player) && userSet == true) 
                    alert("You lost!");
            }
        }
    }
}


void DisplayBoardsGui::alert(std::string text)
{
    sf::RenderWindow alrt(sf::VideoMode(400, 400), text);
    sf::Texture t;
    if(text == "You won!")
        t.loadFromFile("images/youWon.jpg");
    else if(text == "You lost!")
        t.loadFromFile("images/youLost.jpg");
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

void DisplayBoardsGui::displayFields(BoardComputer& computer, BoardUser& player, sf::RenderWindow& app, sf::Sprite& s, int w, sf::Sprite sBackground)
{
    app.clear(sf::Color::White);
    app.draw(sBackground);

    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
        {
            std::vector<int> colors{7,6,7,5,4,6,5,7,6,4,5,6,4,7,5,6,4,7,6,4,7,5,6,4,6,5};
            int tile;
            if(computer.getVisibleFieldInfo(i, j) == 0)
                tile = colors[(i+j*2)%colors.size()];
            else
                tile = computer.getVisibleFieldInfo(i, j);
            s.setTextureRect(sf::IntRect(tile*w,0,w,w));
            s.setPosition(i*w, (j+4)*w);
            app.draw(s);
        }

    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
        {
            std::vector<int> colors{4,5,6,7,5,6,4,7,5,6,4,6,7,6,4,5,7,5,6,4,7,6,5,4,6};
            int tile;
            if(player.getFieldInfo(i, j) == 0)
                tile = colors[(i*3+j)%colors.size()];
            else
                tile = player.getFieldInfo(i, j);
            s.setTextureRect(sf::IntRect(tile*w,0,w,w));
            s.setPosition((i+12)*w, (j+4)*w);
            app.draw(s);
        }
        
    app.display();
}