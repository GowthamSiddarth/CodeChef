/*
You are given four integers a, b, c and d. Determine if there's a rectangle such that the lengths of its sides are a, b, c and d (in any order).

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains four space-separated integers a, b, c and d.
Output
For each test case, print a single line containing one string "YES" or "NO".

Constraints
1 ≤ T ≤ 1,000
1 ≤ a, b, c, d ≤ 10,000
Subtasks
Subtask #1 (100 points): original constraints

Example
Input:

3
1 1 2 2
3 2 2 3
1 2 2 2

Output:

YES
YES
NO

https://www.codechef.com/problems/RECTANGL
*/
#include <stdio.h>

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isRectangle(int side1, int side2, int side3, int side4)
{
    return (side1 == side2 && side3 == side4) || (side2 == side3 && side1 == side4) || (side1 == side3 && side2 == side4) ? TRUE : FALSE;
}

int main()
{
    int side1 = 3;
    int side2 = 3;
    int side3 = 21;
    int side4 = 2;

    enum Boolean res = isRectangle(side1, side2, side3, side4);
    printf("%s\n", res ? "YES" : "NO");

    return 0;
}