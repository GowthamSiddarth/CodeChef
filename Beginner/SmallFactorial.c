/*
Write a program to find the factorial value of any number entered by the user.

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

Output
Display the factorial of the given number N .

Constraints
1 ≤ T ≤ 1000
0 ≤ N ≤ 20
Example
Input
3 
3 
4
5

Output

6
24
120

https://www.codechef.com/problems/FLOW018
*/
#define MAX_SIZE 19

struct SmallFactorial
{
    int factorial[MAX_SIZE];
    int numOfDigits;
};
