/*
You are given a string. Your task is to determine whether number of occurrences of some character in the string is equal to the sum of the numbers of occurrences of other characters in the string. 

Input
The first line of the input contains an integer T denoting the number of test cases. Each of the next T lines contains one string S consisting of lowercase latin letters.

Output
For each test case, output a single line containing "YES" if the string satisfies the condition given above or "NO" otherwise.

Constraints
1 ≤ T ≤ 1000
1 ≤ length of S ≤ 50
Subtasks
Subtask #1[28 points]: S contains no more than 2 different letters.
Subtask #2[72 points]: No additional conditions

Example
Input:
4
acab
zzqzqq
abc
kklkwwww
Output:
YES
YES
NO
YES

https://www.codechef.com/problems/LCH15JAB
*/
#define MAX_SIZE 51

#include <stdio.h>
#include <string.h>

enum Boolean
{
    FALSE,
    TRUE
};

int arraySum(int *arr, int len)
{
    int sum = 0;
    for (int idx = 0; idx < len; idx++)
    {
        sum = sum + arr[idx];
    }

    return sum;
}

enum Boolean checkIfAnyNumExistsEquToRemNums(int *arr, int len)
{
    int sum = arraySum(arr, len);
    for (int idx = 0; idx < len; idx++)
    {
        if (0 == arr[idx])
        {
            continue;
        }
        else if (arr[idx] == sum - arr[idx])
        {
            return TRUE;
        }
    }

    return FALSE;
}

enum Boolean pieceOfCake(char *s)
{
    int count[26] = {0};
    int idx = 0;
    while ('\0' != s[idx])
    {
        count[s[idx] - 'a']++;
        idx++;
    }

    return checkIfAnyNumExistsEquToRemNums(count, 26);
}

int main()
{
    char s[MAX_SIZE];
    memcpy(s, "kklkwwww", 9);

    enum Boolean res = pieceOfCake(s);
    printf("%s\n", res ? "YES" : "NO");

    return 0;
}