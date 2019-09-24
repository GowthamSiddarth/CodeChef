/*
Danya gave integers a, b and n to Archi. Archi wants to compare an and bn. Help Archi with this task.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers a, b and n.
Output
For each test case, print a single line containing one integer: 1 if an>bn, 2 if an<bn or 0 if an=bn.

Constraints
1≤T≤1,000
|a|,|b|≤109
1≤n≤109
Example Input
2
3 4 5
-3 2 4
Example Output
2
1
Explanation
Example case 1: an=243 and bn=1024.

Example case 2: an=81 and bn=16.

https://www.codechef.com/problems/NUMCOMP
*/
#include <stdio.h>

enum Comparsion
{
    ZERO,
    ONE,
    TWO
};

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isEven(int num)
{
    return 0 == num % 2 ? TRUE : FALSE;
}

int abs(int num)
{
    return num < 0 ? -num : num;
}

enum Comparsion compare(int a, int b, int n)
{
    if (a == b)
    {
        return ZERO;
    }
    else if (a >= 0 && b >= 0)
    {
        return a > b ? ONE : TWO;
    }
    else if (a < 0 && b < 0)
    {
        return isEven(n) ? abs(a) > abs(b) ? ONE : TWO : abs(a) < abs(b) ? ONE : TWO;
    }
    else
    {
        return isEven(n) ? abs(a) > abs(b) ? ONE : abs(a) < abs(b) ? TWO : ZERO : a > b ? ONE : TWO;
    }
}

int main()
{
    int a = -3, b = 2, n = 4;
    enum Comparsion res = compare(a, b, n);

    printf("%d\n", res);
    return 0;
}