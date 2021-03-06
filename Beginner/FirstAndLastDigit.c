/*
If Give an integer N . Write a program to obtain the sum of the first and last digit of this number.

Input
The first line contains an integer T, total number of test cases. Then follow T lines, each line contains an integer N.

Output
Display the sum of first and last digit of N.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 1000000
Example
Input
3 
1234
124894
242323

Output
5
5
5

https://www.codechef.com/problems/FLOW004
*/
#include <math.h>
#include <stdio.h>

int getFirstDigit(int num)
{
    return num / pow(10, (int)log10(num));
}

int getLastDigit(int num)
{
    return num % 10;
}

int main()
{
    int num = 242323;
    int firstDigit = getFirstDigit(num);
    int lastDigit = getLastDigit(num);

    printf("%d", firstDigit + lastDigit);

    return 0;
}