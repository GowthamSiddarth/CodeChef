/*
Ada has an array of N crayons, some crayons are pointing upwards and some downwards. Ada thinks that an array of crayons is beautiful if all the crayons are pointing in the same direction.

In one step you can flip any segment of consecutive crayons. After flipping a segment, all crayons pointing downwards will point upwards and visceversa

What is the minimum number of steps to make the array of crayons beautiful?

Input
The first line of the input contains T the number of test cases. Each test case is described in one line containing a string S of N characters, the i-th character is 'U' if the i-th crayon is pointing upwards and 'D' if it is pointing downwards.

Output
For each test case, output a single line containing the minimum number of flips needed to make all crayons point to the same direction.

Constraints
1 ≤ T ≤ 3000
1 ≤ N ≤ 50
Example
Input:
1
UUDDDUUU

Output:
1
Explanation
Example case 1. In one step we can flip all the crayons pointing downwards

https://www.codechef.com/problems/ADACRA
*/
#define MAX_LEN 51

#include <stdio.h>
#include <string.h>

struct AdaAndCrayons
{
    int numOfConsecutiveUps, numOfConsecutiveDowns;
};

struct AdaAndCrayons getCountOfConsecutiveUpsAndDowns(char *crayons)
{
    struct AdaAndCrayons adaAndCrayons = {0, 0};
    char currDirection = crayons[0];

    int idx = 0;
    while ('\0' != crayons[idx])
    {
        while ('\0' != crayons[idx] && currDirection == crayons[idx])
        {
            idx++;
        }

        'U' == currDirection ? adaAndCrayons.numOfConsecutiveUps++ : adaAndCrayons.numOfConsecutiveDowns++;
        if ('\0' != crayons[idx])
        {
            currDirection = crayons[idx];
        }
    }

    return adaAndCrayons;
}

int min(int x, int y)
{
    return x <= y ? x : y;
}

int main()
{
    char crayons[MAX_LEN];
    memcpy(crayons, "UDUDUDDDDDUUUDD", 16);

    struct AdaAndCrayons adaAndCrayons = getCountOfConsecutiveUpsAndDowns(crayons);
    printf("%d\n", min(adaAndCrayons.numOfConsecutiveDowns, adaAndCrayons.numOfConsecutiveUps));

    return 0;
}