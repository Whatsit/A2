//
//  commands.cpp
//  A2
//
//  Created by Ryan Hotte on 2015-11-15.
//  Copyright © 2015 1. All rights reserved.
//

#include "commands.hpp"

string Commands::help() const
{
    return helpStr;
}

int Commands::deleteList(list<Equipment*>& i)
{
    list<Equipment*>::iterator t;
    for(t = i.begin(); t!=i.end(); t++)
    {
        delete *t;
    }
    i.clear();
    if (!i.empty()) {
        return 0;
    }
    return 1;
}

int Commands::showList(list<Equipment*>& i) const
{
    int a = 0;
    list<Equipment*>::iterator t;
    for(t = i.begin(); t!=i.end(); t++)
    {
        a++;
        (*t)->display();
    }
    if (a != 0) {
        return a;
    }
    return 0;
}

void Commands::popList(list<Equipment*>& i)
{
    if (!i.empty()) {
        i.pop_back();
    }
}

void Commands::createType(string command, string name, EquipmentManager* eManager, list<Equipment*>& eqList)
{
    eqType type;
    // select type
    if (command == "treadmill") { type = treadmill;}
    else if (command == "bike") {type = bike;}
    else {cout << "ERROR::Type not recognized";}
    
    // create clone and push onto list
    Equipment* pEquipment;
    pEquipment = eManager->createEquipment(type);
    pEquipment->setName(name);
    eqList.push_back(pEquipment);
}

void Commands::run()
{
    /**
     main(): Display's command options on the command line and
     excepts inputs from the user.
     */
    string name;                    // holds name of inctance
    string command;                 // holds user commands
    list<Equipment*> eqList;        // list to hold clones
    
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
            cout << help();
        }
        else if (command == "create") {     // create a clone
            cin >> command >> name;
            createType(command, name, eManager, eqList);
        }
        else if (command == "pop") {        // remove last type from list
            popList(eqList);
        }
        else if (command == "show") {       // print clones in list
            showList(eqList);
        }
        else {                              // bad input
            cout << "command not recognized::Try typing> help" << endl;
        }
    }
    // clean up memory
    deleteList(eqList);

    delete eManager;                        // delete manager
}