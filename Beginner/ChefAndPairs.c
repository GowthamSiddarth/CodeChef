/*
Given an array A of size N , count number of pairs of index i,j such that Ai is even, Aj is odd and i<j
Input
The first line of the input contains a single integer T denoting the number of test cases.
The first line of each test case contains integer N.
The second line of each test case contains N space separated integers Ai.
Output
For each test case, print a single line containing an integer denoting number of pairs.

Constraints
1≤T≤100
2≤N≤105
1≤Ai≤109
Sum of N over all test cases doesn't exceed 106
Subtasks
Subtask #1 (30 points):

2≤N≤100
Subtask #2 (70 points): original constraints

Example Input
2
4
1 2 1 3
5
5 4 1 2 3
Example Output
2
3
Explanation
Example case 1: (A2,A3) and (A2,A4) .

Example case 2: (A2,A3) , (A2,A5) and  (A4,A5)  .

https://www.codechef.com/problems/CPAIRS
*/
#include <malloc.h>

enum NumType
{
    ODD,
    EVEN
};

enum NumType getNumType(int num)
{
    return 0 == (num & 1) ? EVEN : ODD;
}

int *getCumulativeOddsCount(int *arr, int len)
{
    int *cumulativeOddsCount = (int *)malloc(sizeof(int) * len);
    for (int idx = 0; idx < len; idx++)
    {
        cumulativeOddsCount[idx] = (idx > 0 ? cumulativeOddsCount[idx - 1] : 0) + ODD == getNumType(arr[idx]) ? 1 : 0;
    }

    return cumulativeOddsCount;
}