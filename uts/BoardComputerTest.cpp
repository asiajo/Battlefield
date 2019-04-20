#include "gtest/gtest.h"
#include "../include/BoardComputer.hpp"
#include "../include/Position.hpp"
#include "../include/FieldStatus.hpp"

class BoardComputerTest : public ::testing::Test
{
public:
    BoardComputer boardComputer;
    Position pos = {1,1};
};


TEST_F(BoardComputerTest, getValueAt11Expect0or1)
{
    EXPECT_LE(0, static_cast<int>(boardComputer.getFieldInfo(pos)));
    EXPECT_GE(1, static_cast<int>(boardComputer.getFieldInfo(pos)));
}

TEST_F(BoardComputerTest, getFieldSizeExpect12)
{
    EXPECT_EQ(12, boardComputer.getFieldSize());
}

TEST_F(BoardComputerTest, checkIfSetFieldSetsFieldValue)
{
    boardComputer.SetField(pos, FieldStatus::MISSED);
    EXPECT_EQ(FieldStatus::MISSED, boardComputer.getFieldInfo(pos));
}

TEST_F(BoardComputerTest, checkIfFillComputerFieldSets20Ships)
{
    int bSize = boardComputer.getFieldSize();
    int amount = 0;
    Position pos;
    for (int i = 0; i < bSize; i++)
        for(int j = 0; j < bSize; j++)
        {
            pos = {i, j};
            if (boardComputer.getFieldInfo(pos) == FieldStatus::SHIP)
                amount++;
        }
    EXPECT_EQ(20, amount);
}

TEST_F(BoardComputerTest, getVisibleFieldInfoAt11ExpectFREE)
{
    EXPECT_EQ(FieldStatus::FREE, boardComputer.getVisibleFieldInfo(pos));
}

TEST_F(BoardComputerTest, checkIfSetVisibleFieldSetsFieldValue)
{
    boardComputer.setVisibleField(pos, FieldStatus::MISSED);
    EXPECT_EQ(FieldStatus::MISSED, boardComputer.getVisibleFieldInfo(pos));
}

TEST_F(BoardComputerTest, shootComputerAtEmptyUserFieldExpectMISS)
{
    EXPECT_EQ(ShootResult::MISS, boardComputer.shoot(pos));
}

TEST_F(BoardComputerTest, shootComputerOutOfBoundsExpectFAIL)
{
    int i = boardComputer.getFieldSize();
    Position out = {i+1, i+1};
    EXPECT_EQ(ShootResult::FAIL, boardComputer.shoot(out));
}

TEST_F(BoardComputerTest, crossedFieldsCrossesThem)
{
    int bSize = boardComputer.getFieldSize();
    bool found = false;
    int shipSize =0;
    Position posIJ;
    for(int i =1; i < bSize-1; i++)
        if(!found)
            for(int j=1; j<bSize-1; j++)
                if(!found)
                {
                    posIJ = {i, j};
                    ShootResult rs = boardComputer.shoot(posIJ);
                    if((rs != ShootResult::MISS) && (rs != ShootResult::HIT))
                    {
                        if(i+1 < bSize-1)
                            posIJ = {i+1, j};
                        else if(j+1 < bSize-1)
                            posIJ = {i, j+1};
                        else
                            posIJ = {i-1, j-1};                      
                        found = true;
                        break;
                    }
            }  
    boardComputer.crossFields();
    EXPECT_EQ(FieldStatus::SHIP_SURROUNDING, boardComputer.getFieldInfo(posIJ));

}