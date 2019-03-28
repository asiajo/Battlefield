#include "gtest/gtest.h"
#include "../include/BoardComputer.hpp"

class BoardComputerTest : public ::testing::Test
{
public:
    BoardComputer boardComputer;
};


TEST_F(BoardComputerTest, getValueAt11Expect0or1)
{
    EXPECT_GE(1, boardComputer.getFieldInfo(1,1));
    EXPECT_LE(0, boardComputer.getFieldInfo(1,1));
}

TEST_F(BoardComputerTest, getFieldSizeExpect12)
{
    EXPECT_EQ(12, boardComputer.getFieldSize());
}

TEST_F(BoardComputerTest, checkIfSetFieldSetsFieldValue)
{
    boardComputer.SetField(1, 1, 2);
    EXPECT_EQ(2, boardComputer.getFieldInfo(1,1));
}

TEST_F(BoardComputerTest, checkIfFillComputerFieldSets20Ships)
{
    int bSize = boardComputer.getFieldSize();
    int amount = 0;
    for (int i = 0; i < bSize; i++)
        for(int j = 0; j < bSize; j++)
            if (boardComputer.getFieldInfo(i, j) == 1)
                amount++;
    EXPECT_EQ(20, amount);
}

TEST_F(BoardComputerTest, getVisibleFieldInfoAt11Expect0)
{
    EXPECT_EQ(0, boardComputer.getVisibleFieldInfo(1,1));
}

TEST_F(BoardComputerTest, checkIfSetVisibleFieldSetsFieldValue)
{
    boardComputer.setVisibleField(1, 1, 2);
    EXPECT_EQ(2, boardComputer.getVisibleFieldInfo(1,1));
}


TEST_F(BoardComputerTest, shootComputerAtEmptyUserFieldExpectFalse)
{
    EXPECT_EQ(false, boardComputer.shoot(1,1));
}


TEST_F(BoardComputerTest, shootComputerOutOfBoundsExpectFalse)
{
    int i = boardComputer.getFieldSize();
    EXPECT_EQ(false, boardComputer.shoot(i+1,i+1));
}