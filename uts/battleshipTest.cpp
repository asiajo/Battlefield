#include "gtest/gtest.h"
#include "ships.hpp"

class BattleshipTest : public ::testing::Test
{
public:
    utils::Battleship ship{10};
};


TEST_F(BattleshipTest, getValueAt11Expect0)
{
    EXPECT_EQ(0, ship.getFieldInfo(1,1));
}

TEST_F(BattleshipTest, pushShipExpectTrue)
{
    EXPECT_EQ(true, ship.pushShip(1,1));
}

TEST_F(BattleshipTest, getValueAt11Expect1)
{
    ship.pushShip(1,1);
    EXPECT_EQ(1, ship.getFieldInfo(1,1));
}

TEST_F(BattleshipTest, shootShipAt11)
{
    ship.pushShip(1,1);
    EXPECT_EQ(true, ship.shoot(1,1));
    EXPECT_EQ(false, ship.shoot(2,1));
}

TEST_F(BattleshipTest, checkIfWon)
{
    ship.pushShip(1,1);
    EXPECT_EQ(false, ship.checkIfWon());
    ship.shoot(1,1);
    EXPECT_EQ(true, ship.checkIfWon());
}
