// Name: <Abdallah> <Abualkheir>
// Date: <5/14/2020>
// Course Code: CS-172-<2>
// Copyright (C) <Abdallah Abualkheir> 2020 - 2021
//ship derived class
#pragma once
#pragma once
#include "../headers/battleship.h"
class Cruiser : public Battle_ship
{
public:
    Cruiser() : Battle_ship(3, 3 ,"Cruiser") {}
};