/*
You are given a string s of length 8 consisting solely of '0's and '1's. Assume that the characters of the string are written in a circular fashion. You need to find the number of 0-1 or 1-0 transitions that one has to make while making a single traversal over the string. ie. start from any character and go circularly until you get back to the same character, and find the number of transitions that you made. The string is said to be said to be uniform if there are at most two such transitions. Otherwise, it is called non-uniform.

Given the string s, tell whether the string is uniform or not.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The only line of input contains the string s.

Output
For each test case, output "uniform" if the given string is uniform and "non-uniform" otherwise.

Constraints
1 ≤ T ≤ 256
Length of s is 8
Example
Input
4
00000000
10101010
10000001
10010011

Output
uniform
non-uniform
uniform
non-uniform
Explanation
The number of transitions are 0, 8, 2 and 4 for the respective cases. So, the first and third one are uniform while the second and fourth one are non-uniform.

https://www.codechef.com/problems/STRLBP
*/
#define STRING_LENGTH 8

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isStateChanged(char prevChar, char currChar)
{
    return 0 != currChar - prevChar ? TRUE : FALSE;
}

enum Boolean isUniformString(char *binaryString)
{
    int numOfComparisions = 0, currIdx = 1, prevIdx = currIdx - 1, numOfStateChanges = 0;
    while (numOfComparisions < STRING_LENGTH)
    {
        if (isStateChanged(prevIdx, currIdx))
        {
            numOfStateChanges++;
        }

        prevIdx = currIdx;
        currIdx = (currIdx + 1) % STRING_LENGTH;

        numOfComparisions++;
    }

    return numOfStateChanges <= 2 ? TRUE : FALSE;
}