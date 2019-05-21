/*
Our little chef is fond of doing additions/sums in his free time. Today, he has an array A consisting of N positive integers and he will compute prefix and suffix sums over this array.

He first defines two functions prefixSum(i) and suffixSum(i) for the array as follows. The function prefixSum(i) denotes the sum of first i numbers of the array. Similarly, he defines suffixSum(i) as the sum of last N - i + 1 numbers of the array.

Little Chef is interested in finding the minimum index i for which the value prefixSum(i) + suffixSum(i) is the minimum. In other words, first you should minimize the value of prefixSum(i) + suffixSum(i), and then find the least index i for which this value is attained.

Since, he is very busy preparing the dishes for the guests, can you help him solve this problem?

Input
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains a single integer N denoting the number of integers in the array A.

The second line contains N space-separated integers A1, A2, ..., AN denoting the array A.

Output
For each test case, output a single line containing the answer.

Constraints
1 ≤ T ≤ 10
1 ≤ N, A[i] ≤ 105
Subtasks
Subtask #1 : (20 points) 1 ≤ N ≤ 100
Subtask #2 : (80 points) Original constraints
Example
Input:
2
3
1 2 3
4
2 1 3 1

Output:
1
2
Explanation
Example case 1. Let's calculate prefixSum(i) + suffixSum(i) for all indexes i in the sample case.

prefixSum(1) + suffixSum(1) = 1 + 6 = 7
prefixSum(2) + suffixSum(2) = 3 + 5 = 8
prefixSum(3) + suffixSum(3) = 6 + 3 = 9
The minimum value of the function is 7, which is attained at index 1, so the answer would be 1.

Example case 2. Let's calculate prefixSum(i) + suffixSum(i) for all indexes i in the sample case.

prefixSum(1) + suffixSum(1) = 2 + 7 = 9
prefixSum(2) + suffixSum(2) = 3 + 5 = 8
prefixSum(3) + suffixSum(3) = 6 + 4 = 10
prefixSum(4) + suffixSum(4) = 7 + 1 = 8
The minimum value of the function is 8, which is achieved for indices 2 and 4. The minimum of these two indices 2, 4 is index 2. Hence, the answer will be 2.

https://www.codechef.com/problems/CHEFSUM
*/
#include <malloc.h>
#include <limits.h>

long int arraySum(int *arr, int len)
{
    return 0 == len ? 0 : arr[len - 1] + arraySum(arr, len - 1);
}

long int *getReverseCumulativeSums(int *arr, int len)
{
    long int reverseCumulativeSum = arraySum(arr, len);
    long int *reverseCumulativeSums = (long int *)malloc(sizeof(long int) * len);
    for (int idx = 0; idx < len; idx++)
    {
        reverseCumulativeSums[idx] = reverseCumulativeSum - (idx > 0 ? arr[idx - 1] : 0);
    }

    return reverseCumulativeSums;
}

int findMinIdxForPrefixAndSuffixSum(int *arr, int len)
{
    long int *reverseCumulativeSums = getReverseCumulativeSums(arr, len);
    long int minSum = INT_MAX, minIdx, prefixSum = 0, suffixSum;

    for (int idx = 0; idx < len; idx++)
    {
        prefixSum = prefixSum + arr[idx];
        suffixSum = reverseCumulativeSums[idx];
        if (prefixSum + suffixSum < minSum)
        {
            minSum = prefixSum + suffixSum;
            minIdx = idx;
        }
    }

    return minIdx;
}