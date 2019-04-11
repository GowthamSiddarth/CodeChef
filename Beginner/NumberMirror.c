/*
Problem Statement
Write a program that accepts a number, n, and outputs the same.

Input
The only line contains a single integer.

Output
Output the answer in a single line.

Constraints
0 ≤ n ≤ 105
Sample Input
123
Sample Output
123

https://www.codechef.com/problems/START01
*/
#include<stdio.h>

int mirror(int num) {
    return num;
}

int main() {
    int num = 123;
    int mirrorNumber = mirror(num);
    printf("%d\n", mirrorNumber);
    
    return 0;
}