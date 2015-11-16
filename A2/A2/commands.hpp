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

using namespace std;

class Commands
{
public:
    void help() const;
private:
    const string helpStr = "Commands::\n"\
    "exit       -- close program\n"\
    "create     -- create a new object\n"\
    "show       -- show created objects\n"\
    "load       -- load from file\n"\
    "save       -- save to file\n"\
    "help       -- lists these commands\n";
};

#endif /* commands_hpp */
