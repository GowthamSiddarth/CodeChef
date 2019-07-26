/*
Chef decided to find the connections with all of his friends in an unnamed social network. He calls a user of the social network his friend if there is a common substring of the string "chef" and the nickname of that user with length ≥ 2.

Given a list of users of the social network, compute the number of Chef's friends.

Input
The first line of the input contains a single integer N denoting the number of users in the social network.
N lines follow. Each of these lines contains a single string u denoting the nickname of one user.
Output
Print a single line containing one integer — the number of Chef's friends.

Constraints
1 ≤ N ≤ 5,000
3 ≤ |u| ≤ 20
each character of each user's nickname is either a lowercase English letter ('a'-'z') or '.'
the first character of each user's nickname is a lowercase English letter
Subtasks
Subtask #1 (100 points): original constraints

Example
Input:

4
gennady.korotkevich
kefaa
fhlasek
chemthan

Output:

3
Explanation
gennady.korotkevich is a friend to Chef because he has "ch" at the end of his nickname, which is also a substring of "chef" with length 2
the common substring with kefaa is "ef" and the common substring with chemthan is "che"

https://www.codechef.com/problems/FRK
*/
#include <malloc.h>
#include <string.h>
#include <stdio.h>

int *getMaxPrefixSubstrArr(char *str)
{
    int left = 0, right = 0, idx = 1, len = strlen(str);
    int *maxPrefixSubstrArr = (int *)malloc(sizeof(int) * len);
    while ('\0' != str[idx])
    {
        if (idx > right)
        {
            left = right = idx;

            while ('\0' != str[right] && str[right - left] == str[right])
            {
                right++;
            }

            maxPrefixSubstrArr[idx] = right - left;
            right--;
        }
        else
        {
            int k = idx - left;
            if (maxPrefixSubstrArr[k] < right - idx + 1)
            {
                maxPrefixSubstrArr[idx] = maxPrefixSubstrArr[k];
            }
            else
            {
                left = idx;
                while ('\0' != str[right] && str[right - left] == str[right])
                {
                    right++;
                }

                maxPrefixSubstrArr[idx] = right - left;
                right--;
            }
        }

        idx++;
    }

    return maxPrefixSubstrArr;
}

int indexOf(char *text, char *pattern)
{
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int concatenatedLen = textLen + patternLen + 1;
    char *concatenatedStr = (char *)calloc(concatenatedLen + 1, sizeof(char));

    int destIdx = 0, srcIdx = 0;
    while ('\0' != pattern[srcIdx])
    {
        concatenatedStr[destIdx] = pattern[srcIdx];
        srcIdx++;
        destIdx++;
    }

    concatenatedStr[destIdx] = '$';
    destIdx++;
    srcIdx = 0;
    while ('\0' != text[srcIdx])
    {
        concatenatedStr[destIdx] = text[srcIdx];
        srcIdx++;
        destIdx++;
    }

    int *maxPrefixSubstrArr = getMaxPrefixSubstrArr(concatenatedStr);
    for (int idx = 0; idx < concatenatedLen; idx++)
    {
        if (maxPrefixSubstrArr[idx] == patternLen)
        {
            free(maxPrefixSubstrArr);
            free(concatenatedStr);
            return idx - patternLen - 1;
        }
    }

    free(maxPrefixSubstrArr);
    free(concatenatedStr);
    return -1;
}

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isFriendToChef(char *nickName, char substrings[NUM_OF_SUBSTR][MAX_LEN_SUBSTR])
{
    for (int idx = 0; idx < NUM_OF_SUBSTR; idx++)
    {
        int f = indexOf(nickName, substrings[idx]);
        if (indexOf(nickName, substrings[idx]) >= 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}