// Name: <Abdallah> <Abualkheir>
// Date: <5/14/2020>
// Course Code: CS-172-<2>
// Copyright (C) <Abdallah Abualkheir> 2020 - 2021
//main file
#include <iostream>
#include <string>
#include <ctime>
#include "../headers/gameboard.h"    // map base class
#include "../headers/player_map.h"   //map derived class
#include "../headers/opponent_map.h" // map derived class

int main()
{
    srand(time(NULL)); // seed
    int location_x;
    int location_y;
    Player player_map;
    Opponent opponent_map;
    //create an empty map for the player
    player_map.create_map();
    //fill the map with ships
    player_map.set_player_map();
    //create an empty map for the opponent
    opponent_map.create_map();
    //randomly fill the map with ships
    opponent_map.set_opponent_map();
    //output the map to file // the player is not supposed to see the opponent's map in a game of Battle ships
    opponent_map.map_file();
    cout << "----------------------------------" << endl;
    //char choice ; // choice to close the game
    do
    {
        int op_location_x = rand() % 10; // random attack x input for opponent
        int op_location_y = rand() % 10; // random attack y input for opponent
        cout << "Your turn: " << endl;
        cout << "Input your target location for attack:" << endl;
        cout << "Top is 0, bottom is 9" << endl;
        cout << "X: ";
        cin >> location_x; //ask for x attack location
        cout << "Y: ";
        cout << "Far left is 0, far rigt is 9 " << endl;
        cin >> location_y; // ask for y attack location
        //bad input check
        while ((location_x < 0 || location_x > 9) || (location_y < 0 || location_y > 9))
        {
            cout << "You entered invalid input. please enter proper input\n";
            cout << "Input your target location for attack:" << endl;
            cout << "Top is 0, bottom is 9" << endl;
            cout << "X: ";
            cin >> location_x; //ask for x attack location
            cout << "Y: ";
            cout << "Far left is 0, far rigt is 9 " << endl;
            cin >> location_y; // ask for y attack location
        }

        opponent_map.attack(location_x, location_y); //player's attack on opponent
        opponent_map.map_file();                     // update the map in the text output file
        cout << "Opponent's turn: " << endl;
        player_map.attack(op_location_x, op_location_y); // opponent's attack on player
        player_map.show_map();                           // show player map after attack

    } while ((!player_map.empty_map()) && (!opponent_map.empty_map())); 
    if (player_map.empty_map())
    {
        cout << "The opponent wins!" << endl;
    }
    else if (opponent_map.empty_map())
    {
        cout << "The player wins!" << endl;
    }

    return 0;
}