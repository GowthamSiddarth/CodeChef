/*
Consider a currency system in which there are notes of seven denominations, namely, Rs. 1, Rs. 2, Rs. 5, Rs. 10, Rs. 50, Rs. 100.
If the sum of Rs. N is input, write a program to computer smallest number of notes that will combine to give Rs. N.

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

Output
Display the smallest number of notes that will combine to give N.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 1000000
Example
Input
3 
1200
500
242

Output
12
5
7

https://www.codechef.com/problems/FLOW005
*/
#include <stdio.h>

enum Denomination
{
    ONE = 1,
    TWO = 2,
    FIVE = 5,
    TEN = 10,
    FIFTY = 50,
    HUNDRED = 100
};

int getMaxNumOfNotesWithAmountForDenomination(int amount, enum Denomination denomination)
{
    return amount / denomination;
}

int getMinNumOfNotes(int amount)
{
    int minNumOfNotes = 0, currNumOfNotes;

    for (int denomination = HUNDRED; denomination > 0 && amount > 0; denomination--)
    {
        switch (denomination)
        {
        case HUNDRED:
        case FIFTY:
        case TEN:
        case FIVE:
        case TWO:
        case ONE:
            currNumOfNotes = getMaxNumOfNotesWithAmountForDenomination(amount, denomination);
            minNumOfNotes = minNumOfNotes + currNumOfNotes;
            amount = amount - denomination * currNumOfNotes;
            break;
        default:
            break;
        }
    }

    return minNumOfNotes;
}

int main()
{
    int amount = 333;
    int res = getMinNumOfNotes(amount);

    printf("%d\n", res);
    return 0;
}