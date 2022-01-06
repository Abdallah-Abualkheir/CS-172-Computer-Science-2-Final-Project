// Name: <Abdallah> <Abualkheir>
// Date: <5/14/2020>
// Course Code: CS-172-<2>
// Copyright (C) <Abdallah Abualkheir> 2020 - 2021
//derived class header file
#pragma once
#include <cstdlib>                // rand()
#include <iostream>               //input/output/stream
#include <fstream>                // file stream
#include "../headers/gameboard.h" // base class
class Opponent : public Game_board
{
private:
    size_t count = 0; // counter to identify each ship. increments with each ship created
public:
    //default contructor calls the base class constructor
    Opponent() : Game_board(10, 10) {}
    void set_opponent_ships(Battle_ship b, bool x)
    {
        char ship = '0' + count;
        //'random' x and y input
        int coord1 = rand() % 10;
        int coord2 = rand() % 10;
        //check if there is already a ship at the location passed in
        // if so, exit the function so the program/user can choose again
        for (int i = 0; i < 5; i++)
        {
            if (board_arry[coord1][coord2] == '0' + i)
            {
                cout << "Invalid input, there is already a ship in that location." << endl;
                return;
            }
        }

        // if the bool value passed is 1 or true then print a horizontal ship
        if (x)
        {
            int j = 2; // j checks how many spaces is between the imporoperly placed sign and the ship.
                       // it starts at 2 because the first space is already checked in the while loop condition
            //prints as many signs as the ship's length
            for (int i = 0; i < b.get_length(); i++)
            {
                //In case of ship's length going over the edge, check if the location the sign is being printed to, has other signs next to it
                //indicating that its a complete ship and has no gaps.
                if (coord2 + i > rows - 1) //last index that coord can reach is 9, and rows is 10. so we compare it coord with row-1 =9;
                {
                    board_arry[coord1][coord2 - i] = ship;
                    //if there is a gap, check how far is the sign from the rest of the ship
                    while (board_arry[coord1][coord2 - i + (j - 1)] != ship)
                    {
                        //if the ship is found, print the sign in the proper place then delete the false sign by replacing it with a ~
                        if (board_arry[coord1][coord2 - i + j] == ship)
                        {

                            j--;
                            board_arry[coord1][coord2 - i + j] = ship;
                            board_arry[coord1][coord2 - i] = '~';
                        }
                        //if the ship is not found, increment j to search the space next to the one searched
                        j++;
                    }
                }
                //if the ship is not near any edges, print normally
                else
                {
                    board_arry[coord1][coord2 + i] = ship;
                }
            }
        }
        // if the bool value passed is 0 or false then print a vertical ship
        if (!x)
        {
            int j = 2; // j checks how many spaces is between the imporoper sign and the ship.
                       // it starts at 2 because the first space is already checked in the while loop condition
            //prints as many signs as the ship's length

            for (int i = 0; i < b.get_length(); i++)
            {
                //In case of ship's length going over the edge, check if the location the sign is being printed to has other signs next to it
                //indicating that its a complete ship and has no gaps.
                if (coord1 + i > columns - 1) //last index that coord can reach is 9, and rows is 10. so we compare it coord with row-1 =9;
                {
                    board_arry[coord1 - i][coord2] = ship;
                    //if there is a gap, check how far is the sign from the rest of the ship
                    while (board_arry[coord1 - i + (j - 1)][coord2] != ship)
                    {

                        if (board_arry[coord1 - i + j][coord2] == ship)
                        {
                            j--;
                            board_arry[coord1 - i + j][coord2] = ship;
                            board_arry[coord1 - i][coord2] = '~';
                        }
                        //if the ship is not found, increment j to search the space next to the one searched
                        j++;
                    }
                }
                else
                {
                    board_arry[coord1 + i][coord2] = ship;
                }
            }
        }
        //increment the number of the ships in the map
        ships++;
    }
    bool full_map()
    {
        if (ships == MAX_SHIPS)
        {
            return true;
        }
        return false;
    }

    void set_opponent_map()
    {
        do
        {
            // 'random' ship choice and orientation
            bool orientation = rand() % 2;
            int op_ship_choice = rand() % 5 + 1;
            switch (op_ship_choice)
            {
            case 1: // if the program chooses 1 then create the carrier
                this->battleships.push_back(Carrier());
                set_opponent_ships(this->battleships[count], orientation);
                count++;
                break;
            case 2: // if the program chooses 2 then create the cruiser
                this->battleships.push_back(Cruiser());
                set_opponent_ships(this->battleships[count], orientation);
                count++;
                break;
            case 3: // if the program chooses 3 then create the submarine
                this->battleships.push_back(Submarine());
                set_opponent_ships(this->battleships[count], orientation);
                count++;
                break;
            case 4: // if the program chooses 4 then create the destroyer
                this->battleships.push_back(Destroyer());
                set_opponent_ships(this->battleships[count], orientation);
                count++;
                break;
            }
        } while (!this->full_map()); // add ships until the map is full
    }
    //output the opponent map to  a text file
    void map_file()
    {
        ofstream fout;                 //output file stream
        fout.open("opponent map.txt"); // attempt to open file
        if (fout.fail())               // check if the attempt failed
        {
            cout << "failed to open file " << endl;
            return;
        }
        //output the map
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                fout << this->board_arry[i][j] << " ";
            }
            fout << endl;
        }
        fout.close(); // close and release file to the system
    }

    //this is the function the player is going to use to attack the opponent
    void attack(int x, int y)
    {
        int new_x;                                                              // new x locatain for the second attack function call
        int new_y;                                                              // new y locatain for the second attack function call
        if ((this->board_arry[x][y] == '/') || (this->board_arry[x][y] == 'X')) // if the player attacked an already attacked location
        {                                                                       // attack again with a new random location
            cout << "You already attacked this location. Attack again! " << endl;
            cout << "X :";
            cin >> new_x;
            cout << "Y: ";
            cin >> new_y;
            //bad input check
            while ((new_x < 0 || new_x > 9) || (new_y < 0 || new_y > 9))
            {
                cout << "You entered invalid input. please enter proper input\n";
                cout << "X :";
                cin >> new_x;
                cout << "Y: ";
                cin >> new_y;
            }
            attack(new_x, new_y);
        }
        //if the program detects a sign at the location passed in, then register that as a hit and replace the # with an
        for (int i = 0; i < 5; i++)
        {
            if (this->board_arry[x][y] == '0' + i) // X to indicate a damaged ship
            {
                this->board_arry[x][y] = 'X';
                public_board_arry[x][y] = 'X'; // set the indicator in the public opponent map
                battleships[i].damage();
                cout << "Hit!" << endl;
                health_check(battleships[i]);
                cout << "Opponent map: " << endl;
                show_opp_map();
            }
        }

        if (this->board_arry[x][y] == '~') //otherwise, if the program detects a ~ sign indicating no ship, then register that as a miss
        {                                  // and replace the ~ by a / to indicate a miss
            this->board_arry[x][y] = '/';
            public_board_arry[x][y] = '/'; // set the indicator in the public opponent map
            cout << "Miss!" << endl;
            cout << "Opponent map: " << endl;
            show_opp_map();
        }
    }
};