/*
The chef has a recipe he wishes to use for his guests, but the recipe will make far more food than he can serve to the guests. The chef therefore would like to make a reduced version of the recipe which has the same ratios of ingredients, but makes less food. The chef, however, does not like fractions. The original recipe contains only whole numbers of ingredients, and the chef wants the reduced recipe to only contain whole numbers of ingredients as well. Help the chef determine how much of each ingredient to use in order to make as little food as possible.

Input
Input will begin with an integer T, the number of test cases. Each test case consists of a single line. The line begins with a positive integer N, the number of ingredients. N integers follow, each indicating the quantity of a particular ingredient that is used.

Output
For each test case, output exactly N space-separated integers on a line, giving the quantity of each ingredient that the chef should use in order to make as little food as possible.

Sample Input
3
2 4 4
3 2 3 4
4 3 15 9 6
Sample Output
1 1
2 3 4
1 5 3 2
Constraints
T≤100
2≤N≤50
All ingredient quantities are between 1 and 1000, inclusive.

https://www.codechef.com/problems/RECIPE
*/
#include <stdio.h>

int getGCDofTwoNums(int num1, int num2)
{
    return 0 == num2 ? num1 : getGCDofTwoNums(num2, num1 % num2);
}

int getGCDofArray(int *arr, int len)
{
    if (1 == len)
    {
        return arr[0];
    }
    else if (2 == len)
    {
        return getGCDofTwoNums(arr[0], arr[1]);
    }
    else
    {
        return getGCDofTwoNums(getGCDofArray(arr, len / 2), getGCDofArray(arr + len / 2, len - len / 2));
    }
}

void findMinimalRecipe(int *arr, int len)
{
    int gcdOfArray = getGCDofArray(arr, len);
    for (int idx = 0; idx < len; idx++)
    {
        arr[idx] = arr[idx] / gcdOfArray;
    }
}

void printIntArray(int *arr, int len)
{
    for (int idx = 0; idx < len; idx++)
    {
        printf("%d ", arr[idx]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {3, 15, 9, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    findMinimalRecipe(arr, len);
    printIntArray(arr, len);
    return 0;
}