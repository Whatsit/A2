//
//  Equipment.cpp
//  A2
//
//  Created by Ryan Hotte on 2015-11-13.
//  Copyright © 2015 1. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

enum eqType {treadmill, bike};

class Equipment
{
public:
    Equipment() {}
    virtual Equipment* clone() = 0;
    virtual ~Equipment() {}
    virtual void display() const = 0;
};

class TreadMill : public Equipment
{
public:
    TreadMill(string name) : Equipment(), m_name(name){}
    TreadMill(const TreadMill& tread) : Equipment(tread){m_name = tread.m_name;}
    Equipment* clone() {return new TreadMill(*this);}
    void display() const {cout << m_name << endl;}
private:
    string m_name;
};

class Bike : public Equipment
{
public:
    Bike(string name) : Equipment(), m_name(name){}
    Bike(const Bike& bike) : Equipment(bike){m_name = bike.m_name;}
    Equipment* clone() {return new Bike(*this);}
    void display() const {cout << m_name << endl;}
private:
    string m_name;
};

class EquipmentManager
{
public:
    EquipmentManager()
    {
        m_gymTable[treadmill] = new TreadMill::TreadMill("treadmill 1");
        m_gymTable[bike] = new Bike::Bike("bike 1");
    }
    ~EquipmentManager()
    {
        delete m_gymTable[treadmill];
        delete m_gymTable[bike];
    }
    Equipment* createEquipment(eqType type)
    {
        return m_gymTable[type]->clone();
    }
private:
    map<eqType, Equipment*> m_gymTable;
};

