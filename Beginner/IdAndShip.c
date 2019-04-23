/*
Write a program that takes in a letterclass ID of a ship and display the equivalent string class description of the given ID. Use the table below.

Class ID	Ship Class
B or b	BattleShip
C or c	Cruiser
D or d	Destroyer
F or f	Frigate
Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains a character.

Output
Display the Ship Class depending on ID.

Constraints
1 ≤ T ≤ 1000
Example
Input

3 
B
c
D

Output
BattleShip
Cruiser
Destroyer

https://www.codechef.com/problems/FLOW010
*/
#include <stdio.h>

enum ShipClass
{
    BattleShip,
    Cruiser,
    Destroyer,
    Frigate
};

char toUpper(char alphabet)
{
    return alphabet >= 'a' && alphabet <= 'z' ? alphabet - 32 : alphabet;
}

char *getShipClass(char shipId)
{
    shipId = toUpper(shipId);
    switch (shipId)
    {
    case 'B':
        return BattleShip;
    case 'C':
        return Cruiser;
    case 'D':
        return Destroyer;
    case 'F':
        return Frigate;
    }
}

int main()
{
    char shipID = 'B';
    enum ShipClass shipClass = getShipClass(shipID);

    switch (shipClass)
    {
    case BattleShip:
        printf("BattleShip\n");
        break;
    case Cruiser:
        printf("Cruiser\n");
        break;
    case Destroyer:
        printf("Destroyer\n");
        break;
    case Frigate:
        printf("Frigate\n");
        break;
    }

    return 0;
}