/*
Given a binary number (of N bits) X. Find the highest power of 2 that divides this number.

Note: If the binary number is "100" then the highest power of 2 that divides it is 2 (as 22 = 4)
Input:
The first line contains N the number of bits in the number
The next line contains a binary number of N bits
Output:
The first and only line contains the max power of 2 that divides the given number
Constraints:
1≤N≤105
1≤X
Sample Input:
5
10100
Sample Output:
2

https://www.codechef.com/problems/MAX2
*/

int getMaxPowOf2DividingNum(int num)
{
    int count = 0;
    while (1 != (num & 1))
    {
        count++;
        num = num >> 1;
    }
    
    return count;
}