/*
Chef likes to play table tennis. He found some statistics of matches which described who won the points in order. A game shall be won by the player first scoring 11 points except in the case when both players have 10 points each, then the game shall be won by the first player subsequently gaining a lead of 2 points. Could you please help the Chef find out who the winner was from the given statistics? (It is guaranteed that statistics represent always a valid, finished match.)

Input
The first line of the input contains an integer T, denoting the number of test cases. The description of T test cases follows. Each test case consist a binary string S, which describes a match. '0' means Chef lose a point, whereas '1' means he won the point.

Output
For each test case, output on a separate line a string describing who won the match. If Chef won then print "WIN" (without quotes), otherwise print "LOSE" (without quotes).

Constraints
1 ≤ T ≤ 1000
1 ≤ length(S) ≤ 100
 

Example
Input:
2
0101111111111
11100000000000

Output:
WIN
LOSE
Explanation
Example case 1. Chef won the match 11:2, his opponent won just two points, the first and the third of the match.

Example case 2. Chef lost this match 11:3, however he started very well the match, he won the first three points in a row, but maybe he got tired and after that lost 11 points in a row.

https://www.codechef.com/problems/TTENIS
*/
#define MAX_LEN 101

#include <string.h>
#include <stdio.h>

enum GameStatus
{
    LOSE,
    WIN
};

enum GameStatus getChefGameStatus(char *points)
{
    int idx = 0, chefPoints = 0, opponetsPoints = 0;
    while ('\0' != points[idx])
    {
        '1' == points[idx] ? chefPoints++ : opponetsPoints++;
        if (chefPoints >= 10 && opponetsPoints >= 10)
        {
            if (2 == chefPoints - opponetsPoints)
            {
                return WIN;
            }
            else if (2 == opponetsPoints - chefPoints)
            {
                return LOSE;
            }
        }
        else if (11 == chefPoints)
        {
            return WIN;
        }
        else if (11 == opponetsPoints)
        {
            return LOSE;
        }

        idx++;
    }
}

int main()
{
    char points[MAX_LEN];
    memcpy(points, "11100000000000", 15);

    enum GameStatus chefGameStatus = getChefGameStatus(points);
    printf("%s\n", LOSE == chefGameStatus ? "LOSE" : "WIN");

    return 0;
}