/*
Today, Chef decided to cook some delicious meals from the ingredients in his kitchen. There are N ingredients, represented by strings S1,S2,…,SN. Chef took all the ingredients, put them into a cauldron and mixed them up.

In the cauldron, the letters of the strings representing the ingredients completely mixed, so each letter appears in the cauldron as many times as it appeared in all the strings in total; now, any number of times, Chef can take one letter out of the cauldron (if this letter appears in the cauldron multiple times, it can be taken out that many times) and use it in a meal. A complete meal is the string "codechef". Help Chef find the maximum number of complete meals he can make!

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
N lines follow. For each i (1≤i≤N), the i-th of these lines contains a single string Si.
Output
For each test case, print a single line containing one integer — the maximum number of complete meals Chef can create.

Constraints
1≤T≤100
1≤N≤100
|S1|+|S2|+…+|SN|≤1,000
each string contains only lowercase English letters
Example Input
3
6
cplusplus
oscar
deck
fee
hat
near
5
code
hacker
chef
chaby
dumbofe
5
codechef
chefcode
fehcedoc
cceeohfd
codechef
Example Output
1
2
5
Explanation
Example case 1: After mixing, the cauldron contains the letter 'c' 3 times, the letter 'e' 4 times, and each of the letters 'o', 'd', 'h' and 'f' once. Clearly, this is only enough for one "codechef" meal.

Example case 2: After mixing, the cauldron contains the letter 'c' 4 times, 'o' 2 times, 'd' 2 times, 'e' 4 times, 'h' 3 times and 'f' 2 times, which is enough to make 2 meals.

https://www.codechef.com/problems/CFMM
*/
#define NUM_OF_ALPHABETS_IN_CODECHEF 6
#define MAX_LEN_OF_INGREDIENT 1000
#define MAX_NUM_OF_INGREDIENTS 100

#include <stdio.h>
#include <limits.h>

int getCharIdx(char ch)
{
    switch (ch)
    {
    case 'c':
        return 0;

    case 'o':
        return 1;

    case 'd':
        return 2;

    case 'e':
        return 3;

    case 'h':
        return 4;

    case 'f':
        return 5;

    default:
        return -1;
    }
}

void updateAlphaCount(int (*alphaCount)[NUM_OF_ALPHABETS_IN_CODECHEF], char *string)
{
    size_t idx = 0;
    while ('\0' != string[idx])
    {
        int currCharPos = getCharIdx(string[idx]);
        if (currCharPos >= 0)
        {
            (*alphaCount)[currCharPos]++;
        }

        idx++;
    }
}

int minOfArray(int *array, int len)
{
    int min = INT_MAX;
    for (size_t idx = 0; idx < len; idx++)
    {
        if (array[idx] < min)
        {
            min = array[idx];
        }
    }

    return min;
}

int getNumOfCompleteMeals(char ingredients[MAX_NUM_OF_INGREDIENTS][MAX_LEN_OF_INGREDIENT], int numOfIngredients)
{
    int alphaCount[NUM_OF_ALPHABETS_IN_CODECHEF] = {0};
    for (size_t idx = 0; idx < numOfIngredients; idx++)
    {
        updateAlphaCount(&alphaCount, ingredients[idx]);
    }

    alphaCount[getCharIdx('c')] = alphaCount[getCharIdx('c')] / 2;
    alphaCount[getCharIdx('e')] = alphaCount[getCharIdx('e')] / 2;

    return minOfArray(alphaCount, NUM_OF_ALPHABETS_IN_CODECHEF);
}

int main()
{
    char ingredients[MAX_NUM_OF_INGREDIENTS][MAX_LEN_OF_INGREDIENT] = {
        "codechef", "chefcode", "fehcedoc", "cceeohfd", "cceeohfd"};
    int numOfIngredients = 5;

    int numOfCompleteMeals = getNumOfCompleteMeals(ingredients, numOfIngredients);
    printf("%d\n", numOfCompleteMeals);

    return 0;
}