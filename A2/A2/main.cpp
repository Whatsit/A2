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

int main(int argc, const char * argv[]) {
    
    string name;
    
    cout << "ENTER NAME: ";
    cin >> name;
    cout << endl << "Hello " << name;
    
    Character user1(name);
    
    cout << endl << "Hello " << user1.getName();
    
    cout << endl << "ENTER NEW USER: ";
    cin >> name;
    
    Character user2("default");
    user2.setName(name);
    cout << endl << "Thank you " << user1.getName() << " for letting " << user2.getName() << " register" << endl << "Have a nice day" << endl << endl;
    
    
    return 0;
}
