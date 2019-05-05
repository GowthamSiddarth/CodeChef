/*
Two integers A and B are the inputs. Write a program to find GCD and LCM of A and B.

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer A and B.

Output
Display the GCD and LCM of A and B separated by space respectively.

Constraints
1 ≤ T ≤ 1000
1 ≤ A,B ≤ 1000000
Example
Input
3 
120 140
10213 312
10 30

Output

20 840
1 3186456
10 30

https://www.codechef.com/problems/FLOW016
*/
#include <stdio.h>

int getGCDOfTwoNums(int num1, int num2)
{
    return 0 == num2 ? num1 : getGCDOfTwoNums(num2, num1 % num2);
}

long int getLCMofTwoNums(int num1, int num2, int gcd)
{
    return ((long)num1 * num2) / gcd;
}

int main()
{
    int num1 = 10, num2 = 30;
    int gcd = getGCDOfTwoNums(num1, num2);
    long int lcm = getLCMofTwoNums(num1, num2, gcd);

    printf("%d %ld\n", gcd, lcm);
    return 0;
}