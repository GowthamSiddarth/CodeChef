/*
In a regular table tennis match, the player who serves changes every time after 2 points are scored, regardless of which players scored them.

Chef and Cook are playing a different match — they decided that the player who serves would change every time after K points are scored instead (again regardless of which players scored them). When the game starts, it's Chef's turn to serve.

You are given the current number of points scored by Chef and Cook (P1 and P2 respectively). Find out whether Chef or Cook has to serve next.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers P1, P2 and K.
Output
For each test case, print a single line containing the string "CHEF" if it is Chef's turn or "COOK" if it is Cook's turn.

Constraints
1≤T≤105
1≤K≤109
0≤P1,P2≤109
Subtasks
Subtask #1 (100 points): original constraints

Example Input
3
1 3 2
0 3 2
34 55 2
Example Output
CHEF
COOK
CHEF
Explanation
Example case 1: Chef serves for the first two points, Cook serves for the next two, so Chef has to serve again now.

https://www.codechef.com/problems/CHSERVE
*/
#include <stdio.h>

enum Player
{
    CHEF,
    COOK
};

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isEven(long int num)
{
    return 0 == num % 2 ? TRUE : FALSE;
}

enum Player getNextServer(int chefPoints, int cookPoints, int pointsPerServeChange)
{
    return isEven(((long int)chefPoints + cookPoints) / pointsPerServeChange) ? CHEF : COOK;
}

int main()
{
    int chefPoints = 34, cookPoints = 55, pointsPerServeChange = 2;
    enum Player nextServer = getNextServer(chefPoints, cookPoints, pointsPerServeChange);

    printf("%s\n", CHEF == nextServer ? "CHEF" : "COOK");
    return 0;
}