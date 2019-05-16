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

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isRectangle(int side1, int side2, int side3, int side4)
{
    float avg12 = (side1 + side2) / 2;
    float avg23 = (side2 + side3) / 2;
    float avg34 = (side3 + side4) / 2;
    float avg41 = (side4 + side1) / 2;
    float avg1234 = (side1 + side2 + side3 + side4) / 4;

    return avg12 == avg1234 || avg23 == avg1234 || avg34 == avg1234 || avg41 == avg1234 ? TRUE : FALSE;
}