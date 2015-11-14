//
//  Character.cpp
//  A2
//
//  Created by Ryan Hotte on 2015-11-13.
//  Copyright © 2015 1. All rights reserved.
//

#include "Character.hpp"

Character::Character()
{
}
Character::Character(string n)
{
    name = n;
}
Character::~Character()
{
}

string Character::getName() const
{
    return name;
}
void Character::setName(string n)
{
    name = n;
}