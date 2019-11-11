/*
In the magical land of Byteland, there are three kinds of citizens:

a Bit - 2ms after a Bit appears, it grows up and becomes a Nibble (i.e. it disappears and a Nibble appears)
a Nibble - 8ms after a Nibble appears, it grows up and becomes a Byte
a Byte - 16ms after a Byte appears, it grows up, splits into two Bits and disappears
Chef wants to know the answer to the following question: what would the population of Byteland be immediately before the time Nms if only 1 Bit appeared at time 0ms?

Help him and find the population (number of citizens) of each type.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.
Output
For each test case, print a single line containing three space-separated integers — the number of Bits, Nibbles and Bytes.

Constraints
1≤T≤104
1≤N≤1,600
Subtasks
Subtask #1 (25 points): 1≤N≤140
Subtask #2 (75 points): original constraints

Example Input
2
2
3
Example Output
1 0 0
0 1 0
Explanation
Immediately before the time 2ms, there is only one Bit. At 2ms, this Bit grows up, so immediately before 3ms, there is only one Nibble in Byteland.

https://www.codechef.com/problems/BITOBYT
*/
#include <math.h>
#include <stdio.h>

struct CitizensCount
{
    int bit, nibble, byte;
};

struct CitizensCount getCitizensCountBeforNthInstance(int currInstance)
{
    int prevInstance = currInstance - 1;
    int numOfChainReactions = prevInstance / 26;
    int timeSinceLastChainReaction = prevInstance % 26;
    struct CitizensCount citizensCount = {0, 0, 0};
    if (timeSinceLastChainReaction >= 0 && timeSinceLastChainReaction < 2)
    {
        citizensCount.bit = pow(2, numOfChainReactions);
    }
    else if (timeSinceLastChainReaction >= 2 && timeSinceLastChainReaction < 10)
    {
        citizensCount.nibble = pow(2, numOfChainReactions);
    }
    else
    {
        citizensCount.byte = pow(2, numOfChainReactions);
    }

    return citizensCount;
}

int main()
{
    int instant = 27;
    struct CitizensCount citizensCount = getCitizensCountBeforNthInstance(instant);

    printf("%d %d %d\n", citizensCount.bit, citizensCount.nibble, citizensCount.byte);
    return 0;
}