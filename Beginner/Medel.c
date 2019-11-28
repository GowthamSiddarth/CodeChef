/*
You are given a sequence A1,A2,…,AN of distinct integers. While the sequence contains at least three elements, look at its first three elements, find the median among these elements and delete it. What will the final sequence be?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.
Output
For each test case, print a single line containing K space-separated integers, where K is the length of the final sequence. For each valid i, the i-th of these integers should be the i-th element of the final sequence.
Constraints
1≤T≤74
3≤N≤19
1≤Ai≤109 for each valid i
Example Input
2
3
2 5 3
10
38 9 102 10 96 7 46 28 88 13
Example Output
2 5 
102 7 
Explanation
Example case 1: We remove the element 3 because it is the median of (2,5,3). The final sequence is (2,5).

https://www.codechef.com/problems/MDL
*/
#include <limits.h>

struct MinMax
{
    int min, max;
};

struct MinMax getMinMax(int *arr, int len)
{
    int min = INT_MAX, max = INT_MIN;
    for (int idx = 0; idx < len; ++idx)
    {
        if (arr[idx] > max)
        {
            max = arr[idx];
        }

        if (arr[idx] < min)
        {
            min = arr[idx];
        }
    }

    struct MinMax minMax = {min, max};
    return minMax;
}
