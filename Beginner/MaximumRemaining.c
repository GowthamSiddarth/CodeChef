/*
Chef and Dhyey have become friends recently. Chef wants to test Dhyey's intelligence by giving him a puzzle to solve.

The puzzle contains an integer sequence A1,A2,…,AN. The answer to the puzzle is the maximum of Ai%Aj, taken over all valid i, j.

Help Dhyey solve this puzzle.

Input
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.
Output
For each test case, print a single line containing one integer — the answer to the puzzle.

Constraints
2≤N≤105
1≤Ai≤109 for each valid i
Subtasks
Subtask #1 (30 points): 2≤N≤1,000
Subtask #2 (70 points): 2≤N≤105
Example Input 1
5  
1 2 3 4 5  
Example Output 1
4  
Example Input 2
6  
5 5 5 2 3 8
Example Output 2
5

https://www.codechef.com/problems/MAXREM
*/

int getMaxMod(int *array, int len)
{
    int max1 = 0, max2 = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (array[i] > max1)
        {
            max2 = max1;
            max1 = array[i];
        }
    }

    return max2;
}