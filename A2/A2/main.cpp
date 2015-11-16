//
//  main.cpp
//  A2
//
//  Created by Ryan Hotte on 2015-11-13.
//  Copyright © 2015 1. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>
#include "Equipment.cpp"
#include "commands.hpp"

using namespace std;

/**
 helpStr: Global variable used for help command.
 */

int main(int argc, const char * argv[]) {
    /**
     main(): Display's command options on the command line and
     excepts inputs from the user.
     */
    cout << "starting" << endl;
    Commands com;
    com.run();
    cout << endl << "done" << endl;
    return 0;                               // exit
}
