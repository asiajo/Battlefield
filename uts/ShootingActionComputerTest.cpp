#include "gtest/gtest.h"
#include "../include/ShootingActionComputer.hpp"
#include "../include/BoardUser.hpp"

class ShootingActionComputerTest : public ::testing::Test
{
public:
    ShootingActionComputer actionComputer;
    BoardUser bu;
};



TEST_F(ShootingActionComputerTest, computerShotExpect0_LT_XandY_LT_fieldSize)
{
    std::pair <int, int> shot = actionComputer.computerShot(bu);
    EXPECT_GT(bu.getFieldSize(), shot.first);
    EXPECT_GT(bu.getFieldSize(), shot.second);
    EXPECT_LT(0, shot.first);
    EXPECT_LT(0, shot.second);
}