// Name: <Abdallah> <Abualkheir>
// Date: <5/14/2020>
// Course Code: CS-172-<2>
// Copyright (C) <Abdallah Abualkheir> 2020 - 2021
//ships base class
#pragma once
#include <iostream>
using namespace std;
class Battle_ship
{
protected:
    int length; //also considered health of the  ship
    int health;
public:
    string name;
    //default constructor
    Battle_ship() : Battle_ship(-1 , -1,"no name")
    {
        cout << "No arg constructor " << endl;
    }
    //arg constructor
    Battle_ship(int L , int hp ,string n) : length(L) , health(hp) , name(n)
    {
        cout << "ship created " << endl;
    }
    //getter function
    int get_length()
    {
        return length;
    }
    int get_health()
    {
        return health;
    }
    int damage()
    {
        return health--;
    }
};