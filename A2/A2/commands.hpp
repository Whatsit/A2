//
//  commands.hpp
//  A2
//
//  Created by Ryan Hotte on 2015-11-15.
//  Copyright © 2015 1. All rights reserved.
//

#ifndef commands_hpp
#define commands_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include "Equipment.cpp"

using namespace std;

class Commands
{
/**
 Header class for all commands avalible to user.
 */
public:
    string help() const;
    int deleteList(list<Equipment*>&);
    int showList(list<Equipment*>&) const;
    void popList(list<Equipment*>&);
    void createType(string, string, EquipmentManager*, list<Equipment*>&);
    void run();
private:
    const string helpStr = "Commands::\n"\
    "exit                   -- close program\n"\
    "create (Type) (name)   -- create a new object given type<bike/treadmill> \n\
                            and inctance name\n"\
    "show                   -- show created objects\n"\
    "pop                    -- remove last type entered\n"\
    "help                   -- lists these commands\n";
};

#endif /* commands_hpp */
