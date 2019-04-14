/*
If an Integer N, write a program to reverse the given number.

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

Output
Display the reverse of the given number N.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 100000
Example
Input
4
12345
31203
2123
2300
Output
54321
30213
3212
32

https://www.codechef.com/problems/FLOW007
*/
#include <stdio.h>

int reverse(int num)
{
    int sum = 0;
    while (num)
    {
        sum = sum * 10 + (num % 10);
        num = num / 10;
    }

    return sum;
}

int main()
{
    int num = 2123;
    int res = reverse(num);

    printf("%d\n", res);

    return 0;
}