/*
Write a program, which takes an integer N and if the number is less than 10 then display "What an obedient servant you are!" otherwise print "-1".

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

Output
Output the given string or -1 depending on conditions.

Constraints
1 ≤ T ≤ 1000
-20 ≤ N ≤ 20
Example
Input
3 
1
12
-5
Output
What an obedient servant you are!
-1
What an obedient servant you are!

https://www.codechef.com/problems/FLOW008
*/
#define MAX_LENGTH 34

#include <string.h>

void setMessageForServant(int num, char *message)
{
    memcpy(message, num < 10 ? "What an obedient servant you are!" : "-1", num < 10 ? MAX_LENGTH : 3);
}