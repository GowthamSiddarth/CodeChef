/*
Write a program to check whether a triangle is valid or not, when the three angles of the triangle are the inputs. A triangle is valid if the sum of all the three angles is equal to 180 degrees.

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains three angles A, B and C of triangle separated by space.

Output
Display 'YES' or 'NO' if the triangle is Valid or not respectively.

Constraints
1 ≤ T ≤ 1000
1 ≤ A,B,C ≤ 180
Example
Input

3 
40 40 100
45 45 90
180 1 1
Output

YES
YES
NO

https://www.codechef.com/problems/FLOW013
*/
#include <stdio.h>

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isValidTriangle(int angle1, int angle2, int angle3)
{
    return 180 == angle1 + angle2 + angle3 ? TRUE : FALSE;
}

int main()
{
    int angle1 = 178, angle2 = 1, angle3 = 1;
    enum Boolean res = isValidTriangle(angle1, angle2, angle3);

    switch (res)
    {
    case FALSE:
        printf("NO\n");
        break;
    case TRUE:
        printf("YES\n");
        break;
    }

    return 0;
}