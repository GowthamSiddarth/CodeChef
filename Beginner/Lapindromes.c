/*
Lapindrome is defined as a string which when split in the middle, gives two halves having the same characters and same frequency of each character. If there are odd number of characters in the string, we ignore the middle character and check for lapindrome. For example gaga is a lapindrome, since the two halves ga and ga have the same characters with same frequency. Also, abccab, rotor and xyzxy are a few examples of lapindromes. Note that abbaab is NOT a lapindrome. The two halves contain the same characters but their frequencies do not match.
Your task is simple. Given a string, you need to tell if it is a lapindrome.

Input:
First line of input contains a single integer T, the number of test cases.
Each test is a single line containing a string S composed of only lowercase English alphabet.
Output:
For each test case, output on a separate line: "YES" if the string is a lapindrome and "NO" if it is not.
Constraints:
1 ≤ T ≤ 100
2 ≤ |S| ≤ 1000, where |S| denotes the length of S
Example:
Input:
6
gaga
abcde
rotor
xyzxy
abbaab
ababc


Output:
YES
NO
YES
YES
NO
NO

https://www.codechef.com/problems/LAPIN
*/
#define NUM_OF_ALPHABETS 26

enum Boolean
{
    FALSE,
    TRUE
};

int mapLowerCaseCharToIdx(char ch)
{
    return ch - 'a';
}

enum Boolean isLapindrome(char *string)
{
    int idx = 0, fastIdx = 0;
    int charCount[NUM_OF_ALPHABETS] = {0};

    while ('\0' != string[fastIdx] && '\0' != string[fastIdx + 1])
    {
        int charCountIdx = mapLowerCaseCharToIdx(string[idx]);
        charCount[charCountIdx]++;

        idx++;
        fastIdx = fastIdx + 2;
    }

    if ('\0' != string[fastIdx] && '\0' == string[fastIdx + 1])
    {
        idx++;
    }

    while ('\0' != string[idx])
    {
        int charCountIdx = mapLowerCaseCharToIdx(string[idx]);
        charCount[charCountIdx]--;
        idx++;
    }

    idx = 0;
    while (idx < NUM_OF_ALPHABETS && 0 == charCount[idx])
    {
        idx++;
    }

    return NUM_OF_ALPHABETS == idx ? TRUE : FALSE;
}