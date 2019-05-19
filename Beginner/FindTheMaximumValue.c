/*
The Chef had a box with N numbers arranged inside it: A1, A2, ..., AN. He also had the number N at the front, so that he knows how many numbers are in it. That is, the box actually contains N+1 numbers. But in his excitement due the ongoing IOI, he started dancing with the box in his pocket, and the N+1 numbers got jumbled up. So now, he no longer knows which of the N+1 numbers is N, and which the actual numbers are.

He wants to find the largest of the N numbers. Help him find this.

Input
The first line of the input contains an integer T, denoting the number of test cases. The description of each testcase follows.
Each of the next T lines will contain N and N numbers, but it is not guaranteed that N is the first number.
Output
For each test case, output a single line containing the maximum value of the N numbers in that testcase.

Constraints
1 ≤ T ≤ 100
1 ≤ N ≤ 50
1 ≤ Ai ≤ 109
Example
Input:
3
1 2 1
3 1 2 8
1 5 1 4 3 2

Output:
1
8
4
Explanation
Test case 1:

N = 2 and the numbers are {1, 1}. The maximum among these 2 numbers is 1, and hence the output is 1.

Test case 2:

N = 3 and the numbers are {1, 2, 8}. The maximum among these 3 numbers is 8, and hence the output is 8.

Test case 3:

N = 5 and the numbers are {1, 1, 4, 3, 2}. The maximum among these 5 numbers is 4, and hence the output is 4.

https://www.codechef.com/problems/LOSTMAX
*/
#include <math.h>
#include <malloc.h>
#include <stdio.h>

struct IntArray
{
    int *arr, len;
};

int parseIntFromSubstr(char *str, int start, int end)
{
    int idx = end, num = 0;
    while (idx >= start)
    {
        num = num + (str[idx] - '0') * pow(10, end - idx);
        idx--;
    }

    return num;
}

int getNumOfWhitespaces(char *line)
{
    int count = 0, idx = 0;
    while ('\0' != line[idx])
    {
        count = count + (' ' == line[idx]);
        idx++;
    }

    return count;
}

struct IntArray *initIntArray(int length)
{
    struct IntArray *intArray = (struct IntArray *)malloc(sizeof(struct IntArray));
    intArray->len = length;
    intArray->arr = (int *)malloc(sizeof(int) * intArray->len);

    return intArray;
}

struct IntArray *parseIntArr(char *lineInput)
{
    int numOfInts = getNumOfWhitespaces(lineInput) + 1;
    struct IntArray *intArray = initIntArray(numOfInts);

    int start = 0, end = 0, arrIdx = 0;
    while ('\0' != lineInput[end])
    {
        end = start + 1;
        while ('\0' != lineInput[end] && ' ' != lineInput[end])
        {
            end++;
        }

        int numAtCurrIdx = parseIntFromSubstr(lineInput, start, end - 1);
        intArray->arr[arrIdx] = numAtCurrIdx;
        arrIdx++;

        while ('\0' != lineInput[end] && ' ' == lineInput[end])
        {
            end++;
        }

        start = end;
    }

    return intArray;
}