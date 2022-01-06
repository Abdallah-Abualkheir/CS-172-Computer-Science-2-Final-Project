// Name: <Abdallah> <Abualkheir>
// Date: <5/14/2020>
// Course Code: CS-172-<2>
// Copyright (C) <Abdallah Abualkheir> 2020 - 2021
//base class header file
#pragma once
#include <vector> // vector class
#include "../headers/battleship.h"
#include "../headers/Carrier.h"
#include "../headers/Cruiser.h"
#include "../headers/Submarine.h"
#include "../headers/Destroyer.h"
using namespace std; // standard name space
class Game_board
{
protected:                   // protected so derived classes can access this data
    int rows;                // rows in the map grid
    int columns;             // columns in the map grid
    int const MAX_SHIPS = 5; // maximum number of ships per map
    int ships = 0;           // inital number of ships in the map

public:
    char public_board_arry[10][10];                   //map shown only indicating hits and misses
    char board_arry[10][10];                          //the map grid place-holder 10 x 10
    vector<Battle_ship> battleships;                  // vector of Battleship pointers to contain the different ships
    Game_board() : rows(10), columns(10) {}           // default constructor
    Game_board(int r, int c) : rows(r), columns(c) {} //arg constructor
    //create the actual printed map
    void create_map()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                public_board_arry[i][j] = '~';
                this->board_arry[i][j] = '~';
            }
        }
    }
    //display the current map
    void show_map()
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                cout << " " << board_arry[i][j] << " ";
            }
            cout << endl;
        }
    }
    //shows the opponent map
    void show_opp_map()
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                cout << " " << public_board_arry[i][j] << " ";
            }
            cout << endl;
        }
    }
    //check if the map has the maximum number of ships
    virtual bool full_map()
    {
        if (ships == MAX_SHIPS)
        {
            return true;
        }
        return false;
    }
    //check if the map is empty
    virtual bool empty_map()
    {
        if (ships == 0)
        {
            return true;
        }
        return false;
    }
    //check if the ship is fully destroyed
    void health_check(Battle_ship bs)
    {
        if (bs.get_health() <= 0)
        {
            cout << bs.name << " has been destroyed" << endl;
            ships--;
        }
    }
    virtual void attack(int x, int y) = 0;
};