/*
Given the list of numbers, you are to sort them in non decreasing order.
Input
t – the number of numbers in list, then t lines follow [t <= 10^6]. 
Each line contains one integer: N [0 <= N <= 10^6]

Output
Output given numbers in non decreasing order.
Example
Input:

5
5
3
6
7
1
Output:

1
3
5
6
7

https://www.codechef.com/problems/TSORT
*/
#define MAX_SIZE 1000001

void turboSort(int *arr, int len)
{
    int occurrences[MAX_SIZE] = {0};
    for (int i = 0; i < len; i++)
    {
        occurrences[arr[i]]++;
    }

    for (int i = 0, j = 0; i < MAX_SIZE; i++)
    {
        while (occurrences[i])
        {
            arr[j] = i;
            occurrences[i]--;
            j++;
        }
    }
}