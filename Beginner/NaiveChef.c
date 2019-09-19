/*
Once, after a stressful day, Chef decided to relax and visit a casino near his house to gamble. He feels lucky and he's going to bet almost all of his money.

The game Chef is going to play in the casino consists of tossing a die with N faces twice. There is a number written on each face of the die (these numbers are not necessarily distinct). In order to win, Chef must get the number A on the first toss and the number B on the second toss of the die.

The excited viewers want to know the probability that Chef will win the game. Can you help them find that number? Assume that Chef gets each face of the die with the same probability on each toss and that tosses are mutually independent.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, A and B.
The second line contains N space-separated integers x1,x2,…,xN denoting the numbers written on the faces of the die.
Output
For each test case, print a single line containing one real number — the probability that Chef will win. Your answer will be considered correct if its absolute error does not exceed 10−6.

Constraints
1≤T≤70
1≤N≤104
1≤A≤N
1≤B≤N
1≤xi≤N for each valid i
Subtasks
Subtask #1 (20 points):

T≤10
N≤100
Subtask #2 (80 points): original constraints

Example Input
2
5 1 1
1 1 1 1 1
2 1 1
1 2
Example Output
1.0000000000
0.2500000000

https://www.codechef.com/problems/NAICHEF
*/
#include <stdio.h>

int countOfOcc(int *arr, int len, int item)
{
    return 0 == len ? 0 : arr[len - 1] == item ? 1 + countOfOcc(arr, len - 1, item) : countOfOcc(arr, len - 1, item);
}

double getProbabilityOfChefWinning(int *facesOfDice, int numOfFaces, int target1, int target2)
{
    int target1Occ = countOfOcc(facesOfDice, numOfFaces, target1);
    double target1Prob = (double)target1Occ / numOfFaces;
    return target1 == target2 ? target1Prob * target1Prob : target1Prob * countOfOcc(facesOfDice, numOfFaces, target2) / numOfFaces;
}

int main()
{
    int facesOfDice[] = {1, 2};
    int numOfFaces = sizeof(facesOfDice) / sizeof(facesOfDice[0]);
    int target1 = 1, target2 = 1;

    double probabilityOfChefWinning = getProbabilityOfChefWinning(facesOfDice, numOfFaces, target1, target2);
    printf("%.10lf\n", probabilityOfChefWinning);

    return 0;
}