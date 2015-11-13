//
//  Character.hpp
//  A2
//
//  Created by Ryan Hotte on 2015-11-13.
//  Copyright © 2015 1. All rights reserved.
//
#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Character
{
public:
    Character();
    Character(string);
    ~Character();
    string getName() const;
    void setName(string);
    
private:
    string name;
    
};

#endif
