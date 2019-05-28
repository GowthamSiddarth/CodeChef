/*
Alice has quarreled with Berta recently. Now she doesn't want to have anything in common with her!

Recently, they've received two collections of positive integers. The Alice's integers were A1, A2, ..., AN, while Berta's were B1, B2, ..., BM.

Now Alice wants to throw away the minimal amount of number from her collection so that their collections would have no common numbers, i.e. there won't be any number which is present in both collections. Please help Alice to find the minimal amount of numbers she would need to throw away.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains two space-separated integer numbers N and M denoting the amount of numbers in Alice's and Berta's collections respectively.

The second line contains N space-separated integers A1, A2, ..., AN denoting the numbers of Alice.

The third line contains M space-separated integers B1, B2, ..., BM denoting the numbers of Berta.

Output
For each test case, output a single line containing the minimal amount of numbers Alice needs to throw away from her collection so that she wouldn't have any numbers in common with Berta.

Constraints
1 ≤ Ai, Bi ≤ 106
All numbers are distinct within a single girl's collection.
Subtasks
Subtask #1 (47 points): T = 25, 1 ≤ N, M ≤ 1000
Subtask #2 (53 points): T = 5, 1 ≤ N, M ≤ 100000
Example
Input:
2
3 4
1 2 3
3 4 5 6
3 3
1 2 3
4 5 6

Output:
1
0
Explanation
Example case 1. If Alice throws away the number 3 from her collection, she would obtain {1, 2} which is disjoint with {3, 4, 5, 6}.

Example case 2. Girls don't have any number in common initially. So there is no need to throw away any number.

https://www.codechef.com/problems/NOTINCOM
*/

#include <stdlib.h>
#include <stdio.h>

int compareInts(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

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

int intersection(int *arr1, int len1, int *arr2, int len2)
{
    qsort(arr1, len1, sizeof(int), compareInts);
    qsort(arr2, len2, sizeof(int), compareInts);

    int count = 0;
    for (int idx = 0; idx < len1; idx++)
    {
        count = count + (binarySearch(arr2, len2, arr1[idx]) >= 0 ? 1 : 0);
    }

    return count;
}

int getNumOfCommonItems(int *arr1, int len1, int *arr2, int len2)
{
    return len1 <= len2 ? intersection(arr2, len2, arr1, len1) : intersection(arr1, len1, arr2, len2);
}

int main()
{
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6, 2, 1, 0};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    int res = getNumOfCommonItems(arr1, len1, arr2, len2);
    printf("%d\n", res);

    return 0;
}