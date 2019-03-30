#include "gtest/gtest.h"
#include "../include/PlayGame.hpp"
#include "../include/BoardComputer.hpp"
#include "../include/BoardUser.hpp"
#include "../include/ShootingActionComputer.hpp"

class PlayGameTest : public ::testing::Test
{
public:
    BoardComputer bc;
    BoardUser bu;
    std::shared_ptr<ShootingActionComputer> actionComputer;
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

TEST_F(PlayGameTest, checkIfBothBoardsAreChangedAfterShootingSession)
{
    pg.shootingSession(1, 1, bc, bu);
    EXPECT_EQ(3, bc.getFieldInfo(1,1));
    EXPECT_EQ(3, bc.getVisibleFieldInfo(1,1));
    int bSize = bu.getFieldSize();
    int fieldsShot = 0;
    for (int i = 1; i < bSize-1; i++)
        for(int j = 1; j < bSize-1; j++)
            if (bu.getFieldInfo(i, j) != 0)
                fieldsShot++;
    EXPECT_EQ(1, fieldsShot);
}