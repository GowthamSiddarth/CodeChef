/*
You are asked to calculate factorials of some small positive integers.

Input
An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.

Output
For each integer n given at input, display a line with the value of n!

Example
Sample input:
4
1
2
5
3
Sample output:

1
2
120
6

https://www.codechef.com/problems/FCTRL2
*/
#define MAX_SIZE 158

#include <stdio.h>

struct SmallFactorial
{
    int arr[MAX_SIZE];
    int numOfDigits;
};

void printSmallFactorial(struct SmallFactorial smallFactorial)
{
    for (int i = smallFactorial.numOfDigits - 1; i >= 0; i--)
    {
        printf("%d", smallFactorial.arr[i]);
    }
    printf("\n");
}

void multiply(int num, struct SmallFactorial *factorial)
{
    int digitIdx = 0, carry = 0;
    while (digitIdx < factorial->numOfDigits)
    {
        int temp = factorial->arr[digitIdx] * num + carry;
        factorial->arr[digitIdx] = temp % 10;
        carry = temp / 10;
        digitIdx++;
    }

    while (carry)
    {
        factorial->arr[digitIdx] = carry % 10;
        carry = carry / 10;
        digitIdx++;
    }

    factorial->numOfDigits = digitIdx;
}

struct SmallFactorial getFactorial(int num)
{
    struct SmallFactorial smallFactorial;
    smallFactorial.arr[0] = 1;
    smallFactorial.numOfDigits = 1;

    for (int i = 2; i <= num; i++)
    {
        multiply(i, &smallFactorial);
    }

    return smallFactorial;
}

int main()
{
    int num = 13;
    struct SmallFactorial smallFactorial = getFactorial(num);
    printSmallFactorial(smallFactorial);

    return 0;
}