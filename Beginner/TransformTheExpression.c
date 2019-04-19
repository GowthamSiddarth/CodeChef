/*
Reverse Polish Notation (RPN) is a mathematical notation where every operator follows all of its operands. For instance, to add three and four, one would write "3 4 +" rather than "3 + 4". If there are multiple operations, the operator is given immediately after its second operand; so the expression written "3 − 4 + 5" would be written "3 4 − 5 +" first subtract 4 from 3, then add 5 to that.
Transform the algebraic expression with brackets into RPN form.

You can assume that for the test cases below only single letters will be used, brackets [] will not be used and each expression has only one RPN form (no expressions like a*b*c)

Input
The first line contains t, the number of test cases (less then 100).

Followed by t lines, containing an expression to be translated to RPN form, where the length of the expression is less then 400.

Output
The expressions in RPN form, one per line.
Example
Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*

https://www.codechef.com/problems/ONP
*/
#define MAX_SIZE 400

#include <malloc.h>

enum Boolean
{
    FALSE,
    TRUE
};

struct StackOfStrings
{
    char stack[MAX_SIZE][MAX_SIZE];
    int top;
};

struct StackOfStrings *initStackOfStrings()
{
    struct StackOfStrings *stackOfStrings = (struct StackOfStrings *)malloc(sizeof(struct StackOfStrings));
    stackOfStrings->top = 0;

    return stackOfStrings;
}

enum Boolean push(struct StackOfStrings *stackOfStrings, char *string)
{
    if (MAX_SIZE == stackOfStrings->top)
    {
        return FALSE;
    }

    int strIdx = 0, itemIdx = 0;
    while ('\0' != string[strIdx])
    {
        stackOfStrings->stack[stackOfStrings->top][itemIdx] = string[strIdx];
        strIdx++;
        itemIdx++;
    }

    stackOfStrings->stack[stackOfStrings->top][itemIdx] = '\0';
    return TRUE;
}

char *getTopItem(struct StackOfStrings *stackOfStrings)
{
    char *topItem = (char *)malloc(sizeof(char) * MAX_SIZE);
    int idx = 0;

    while ('\0' != stackOfStrings->stack[stackOfStrings->top][idx])
    {
        topItem[idx] = stackOfStrings->stack[stackOfStrings->top][idx];
        idx++;
    }

    topItem[idx] = '\0';
    return topItem;
}

char *pop(struct StackOfStrings *stackOfStrings)
{
    char *topItem = getTopItem(stackOfStrings);
    stackOfStrings->stack[stackOfStrings->top][0] = '\0';

    if (0 != stackOfStrings->top)
    {
        stackOfStrings->top = stackOfStrings->top - 1;
    }

    return topItem;
}

enum Boolean isEmpty(struct StackOfStrings *stackOfStrings)
{
    return 0 == stackOfStrings->top ? TRUE : FALSE;
}

char *charToString(char c)
{
    char *string = (char *)malloc(sizeof(char) * 2);
    string[0] = c;
    string[1] = '\0';

    return string;
}

enum Boolean isOpenParanthesis(char *operator)
{
    return '(' == operator[0] ? TRUE : FALSE;
}