/*
You are given an array with N integers: A[1],A[2],…,A[N] (where N is even). You are allowed to permute the elements however you want. Say, after permuting the elements, you end up with the array A′[1],A′[2],…,A′[N]. Your goal is to maximize the following sum:

|A′[1]−A′[2]| + |A′[3]−A′[4]| + ... + |A′[N−1]−A′[N]|
Here, |x| denotes the absolute value of x.

You have to print the maximum sum achievable.

Input
The first line contains T, the number of test cases.
Each test case starts with an integer N in the first line.
The second line of each test case contains N space separated integers, denoting the values of array A.
Output
For each test case, output the maximum sum achievable in a new line.

Constraints
1≤T≤105
1≤N≤105
N is even
|A[i]|≤109
Sum of N over all test cases ≤2∗105
Example Input 1
1
4
1 -3 2 -3
Example Output 1
9
Explanation 1
The original array is {1,−3,2,−3}. Suppose you permute it and get the array {2,1,−3,−3}. Then the corresponding sum would be |2−1| + |−3−(−3)|=1+0=1.

But suppose you permute it differently and get the array {−3,2,1,−3}. Then the corresponding sum would be |−3−2| + |1−(−3)|=5+4=9. You can check that you cannot do any better, and hence the answer is 9.

https://www.codechef.com/problems/NOMATCH
*/
#include <stdlib.h>

int compareInts(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

long int getMaxSumWithConsecutiveSubtraction(int *array, int len)
{
    qsort(array, len, sizeof(array[0]), compareInts);
    long int maxSum = 0;
    int left = 0, right = len - 1;
    while (left < right)
    {
        maxSum = maxSum + (array[right] - array[left]);
        left++;
        right--;
    }

    return maxSum;
}