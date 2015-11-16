//
//  main.cpp
//  Tests
//
//  Created by Ryan Hotte on 2015-11-15.
//  Copyright © 2015 1. All rights reserved.
//

#include <gtest/gtest.h>
#include "commands.hpp"
#include <string>

string test = "Commands::\n"\
"exit       -- close program\n"\
"create     -- create a new object\n"\
"show       -- show created objects\n"\
"load       -- load from file\n"\
"save       -- save to file\n"\
"help       -- lists these commands\n";
// my first fancy addition test
TEST (A2, Addition)
{
    // equal to 20
    EXPECT_EQ(10 + 10, 20);
    
}

TEST(A2, Help)
{
    Commands cam;
    EXPECT_EQ(test, cam.help());
}

TEST(A2, Show)
{
    Commands cam;
    EquipmentManager* eManager = new EquipmentManager();
    list<Equipment*> eqList;        // list to hold clones
    
    Equipment* pEquipment;
    pEquipment = eManager->createEquipment(bike);
    pEquipment->setName("1");
    eqList.push_back(pEquipment);
    
    EXPECT_EQ(1,cam.showList(eqList));
}

TEST(A2, DeleteList)
{
    Commands cam;
    EquipmentManager* eManager = new EquipmentManager();
    list<Equipment*> eqList;        // list to hold clones
    
    Equipment* pEquipment;
    pEquipment = eManager->createEquipment(bike);
    pEquipment->setName("1");
    eqList.push_back(pEquipment);
    
    cam.deleteList(eqList);
    
    EXPECT_TRUE(eqList.empty());
    
}


int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}