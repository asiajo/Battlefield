#include "gtest/gtest.h"
#include "../include/PlayGame.hpp"
#include "../include/BoardComputer.hpp"
#include "../include/BoardUser.hpp"
#include "../include/ShootingActionComputer.hpp"
#include "../include/FieldStatus.hpp"

class PlayGameTest : public ::testing::Test
{
public:
    BoardComputer bc;
    BoardUser bu;
    ShootingActionComputer actionComputer;
    PlayGame pg{actionComputer};
};


TEST_F(PlayGameTest, checkIfComputerWonExpectFalse)
{
    EXPECT_EQ(false, pg.checkIfWon(bc));
}

TEST_F(PlayGameTest, checkIfUserWonExpectFalse)
{
    EXPECT_EQ(false, pg.checkIfWon(bu));
}

TEST_F(PlayGameTest, checkIfComputersBoardIsChangedAfterShootingSession)
{
    int shipSize=0;
    Position pos = {1,1};
    pg.shootingAtComputer(pos, bc, shipSize);
    EXPECT_EQ(FieldStatus::MISSED, bc.getFieldInfo(pos));
    EXPECT_EQ(FieldStatus::MISSED, bc.getVisibleFieldInfo(pos));
    
}

TEST_F(PlayGameTest, checkIfUserBoardIsChangedAfterShootingSession)
{
    pg.shootingByComputer(bu);
    int bSize = bu.getFieldSize();
    int fieldsShot = 0;
    Position pos;
    for (int i = 1; i < bSize-1; i++)
        for(int j = 1; j < bSize-1; j++)
        {
            pos = {i, j};
            if (bu.getFieldInfo(pos) != FieldStatus::FREE)
                fieldsShot++;
        }
    EXPECT_EQ(1, fieldsShot);
}