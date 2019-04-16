/*
Three numbers A, B and C are the inputs. Write a program to find second largest among three numbers.

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains three integers A, B and C.

Output
Display the second largest among A, B and C.

Constraints
1 ≤ T ≤ 1000
1 ≤ A,B,C ≤ 1000000
Example
Input
3 
120 11 400
10213 312 10
10 3 450

Output

120
312
10

https://www.codechef.com/problems/FLOW017
*/
#include <stdio.h>

int getSecondLargest(int num1, int num2, int num3)
{
    if ((num1 > num2 && num1 < num3) || (num1 > num3 && num1 < num2))
    {
        return num1;
    }
    else if ((num2 > num1 && num2 < num3) || (num2 > num3 && num2 < num1))
    {
        return num2;
    }
    else if ((num3 > num1 && num3 < num2) || (num3 > num2 && num3 < num1))
    {
        return num3;
    }
}

int main()
{
    int num1 = 10;
    int num2 = 3;
    int num3 = 450;

    int secondLargest = getSecondLargest(num1, num2, num3);
    printf("%d\n", secondLargest);

    return 0;
}