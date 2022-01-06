// Name: <Abdallah> <Abualkheir>
// Date: <5/14/2020>
// Course Code: CS-172-<2>
// Copyright (C) <Abdallah Abualkheir> 2020 - 2021
//ship derived class
#pragma once
#pragma once
#include "../headers/battleship.h"
class Destroyer : public Battle_ship
{
public:
    Destroyer() : Battle_ship(2 , 2 ,"Destroyer") {}
};