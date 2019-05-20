/*
Trans bought a calculator at creatnx's store. Unfortunately, it is fake. It has many bugs. One of them is adding two numbers without carrying. Example expression: 12 + 9 will have result 11 in his calculator. Given an expression in the form a + b, please output result from that calculator.

 

Input
The first line contains an integer T denote the number of test cases. Each test case contains two integers a, b in a single line.

 

Output
Each test case, print answer in a single line.

 

Constraints
1 ≤ T ≤ 100
1 ≤ a, b ≤ 109
Subtasks:

Subtask #1 (30 points): 1 ≤ a, b ≤ 9
Subtask #2 (70 points): original constrains
 

Example
Input:
2
12 9
25 25

Output:
11
40

https://www.codechef.com/problems/BUGCAL
*/
#include <math.h>

int buggySum(int a, int b)
{
    int sum = 0, placeValue = 0;
    while (a && b)
    {
        sum = sum + pow(10, placeValue) * (((a % 10) + (b % 10)) % 10);
        a /= 10;
        b /= 10;
        placeValue++;
    }
    
    return sum;
}