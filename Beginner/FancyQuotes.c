/*
"I don't have any fancy quotes." - vijju123

Chef was reading some quotes by great people. Now, he is interested in classifying all the fancy quotes he knows. He thinks that all fancy quotes which contain the word "not" are Real Fancy; quotes that do not contain it are regularly fancy.

You are given some quotes. For each quote, you need to tell Chef if it is Real Fancy or just regularly fancy.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single string S denoting a quote.
Output
For each test case, print a single line containing the string "Real Fancy" or "regularly fancy" (without quotes).

Constraints
1≤T≤50
1≤|S|≤100
each character of S is either a lowercase English letter or a space
Subtasks
Subtask #1 (100 points): original constraints

Example Input
2
i do not have any fancy quotes
when nothing goes right go left
Example Output
Real Fancy
regularly fancy
Explanation
Example case 1: "i do not have any fancy quotes"

Example case 2: The word "not" does not appear in the given quote.

https://www.codechef.com/problems/FANCY
*/
#define MAX_LEN 100

#include <stdio.h>
#include <string.h>

enum QuoteType
{
    REAL_FANCY,
    REGULAR_FANCY
};

enum Boolean
{
    FALSE,
    TRUE
};

int getNextCharPos(char *string, char ch, int idx, enum Boolean match)
{
    while ('\0' != string[idx] && ((match && ch != string[idx]) || (!match && ch == string[idx])))
    {
        idx++;
    }

    return idx;
}

enum QuoteType getQuoteType(char *quotation, char *fancyWord)
{
    char WHITESPACE = ' ';
    int idx = getNextCharPos(quotation, WHITESPACE, 0, FALSE);
    while ('\0' != quotation[idx])
    {
        idx = getNextCharPos(quotation, WHITESPACE, idx, FALSE);
        int fancyWordIdx = 0;
        while ('\0' != fancyWord[fancyWordIdx] && '\0' != quotation[idx] && fancyWord[fancyWordIdx] == quotation[idx])
        {
            idx++;
            fancyWordIdx++;
        }
        
        if ('\0' == fancyWord[fancyWordIdx] && (WHITESPACE == quotation[idx] || '\0' == quotation[idx]))
        {
            return REAL_FANCY;
        }

        idx = getNextCharPos(quotation, WHITESPACE, idx, TRUE);
    }

    return REGULAR_FANCY;
}

int main()
{
    char quotation[MAX_LEN];
    memcpy(quotation, "i do not have any fancy quotes", 31);

    char fancyWord[] = {'n', 'o', 't', '\0'};
    enum QuoteType quoteType = getQuoteType(quotation, fancyWord);

    printf("%s %d\n", REAL_FANCY == quoteType ? "Real Fancy" : "regularly fancy", quoteType);
    return 0;
}