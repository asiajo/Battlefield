#include "gtest/gtest.h"
#include "../include/BoardUser.hpp"

class BoardUserTest : public ::testing::Test
{
public:
    BoardUser boardUser;
    Position pos = {1,1};
};


TEST_F(BoardUserTest, getValueAt11Expect0)
{
    EXPECT_EQ(FieldStatus::FREE, boardUser.getFieldInfo(pos));
}

TEST_F(BoardUserTest, pushShipExpectTrue)
{
    EXPECT_EQ(true, boardUser.pushShip(pos));
}

TEST_F(BoardUserTest, getValueAt11Expect1)
{
    boardUser.pushShip(pos);
    EXPECT_EQ(FieldStatus::SHIP, boardUser.getFieldInfo(pos));
}

TEST_F(BoardUserTest, getFieldSizeExpect12)
{
    EXPECT_EQ(12, boardUser.getFieldSize());
}

TEST_F(BoardUserTest, checkIfSetFieldSetsFieldValue)
{
    boardUser.SetField(pos, FieldStatus::SHOT);
    EXPECT_EQ(FieldStatus::SHOT, boardUser.getFieldInfo(pos));
}

TEST_F(BoardUserTest, isShipShotAt11ExpectSUNK1)
{
    boardUser.pushShip(pos);
    EXPECT_EQ(ShootResult::SUNK1, boardUser.shoot(pos));
}

TEST_F(BoardUserTest, isShipShotAt33ExpectSUNK1)
{
    Position pos33 = {3, 3};
    boardUser.pushShip(pos33);
    EXPECT_EQ(ShootResult::SUNK1, boardUser.shoot(pos33));
}

TEST_F(BoardUserTest, shootUserAtEmptyUserFieldExpectMISS)
{
    EXPECT_EQ(ShootResult::MISS, boardUser.shoot(pos));
}

TEST_F(BoardUserTest, shootUserAtFilledFieldExpectHIT)
{
    boardUser.pushShip(pos);
    Position pos12 = {1,2};
    boardUser.pushShip(pos12);
    EXPECT_EQ(ShootResult::HIT, boardUser.shoot(pos));
}

TEST_F(BoardUserTest, shootUserOutOfBoundsExpectFAIL)
{
    int i = boardUser.getFieldSize();
    Position pos = {i+1,i+1};
    EXPECT_EQ(ShootResult::FAIL, boardUser.shoot(pos));
}

TEST_F(BoardUserTest, isTripleShipShotExpectTrue)
{
    Position pos12 = {1, 2};
    Position pos13 = {1, 3};
    boardUser.pushShip(pos);
    boardUser.pushShip(pos12);
    boardUser.pushShip(pos13);
    EXPECT_EQ(ShootResult::HIT, boardUser.shoot(pos));
    EXPECT_EQ(ShootResult::HIT, boardUser.shoot(pos12));
    EXPECT_EQ(ShootResult::SUNK3, boardUser.shoot(pos13));
}