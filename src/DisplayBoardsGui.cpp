#include "../include/DisplayBoardsGui.hpp"
#include <iostream>


DisplayBoardsGui::DisplayBoardsGui(BoardComputer& computer, BoardUser& player, PlayGame& playGame)
{
    
    sf::RenderWindow app(sf::VideoMode(w*12*2, w*12+w*4), "Battleship");
    sf::Texture background;
    background.loadFromFile("images/background.jpg");
    sf::Sprite sBackground(background);
    sf::Texture t;
    t.loadFromFile("images/tiles.jpg");
    sf::Sprite s(t);
    sf::Event e;
    
    bool computerTurn = false;
    bool userTurn = true;
    bool userSet = false;
    int userShips = 0;   
    int shipSize; 

    int ship4 = 1;
    int ship3 = 2;
    int ship2 = 3;
    int ship1 = 4;
    
    while (app.isOpen() && !( playGame.checkIfWon(computer) || playGame.checkIfWon(player) ))
    {
        sf::Vector2i pos = sf::Mouse::getPosition(app);
        int x = pos.x/w;
        int y = pos.y/w-4;
        app.pollEvent(e);

        if (e.type == sf::Event::Closed)
            app.close();

        if (e.type == sf::Event::MouseButtonPressed)
        {
            if(x<11 && x>0 && y>0 && y<11 && userSet == true)
            {
                if (e.mouseButton.button == sf::Mouse::Left) 
                    if(userTurn) 
                    {
                        computerTurn = playGame.shootingAtComputer(x, y, computer, shipSize);
                        if(shipSize == 4) ship4--;
                        if(shipSize == 3) ship3--;
                        if(shipSize == 2) ship2--;
                        if(shipSize == 1) ship1--;
                    }
            }
            else if(x>12 && userSet == false)
                if (e.mouseButton.button == sf::Mouse::Left) 
                    if(player.pushShip(x-12, y))
                    {
                        userShips++;
                        if (userShips == 20)
                            userSet = true;
                    }
        }
        if(computerTurn && userSet == true && x<12) 
        {
            userTurn = playGame.shootingByComputer(player);
            computerTurn = !userTurn;
        }
        app.clear(sf::Color::White);
        app.draw(sBackground);
        displayShipsCounter(app, ship4, ship3, ship2, ship1);
        displayFields(computer, player, app, s, w);
        
        if (playGame.checkIfWon(computer)) 
            alert("You won!");
        else if (playGame.checkIfWon(player)) 
            alert("You lost!");  
    }
}

void DisplayBoardsGui::alert(std::string text)
{
    sf::RenderWindow alrt(sf::VideoMode(400, 400), text);
    while (alrt.isOpen())
    {
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
}

void DisplayBoardsGui::displayFields(BoardComputer& computer, BoardUser& player, sf::RenderWindow& app, sf::Sprite& s, int w)
{
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

void DisplayBoardsGui::displayShipsCounter(sf::RenderWindow& app, int ship4, int ship3, int ship2, int ship1)
{
    app.pushGLStates();

    sf::Font font;
    if (!font.loadFromFile("fonts/Ubuntu-M.ttf"))
        std::cout << "Error loading font\n" ;
    std::ostringstream ss;
    ss << ship4 << " \n" << ship3 << " \n" << ship2 << " \n" << ship1 << std::endl;
    sf::Text atext;
    atext.setFont(font);
    atext.setCharacterSize(23);
    atext.setFillColor(sf::Color::White);
    atext.setPosition(150,52);
    atext.setString(ss.str());

    app.draw(atext);
    app.popGLStates();
}