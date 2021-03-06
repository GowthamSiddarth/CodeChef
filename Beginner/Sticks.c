/*
Chef and his little brother are playing with sticks. They have total N sticks. Length of i-th stick is Ai. Chef asks his brother to choose any four sticks and to make a rectangle with those sticks its sides. Chef warns his brother to not to break any of the sticks, he has to use sticks as a whole. Also, he wants that the rectangle formed should have the maximum possible area among all the rectangles that Chef's brother can make.

Chef's little brother takes this challenge up and overcomes it. Can you also do so? That is, you have to tell whether it is even possible to create a rectangle? If yes, then you have to tell the maximum possible area of rectangle.

Input
The first line contains a single integer T denoting the number of test-cases. T test cases follow.

The first line of each test case contains a single integer N denoting the number of sticks.

The second line of each test case contains N space-separated integers A1, A2, ..., AN denoting the lengths of sticks.

Output
For each test case, output a single line containing an integer representing the maximum possible area for rectangle or -1 if it's impossible to form any rectangle using the available sticks.

Constraints
1 ≤ T ≤ 100
1 ≤ N ≤ 103
1 ≤ sum of N's over all test-cases in a single test file ≤ 103
1 ≤ Ai ≤ 103
Example
Input:
2
5
1 2 3 1 2
4
1 2 2 3

Output:
2
-1
Explanation
Example case 1. Chef's brother can choose sticks of lengths 1, 2, 1, 2. He can create a rectangle with area 1 * 2 = 2.

Example case 2. It's impossible to choose 4 sticks so that they form a rectangle.

https://www.codechef.com/problems/STICKS
*/
#include <stdlib.h>
#include <stdio.h>

int compareInts(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

int getAreaOfLargestRectangle(int *sticksLengths, int numOfSticks)
{
    qsort(sticksLengths, numOfSticks, sizeof(sticksLengths[0]), compareInts);

    int idx = numOfSticks - 2, largestSide = sticksLengths[numOfSticks - 1];
    while (idx >= 0)
    {
        if (largestSide == sticksLengths[idx])
        {
            idx--;
            break;
        }
        else
        {
            largestSide = sticksLengths[idx];
            idx--;
        }
    }

    if (idx < 0)
    {
        return -1;
    }

    int smallestSide = sticksLengths[idx];
    idx--;
    while (idx >= 0)
    {
        if (smallestSide == sticksLengths[idx])
        {
            break;
        }
        else
        {
            smallestSide = sticksLengths[idx];
            idx--;
        }
    }

    return idx < 0 ? -1 : largestSide * smallestSide;
}

int main()
{
    int sticksLengths[] = {1, 2, 2, 3};
    int numOfSticks = sizeof(sticksLengths) / sizeof(sticksLengths[0]);

    int areaOfLargestRectangle = getAreaOfLargestRectangle(sticksLengths, numOfSticks);
    printf("%d\n", areaOfLargestRectangle);

    return 0;
}