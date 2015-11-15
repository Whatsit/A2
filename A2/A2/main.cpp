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

using namespace std;

/**
 helpStr: Global variable used for help command.
 */
const string helpStr = "Commands::\n"\
                        "exit       -- close program\n"\
                        "create     -- create a new object\n"\
                        "show       -- show created objects\n"\
                        "load       -- load from file\n"\
                        "save       -- save to file\n"\
                        "help       -- lists these commands\n";

int main(int argc, const char * argv[]) {
    /**
     main(): Display's command options on the command line and
     excepts inputs from the user.
     */
    string name;                    // holds name of inctance
    string command;                 // holds user commands
    list<Equipment*> eqList;        // list to hold clones
    list<Equipment*>::iterator it;  // iterator for list
    
    // create Equipment manager to help create clones
    EquipmentManager* eManager = new EquipmentManager();
    
    // main command loop
    while (true) {
        cout << endl << "ENTER COMMAND> ";
        cin >> command;
        if (command == "exit") {            // exit program
            break;
        }
        else if (command == "help") {       // display help
            cout << helpStr;
        }
        else if (command == "create") {     // create a clone
            eqType type;
            cout << "COMMAND>Enter the type and name(ex:bike 1)> ";
            cin >> command >> name;
            // select type
            if (command == "treadmill") { type = treadmill;}
            else if (command == "bike") {type = bike;}
            else {cout << "ERROR::Type not recognized";}
            // create clone and add to list
            Equipment* pEquipment;
            pEquipment = eManager->createEquipment(type);
            pEquipment->setName(name);
            eqList.push_back(pEquipment);
            
        }
        else if (command == "show") {       // print clones in list
            for(it = eqList.begin(); it!=eqList.end(); it++)
            {
                (*it)->display();
            }
        }
        else if (command == "load") {       // load list of clones
            cout << command << endl;
        }
        else if (command == "save") {       // save list of clones
            cout << command << endl;
        }
        else {                              // bad input
            cout << "command not recognized::Try typing> help" << endl;
        }
    }
    // clean up memory
    for(it = eqList.begin(); it!=eqList.end(); it++)
    {
        delete *it;
    }
    delete eManager;                        // delete manager
    
    return 0;                               // exit
}
