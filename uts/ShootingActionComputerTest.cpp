#include "gtest/gtest.h"
#include "../include/ShootingActionComputer.hpp"
#include "../include/BoardUser.hpp"
#include "../include/Position.hpp"

class ShootingActionComputerTest : public ::testing::Test
{
public:
    ShootingActionComputer actionComputer;
    BoardUser bu;
};



TEST_F(ShootingActionComputerTest, computerShotExpect0_LT_XandY_LT_fieldSize)
{
    Position shot = actionComputer.computerShot(bu);
    EXPECT_GT(bu.getFieldSize(), shot.x);
    EXPECT_GT(bu.getFieldSize(), shot.y);
    EXPECT_LT(0, shot.x);
    EXPECT_LT(0, shot.y);
}