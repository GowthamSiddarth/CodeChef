/*
Chef and Paja are bored, so they are playing an infinite game of ping pong. The rules of the game are as follows:

The players play an infinite number of games. At the end of each game, the player who won it scores a point.
In each game, one of the players serves. Chef serves in the first game.
After every K points are scored (regardless of which players scored them), i.e. whenever K games have been played since the last time the serving player changed, the player that serves in the subsequent games changes: if Chef served in the game that just finished, then Paja will serve in the next game and all subsequent games until the serving player changes again; if Paja served, then Chef will serve.
The players got a little too caught up in the game and they forgot who is supposed to serve in the next game. Will you help them determine that? So far, Chef has scored X points and Paja has scored Y points.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers X, Y and K.
Output
For each test case, print a single line containing the string "Chef" if Chef is supposed to serve next or "Paja" otherwise (without quotes).

Constraints
1≤T≤50
0≤X,Y≤109
1≤K≤109
Subtasks
Subtask #1 (100 points): original constraints

Example Input
3
1 3 3
5 7 2
38657 76322 564
Example Output
Paja
Chef
Paja

Explanation
Example case 1: Chef served for the first three games, after that Paja started serving. He only served in one game, so he is supposed to serve next.

https://www.codechef.com/problems/PAJAPONG
*/
#include <stdio.h>

enum Player
{
    CHEF,
    PAJA
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

enum Player getNextServer(int chefScore, int pajaScore, int numOfGamesForServerChange)
{
    return isEven(((long int)chefScore + pajaScore) / numOfGamesForServerChange) ? CHEF : PAJA;
}

int main()
{
    int chefScore = 38657, pajaScore = 76322, numOfGamesForServerChange = 564;
    enum Player nextServer = getNextServer(chefScore, pajaScore, numOfGamesForServerChange);

    printf("%s\n", CHEF == nextServer ? "Chef" : "Paja");
    return 0;
}