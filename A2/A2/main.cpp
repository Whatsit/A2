//
//  main.cpp
//  A2
//
//  Created by Ryan Hotte on 2015-11-13.
//  Copyright © 2015 1. All rights reserved.
//

#include <iostream>
#include <string>
#include "Character.hpp"

using namespace std;

const string helpStr = "Commands::\n"\
                        "exit\n"\
                        "create\n"\
                        "help\n";

int main(int argc, const char * argv[]) {
    
    string name;
    string command;
    
    while (true) {
        cout << endl << "ENTER COMMAND> ";
        cout << command << endl;
        if (command == "exit") {
            break;
        }
        else if (command == "help") {
            cout << helpStr;
        }
        else if (command == "create") {
            cout << "create has been called" << endl;
        }
        else if (command == "load") {
            cout << command << endl;
        }
        else if (command == "save") {
            cout << command << endl;
        }
        else {
            cout << "command not recognized" << endl;
        }
    }
    
    return 0;
}
