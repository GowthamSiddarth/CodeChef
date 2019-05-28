/*
Nitika was once reading a history book and wanted to analyze it. So she asked her brother to create a list of names of the various famous personalities in the book. Her brother gave Nitika the list. Nitika was furious when she saw the list. The names of the people were not properly formatted. She doesn't like this and would like to properly format it.

A name can have at most three parts: first name, middle name and last name. It will have at least one part. The last name is always present. The rules of formatting a name are very simple:

Only the first letter of each part of the name should be capital.
All the parts of the name except the last part should be represented by only two characters. The first character should be the first letter of the part and should be capitalized. The second character should be ".".
Let us look at some examples of formatting according to these rules:

gandhi -> Gandhi
mahatma gandhI -> M. Gandhi
Mohndas KaramChand ganDhi -> M. K. Gandhi
Input
The first line of the input contains an integer T denoting the number of test cases.

The only line of each test case contains the space separated parts of the name.

Output
For each case, output the properly formatted name.

Constraints
1 ≤ T ≤ 100
2 ≤ Length of each part of the name ≤ 10
Each part of the name contains the letters from lower and upper case English alphabets (i.e. from 'a' to 'z', or 'A' to 'Z')
Subtasks
Subtask #1 (40 points)

There is exactly one part in the name.
Subtask #2 (60 points)

Original constraints.
Example
Input:
3
gandhi
mahatma gandhI
Mohndas KaramChand gandhi

Output:
Gandhi 
M. Gandhi 
M. K. Gandhi 
Explanation
The examples are already explained in the problem statement.

https://www.codechef.com/problems/NITIKA
*/
#define MAX_ABBR_NAME_SIZE 17

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isFirstCharInName(char *fullName, int charPos)
{
    return 0 == charPos || ' ' == fullName[charPos - 1] ? TRUE : FALSE;
}

char toUpperCase(char lowerCaseChar)
{
    return lowerCaseChar >= 'a' && lowerCaseChar <= 'z' ? lowerCaseChar - ('a' - 'A') : lowerCaseChar;
}

char toLowerCase(char upperCaseChar)
{
    return upperCaseChar >= 'A' && upperCaseChar <= 'Z' ? upperCaseChar + ('a' - 'A') : upperCaseChar;
}

char *abbreviateFullName(char *fullName)
{
    char *abbrFullName = (char *)malloc(sizeof(char) * MAX_ABBR_NAME_SIZE);
    int fullNameIdx = 0, abbrFullNameIdx = 0;
    while ('\0' != fullName[fullNameIdx])
    {
        int firstCharPos = abbrFullNameIdx;
        abbrFullName[abbrFullNameIdx] = toUpperCase(fullName[fullNameIdx]);
        fullNameIdx++;
        abbrFullNameIdx++;

        while ('\0' != fullName[fullNameIdx] && ' ' != fullName[fullNameIdx])
        {
            abbrFullName[abbrFullNameIdx] = toLowerCase(fullName[fullNameIdx]);
            fullNameIdx++;
            abbrFullNameIdx++;
        }

        if (' ' == fullName[fullNameIdx])
        {
            abbrFullName[firstCharPos + 1] = '.';
            abbrFullName[firstCharPos + 2] = ' ';
            fullNameIdx++;
            abbrFullNameIdx = firstCharPos + 3;
        }
    }

    abbrFullName[abbrFullNameIdx] = '\0';
    return abbrFullName;
}