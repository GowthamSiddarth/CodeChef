/*
In the 2-D world of Flatland, the Circles were having their sports day and wanted to end it with a nice formation. So, they called upon Mr. Sphere from Spaceland for help. Mr Sphere decides to arrange the Circles in square formations. He starts with N Circles and forms the largest possible square using these Circles. He then takes the remaining Circles and repeats the procedure. A square of side S requires S2 Circles to create.

Find the number of squares he will be able to form at the end of the process.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single integer N.
Output:
For each testcase, output a single integer denoting the number of squares.

Constraints
1≤T≤1000
1≤N≤1000
Sample Input:
2
85
114

Sample Output:
2
4

EXPLANATION:
Test case 1 : Mr Sphere forms a square of side 9 using 81 Circles and then forms a square of side 2 using the remaining 4.

https://www.codechef.com/problems/ICL1902
*/
#include <math.h>
#include <stdio.h>

int getNumOfSquaresFormed(int numOfCircles)
{
    int count = 0;
    while (numOfCircles > 0)
    {
        int integralSqrRoot = sqrt(numOfCircles);
        numOfCircles = numOfCircles - (integralSqrRoot * integralSqrRoot);
        count++;
    }

    return count;
}

int main()
{
    int numOfCircles = 114;
    int numOfSquaresFormed = getNumOfSquaresFormed(numOfCircles);

    printf("%d\n", numOfSquaresFormed);

    return 0;
}