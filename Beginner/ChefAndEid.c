/*
During Eid, it's a tradition that each father gives his kids money which they can spend on entertainment.

Chef has N coins; let's denote the value of coin i by vi. Since today is Eid, Chef is going to give one coin to each of his two children. He wants the absolute value of the difference between the values of coins given to the two children to be as small as possible, so that he would be as fair as possible.

Help Chef by telling him the minimum possible difference between the values of the coins given to the two children. Of course, Chef cannot give the same coin to both children.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers v1,v2,…,vN.
Output
For each test case, print a single line containing one integer — the minimum possible difference.

Constraints
1≤T≤100
2≤N≤105
the sum of N in all test cases does not exceed 5⋅105
1≤vi≤106 for each valid i
Subtasks
Subtask #1 (30 points): the sum of N in all test cases does not exceed 2,000
Subtask #2 (70 points): original constraints

Example Input
2
3
1 4 2
3
1 3 3
Example Output
1
0
Explanation
Example case 1: Chef gives the coin with value 1 to his first child and the coin with value 2 to the second child, so the answer is 2−1=1.

Example case 2: Chef gives each of his children a coin with value 3, so the difference is 0.

https://www.codechef.com/problems/EID
*/
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

int compare(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

int getMinPossibleDiff(int *coins, int numOfCoins)
{
    qsort(coins, numOfCoins, sizeof(coins[0]), compare);
    int minConsDiff = INT_MAX, idx = 1;
    while (idx < numOfCoins)
    {
        int currDiff = coins[idx] - coins[idx - 1];
        if (0 == currDiff)
        {
            return 0;
        }
        else if (currDiff < minConsDiff)
        {
            minConsDiff = currDiff;
        }

        idx++;
    }

    return minConsDiff;
}

int main()
{
    int coins[] = {1, 3, 3};
    int numOfCoins = sizeof(coins) / sizeof(coins[0]);

    int minDiff = getMinPossibleDiff(coins, numOfCoins);
    printf("%d\n", minDiff);

    return 0;
}