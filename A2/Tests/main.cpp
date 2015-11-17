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
"pop        -- remove last type entered"\
"help       -- lists these commands\n";

/**
 Test cases:\n
 Help           --test help finction\n
 Show           --test showList function\n
 DeleteList     --test deleteList function\n
 Pop            --test pop function\n
 Create         --test createType function\n
 */
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

TEST(A2, Pop)
{
    Commands cam;
    EquipmentManager* eManager = new EquipmentManager();
    list<Equipment*> eqList;        // list to hold clones
    
    Equipment* pEquipment;
    pEquipment = eManager->createEquipment(bike);
    pEquipment->setName("1");
    eqList.push_back(pEquipment);
    EXPECT_FALSE(eqList.empty());
    cam.popList(eqList);
    EXPECT_TRUE(eqList.empty());
}

TEST(A2, Create)
{
    Commands cam;
    EquipmentManager* eManager = new EquipmentManager();
    list<Equipment*> eqList;        // list to hold clones
    cam.createType("bike", "12", eManager, eqList);
    list<Equipment*>::iterator t = eqList.begin();
    EXPECT_EQ("bike", (*t)->getType());
}


int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}