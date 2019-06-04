/*
Given an array A of size N and an integer K , check if there exist any pair of index i,j such that Ai+Aj=K and i≠j
Input
The first line of the input contains a single integer T denoting the number of test cases.
The first line of each test case contains two space separated integer N and K respectively.
The second line of each test case contains N space separated integers Ai.
Output
For each test case, print a single line containing answer "Yes" or "No" (without quotes).

Constraints
1≤T≤100
2≤N≤104
1≤K≤109
1≤Ai≤109
Subtasks
Subtask #1 (30 points):

2≤N≤100
Subtask #2 (70 points): original constraints

Example Input
3
4 3
1 2 1 3
4 6
1 2 1 3
5 1
5 4 1 2 3
Example Output
Yes
No
No
Explanation
Example case 1: A1+A2=3.

Example case 2: Pair having Ai+Aj=6 doesn't exist.

Example case 3: Pair having Ai+Aj=1 doesn't exist.

https://www.codechef.com/problems/CSUM
*/
#include <stdlib.h>

enum Boolean
{
    FALSE,
    TRUE
};

int binarySearch(int *arr, int len, int key)
{
    int low = 0, high = len - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (key > arr[mid])
        {
            low = mid + 1;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int compareInts(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

enum Boolean sumPairExists(int *arr, int len, int key)
{
    qsort(arr, len, sizeof(arr[0]), compareInts);
    int idx = 0;
    while (idx < len)
    {
        int item = arr[idx];
        int compliment = key - arr[idx];

        if (binarySearch(arr, len, compliment) > 0) {
            return TRUE;
        }

        idx++;
    }

    return FALSE;    
}