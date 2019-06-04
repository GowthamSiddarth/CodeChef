/*
Given an array A of size N , check if there exist any pair of index i,j such that Ai=Aj and i≠j
Input
The first line of the input contains a single integer T denoting the number of test cases.
The first line of each test case contains integer N.
The second line of each test case contains N space separated integers Ai.
Output
For each test case, print a single line containing answer "Yes" or "No" (without quotes).

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
Yes
No
Explanation
Example case 1: A1 and A3 both have value 1.

Example case 2: All values are pairwise distinct.

https://www.codechef.com/problems/CEQUAL
*/
#include <stdlib.h>

enum Boolean
{
    FALSE,
    TRUE
};

int compareInts(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

enum Boolean duplicateItemExists(int *arr, int len)
{
    qsort(arr, len, sizeof(arr[0]), compareInts);
    int offset = 0, idx = 1;
    while (idx < len && arr[idx] != arr[offset])
    {
        offset = idx;
        idx++;
    }
    
    return len == idx ? FALSE : TRUE;
}