/*
Chef had a sequence of positive integers with length N+K. He managed to calculate the arithmetic average of all elements of this sequence (let's denote it by V), but then, his little brother deleted K elements from it. All deleted elements had the same value.

Chef still knows the remaining N elements — a sequence A1,A2,…,AN. Help him with restoring the original sequence by finding the value of the deleted elements or deciding that there is some mistake and the described scenario is impossible.

Note that the if it is possible for the deleted elements to have the same value, then it can be proven that it is unique. Also note that this value must be a positive integer.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, K and V.
The second line contains N space-separated integers A1,A2,…,AN.
Output
For each test case, print a single line containing one integer — the value of the deleted elements, or −1 if there is a mistake.

Constraints
1≤T≤100
1≤N,K≤100
1≤V≤105
1≤Ai≤105 for each valid i
Subtasks
Subtask #1 (100 points): original constraints

Example Input
3
3 3 4
2 7 3
3 1 4
7 6 5
3 3 4
2 8 3
Example Output
4
-1
-1

https://www.codechef.com/problems/AVG
*/
#include <stdio.h>

int sumOfIntArray(int *arr, int len)
{
    int sum = 0;
    for (int idx = 0; idx < len; idx++)
    {
        sum = sum + arr[idx];
    }

    return sum;
}

int getValueOfDeletedItems(int *residualItems, int numOfResidualItems, int numOfDeletedItems, int meanOfAllItems)
{
    int sumOfAllItems = (numOfResidualItems + numOfDeletedItems) * meanOfAllItems;
    int sumOfResidualItems = sumOfIntArray(residualItems, numOfResidualItems);
    int sumOfDeletedItems = sumOfAllItems - sumOfResidualItems;

    return sumOfDeletedItems > 0 && 0 == sumOfDeletedItems % numOfDeletedItems ? sumOfDeletedItems / numOfDeletedItems : -1;
}

int main()
{
    int numOfResidualItems = 3, numOfDeletedItems = 1, meanOfAllItems = 4;
    int residualItems[] = {7, 6, 5};

    int valueOfDeletedItems = getValueOfDeletedItems(residualItems, numOfResidualItems, numOfDeletedItems, meanOfAllItems);
    printf("%d\n", valueOfDeletedItems);

    return 0;
}