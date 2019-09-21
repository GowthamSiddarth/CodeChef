/*
There are n villages in a line in an area. There are two kinds of tribes A and B that reside there. A village can be either empty or occupied by one of the tribes. An empty village is said to be controlled by a tribe of village A if it is surrounded by villages of tribes A from the left and from the right. Same goes for the tribe B.

Find out the number of villages that are either occupied by or controlled by tribes A and B, respectively.

Input
The first line of the input contains an integer T denoting the number of test cases.

The first line of the input contains a string s denoting the configuration of the villages, each character of which can be 'A', 'B' or '.'.

Output
For each test case, output two space-separated integers denoting the number of villages either occupied by or controlled by tribe A and B, respectively.

Constraints
1 ≤ T ≤ 20
1 ≤ |s| ≤ 105
Subtasks
Subtask #1 (40 points): 1 ≤ |s| ≤ 103
Subtask #2 (60 points): Original constraints
Example
Input
4
A..A..B...B
..A..
A....A
..B..B..B..

Output
4 5
1 0
6 0
0 7

https://www.codechef.com/problems/VILTRIBE
*/
#define MAX_SIZE 10000

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum VillageTribe
{
    TRIBE_A = 'A',
    TRIBE_B = 'B',
    EMPTY = '.'
};

struct VillagesPerTribe
{
    int numOfVillagesForTribeA, numOfVillagesForTribeB;
};

struct VillagesPerTribe getCountOfVillagesPerTribe(char *villagesConfiguration)
{
    size_t idx = 0;
    struct VillagesPerTribe villagesPerTribe = {0, 0};
    while ('\0' != villagesConfiguration[idx])
    {
        enum VillageTribe currVillageTribe = villagesConfiguration[idx];
        enum VillageTribe otherTribe = '\0';
        int *villagesCountForCurrTribe = NULL;
        if (EMPTY == currVillageTribe)
        {
            idx++;
            continue;
        }
        else if (TRIBE_A == currVillageTribe)
        {
            otherTribe = TRIBE_B;
            villagesCountForCurrTribe = &villagesPerTribe.numOfVillagesForTribeA;
        }
        else
        {
            otherTribe = TRIBE_A;
            villagesCountForCurrTribe = &villagesPerTribe.numOfVillagesForTribeB;
        }

        int firstOccupiedVillage = idx, lastOccupiedVillagePos = idx;
        while ('\0' != villagesConfiguration[idx] && otherTribe != villagesConfiguration[idx])
        {
            if (currVillageTribe == villagesConfiguration[idx])
            {
                lastOccupiedVillagePos = idx;
            }

            idx++;
        }

        *villagesCountForCurrTribe = *villagesCountForCurrTribe + lastOccupiedVillagePos - firstOccupiedVillage + 1;
    }

    return villagesPerTribe;
}

int main()
{
    char villagesConfiguration[MAX_SIZE];
    memcpy(villagesConfiguration, "ABA..A", 7);

    struct VillagesPerTribe villagesPerTribe = getCountOfVillagesPerTribe(villagesConfiguration);
    printf("%d %d\n", villagesPerTribe.numOfVillagesForTribeA, villagesPerTribe.numOfVillagesForTribeB);

    return 0;
}