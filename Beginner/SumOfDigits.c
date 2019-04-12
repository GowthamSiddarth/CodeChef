/*
You're given an integer N. Write a program to calculate the sum of all the digits of N.

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

Output
Calculate the sum of digits of N.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 1000000

https://www.codechef.com/problems/FLOW006
*/
#include<stdio.h>

int getSumOfDigitsOfNum(int num) {
    int sum = 0;
    while (num)
    {
        sum = num % 10 + sum;
        num = num / 10;
    }

    return sum;    
}

int main() {
    int num = 23;
    int sumOfDigits = getSumOfDigitsOfNum(num);
    printf("%d\n", sumOfDigits);

    return 0;
}