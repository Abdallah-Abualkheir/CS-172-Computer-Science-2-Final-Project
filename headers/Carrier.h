// Name: <Abdallah> <Abualkheir>
// Date: <5/14/2020>
// Course Code: CS-172-<2>
// Copyright (C) <Abdallah Abualkheir> 2020 - 2021
//ship derived class
#pragma once
#include "../headers/battleship.h"
class Carrier : public Battle_ship
{
public:
    Carrier() : Battle_ship(5, 5, "Carrier") {}
};