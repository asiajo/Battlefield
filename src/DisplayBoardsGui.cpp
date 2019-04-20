#include "../include/DisplayBoardsGui.hpp"
#include <iostream>


DisplayBoardsGui::DisplayBoardsGui(BoardComputer& computer, BoardUser& player, PlayGame& playGame)
{
    
    sf::RenderWindow app(sf::VideoMode(w*12*2, w*12+w*4), "Battleship");
    app.setFramerateLimit(90);
    sf::Texture background;
    background.loadFromFile("images/background.jpg");
    sf::Sprite sBackground(background);
    sf::Texture t;
    t.loadFromFile("images/tiles.jpg");
    sf::Sprite s(t);
    sf::Event e;

    if (!font.loadFromFile("fonts/Ubuntu-M.ttf"))
        std::cout << "Error loading font\n" ;
    atext.setFont(font);
    atext.setCharacterSize(23);
    atext.setFillColor(sf::Color::White);
    atext.setPosition(150,52);
    
    bool computerTurn = false;
    bool userTurn = true;
    bool userSet = false;
    int userShips = 0;   
    int shipSize; 

    int ship4 = 1;
    int ship3 = 2;
    int ship2 = 3;
    int ship1 = 4;
    Position p;
    
    while (app.isOpen())
    {
        app.pollEvent(e);
        int x = e.mouseButton.x/w;
        int y = e.mouseButton.y/w-4;

        if (e.type == sf::Event::Closed)
            app.close();

        if (e.type == sf::Event::MouseButtonPressed && !(playGame.checkIfWon(computer) || playGame.checkIfWon(player)))
        {
            if(x<11 && x>0 && y>0 && y<11 && userSet == true && e.mouseButton.button == sf::Mouse::Left)
            {
                p = {x,y};
            }
            else if(x>12 && userSet == false && e.mouseButton.button == sf::Mouse::Left) 
            {
                p = {x-12, y};
                if(player.pushShip(p))
                {
                    userShips++;
                    if (userShips == 20)
                    {
                        userSet = true;
                        p ={};
                    }
                }
            }
        }
        if(userTurn && userSet == true) 
        {
            computerTurn = playGame.shootingAtComputer(p, computer, shipSize);
            if(shipSize == 4) ship4--;
            if(shipSize == 3) ship3--;
            if(shipSize == 2) ship2--;
            if(shipSize == 1) ship1--;
        }
        if(computerTurn && userSet == true) 
        {
            userTurn = playGame.shootingByComputer(player);
            computerTurn = !userTurn;
        }
        app.clear(sf::Color::White);
        app.draw(sBackground);
        displayShipsCounter(app, ship4, ship3, ship2, ship1);
        displayFields(app, computer, player, s, w);
        
        if (playGame.checkIfWon(computer)) 
            alert(app, "You won!");
        else if (playGame.checkIfWon(player)) 
            alert(app, "You lost!");  
        app.display(); 
    }
}

void DisplayBoardsGui::alert(sf::RenderWindow& app, std::string text)
{
    app.pushGLStates();

    std::ostringstream osa;
    osa << text << std::endl;
    sf::Text texta;
    texta.setFont(font);
    texta.setCharacterSize(200);
    texta.setFillColor(sf::Color::White);
    texta.setPosition(200,300);
    texta.setString(osa.str());

    app.draw(texta);
    app.popGLStates();
}

void DisplayBoardsGui::displayFields(sf::RenderWindow& app, const BoardComputer& computer, const BoardUser& player, sf::Sprite& s, int w)
{
    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
        {
            std::vector<int> colors{7,6,7,5,8,6,5,7,6,8,5,6,8,7,5,6,8,7,6,8,7,5,6,8,6,5};
            int tile;
            Position p = {i,j};
            if(computer.getVisibleFieldInfo(p) == FieldStatus::FREE)
                tile = colors[(i+j*2)%colors.size()];
            else
                tile = static_cast<int>(computer.getVisibleFieldInfo(p));
            s.setTextureRect(sf::IntRect(tile*w,0,w,w));
            s.setPosition(i*w, (j+4)*w);
            app.draw(s);
        }

    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
        {
            std::vector<int> colors{8,5,6,7,5,6,8,7,5,6,8,6,7,6,8,5,7,5,6,8,7,6,5,8,6};
            int tile;
            Position p = {i,j};
            if(player.getFieldInfo(p) == FieldStatus::FREE)
                tile = colors[(i*3+j)%colors.size()];
            else
                tile = static_cast<int>(player.getFieldInfo(p));
            s.setTextureRect(sf::IntRect(tile*w,0,w,w));
            s.setPosition((i+12)*w, (j+4)*w);
            app.draw(s);
        }   
}

void DisplayBoardsGui::displayShipsCounter(sf::RenderWindow& app, int ship4, int ship3, int ship2, int ship1)
{
    app.pushGLStates();
    os.str("");
    os << ship4 << " \n" << ship3 << " \n" << ship2 << " \n" << ship1 << std::endl;
    atext.setString(os.str());

    app.draw(atext);
    app.popGLStates();
}