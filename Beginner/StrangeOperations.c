/*
Given an array consisting of N integers, you have to do the following operation K times.

Find out the sum of all the elements in the array. Denote it by S. Insert an integer in the array strictly greater than S. Hence, size of the array will increase by one.
Thus, at the end of the K operations, the array will have N + K elements. Find out the smallest possible value of the last number inserted in the array. Since this number can be very large, you just have to tell whether it will be odd or even.

Input
The first line of each test file contains the number of test cases, T.
The description of the test cases follows this line. Each test case description consists of 2 lines.
The first line has the values of N and K, separated by a space.
The next line contains a single-space separated list of values of the elements in the array.
Output
For each test case, output a single line containing the answer to the problem.If the number is even print "even" and if the number is odd print "odd".
Constraints:
1 ≤ T ≤10
1 ≤ K ≤ 106
1 ≤ N ≤ 103
1 ≤ array element ≤ 109
Example
Sample Input:
1
2 3
5 7
Sample Output:
even

https://www.codechef.com/problems/UTMOPR
*/

enum IntType
{
    ODD,
    EVEN
};

enum IntType getIntType(long int num)
{
    return 0 == num % 2 ? EVEN : ODD;
}

long int arraySum(int *arr, int len)
{
    int idx = 0, sum = 0;
    while (idx < len)
    {
        sum = sum + arr[idx];
    }

    return sum;
}

enum IntType getIntTypeOfLastSmallestInserted(int *arr, int len, int numOfOperations)
{
    return numOfOperations > 1 ? EVEN : getIntType(arraySum(arr, len) + 1);
}