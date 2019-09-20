/*
Vishal loves running. He often visits his favourite Nehru Park and runs for very long distances. On one such visit he found that the number of girls in the park was unusually high. Now he wants to use this as an opportunity to impress a large number of girls with his awesome speed.

The track on which he runs is an N kilometres long straight path. There are ai girls standing within the ith kilometre of this path. A girl will be impressed only if Vishal is running at his maximum speed when he passes by her. But he can run at his best speed only for a single continuous stretch of K kilometres. Now Vishal wants to know what is the maximum number of girls that he can impress.

Input
First line of the input contains the number of testcases T.

For each test case,

First line contains two space-separated integers N and K, the length of the track and the maximum distance he can run at his best speed.

Second line contains N space-separated integers, the number of girls within each kilometre of the track.

Output
For each test case print one line containing an integer, denoting the maximum number of girls Vishal can impress.

Constraints
1≤T≤10
1≤K≤N≤100

1≤ai≤100

Sample Input
1
7 2
2 4 8 1 2 1 8
Sample Output
12

Explanation
He can impress 4+8=12 girls if he runs at his best speed between the 2nd and the 3rd kilometre, inclusive.

https://www.codechef.com/problems/PROC18A
*/
#include <limits.h>

int getSumOfSubArr(int *arr, int start, int end)
{
    int sum = 0;
    for (int idx = start; idx < end; idx++)
    {
        sum = sum + arr[idx];
    }

    return sum;
}

int getMaxNumOfGirlsVishalCanImpress(int *numOfGirlsForEveryKm, int lengthOfTrack, int maxDistWithMaxSpeed)
{
    int start = 0, end = maxDistWithMaxSpeed, prevSum = 0, maxSum = INT_MIN;
    while (end < lengthOfTrack)
    {
        int currSum = 0 == prevSum ? getSumOfSubArr(numOfGirlsForEveryKm, start, end) : prevSum + numOfGirlsForEveryKm[end] - numOfGirlsForEveryKm[start - 1];
        if (currSum > maxSum)
        {
            maxSum = currSum;
        }

        prevSum = currSum;
        start++;
        end++;
    }

    return maxSum;
}