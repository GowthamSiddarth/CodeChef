/*
Write a program to obtain a number (N) from the user and display whether the number is a one digit number, 2 digit number, 3 digit number or more than 3 digit number

Input:
First line will contain the number N,
Output:
Print "1" if N is a 1 digit number.

Print "2" if N is a 2 digit number.

Print "3" if N is a 3 digit number.

Print "More than 3 digits" if N has more than 3 digits.

Constraints
0≤N≤1000000
Sample Input:
9
Sample Output:
1

https://www.codechef.com/problems/HOWMANY
*/

int getNumOfDigits(int num)
{
    int count = 0;
    while (num)
    {
        count++;
        num = num / 10;
    }

    return count;
}