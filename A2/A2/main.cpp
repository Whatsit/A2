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
#include "Character.hpp"
#include "Equipment.cpp"

using namespace std;

const string helpStr = "Commands::\n"\
                        "exit\n"\
                        "create\n"\
                        "help\n";

int main(int argc, const char * argv[]) {
    
    string name;
    string command;
    list<Equipment*> eqList;
    list<Equipment*>::iterator it;
    
    EquipmentManager* eManager = new EquipmentManager();
    typedef map< eqType, Equipment* >::iterator it_type;
    
    while (true) {
        cout << endl << "ENTER COMMAND> ";
        cin >> command;
        if (command == "exit") {
            break;
        }
        else if (command == "help") {
            cout << helpStr;
        }
        else if (command == "create") {
            eqType type;
            cout << "Enter the type: ";
            cin >> command;
            
            if (command == "treadmill") { type = treadmill;}
            else {type = bike;}
            
            Equipment* pEquipment;
            pEquipment = eManager->createEquipment(type);
            eqList.push_back(pEquipment);
            
        }
        else if (command == "show") {
            for(it = eqList.begin(); it!=eqList.end(); it++)
            {
                (*it)->display();
            }
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
    delete eManager;
    
    return 0;
}
