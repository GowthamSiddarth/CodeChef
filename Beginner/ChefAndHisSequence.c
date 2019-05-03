/*
Chef has a sequence of N numbers. He like a sequence better if the sequence contains his favorite sequence as a substring.

Given the sequence and his favorite sequence(F) check whether the favorite sequence is contained in the sequence

Input
The first line will contain the number of test cases and are followed by the cases. 
Each test case consists of four lines: The length of the sequence, the sequence N,the length of F and the sequence F 
Output
Print "Yes" if the sequence contains the favourite sequence int it otherwise print "No"

Constraints
1<=T<=10 
1 1


Input:
2
6
1 2 3 4 5 6
3
2 3 4
6
22 5 6 33 1 4
2
4 15


Output:
Yes
No

https://www.codechef.com/problems/CHEFSQ
*/
#include <stdio.h>

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isSubSequence(int *seq, int seqLen, int *subSeq, int subSeqLen)
{
    int subSeqIdx = 0, seqIdx = 0;

    while (subSeqIdx < subSeqLen)
    {
        int key = subSeq[subSeqIdx];
        while (seqIdx < seqLen && seq[seqIdx] != key)
        {
            seqIdx++;
        }

        if (seqIdx == seqLen)
        {
            return FALSE;
        }

        subSeqIdx++;
    }

    return TRUE;
}

int main()
{
    int seq[] = {22, 5, 6, 33, 1, 4};
    int seqLen = sizeof(seq) / sizeof(seq[0]);

    int subSeq[] = {4, 15};
    int subSeqLen = sizeof(subSeq) / sizeof(subSeq[0]);

    enum Boolean res = isSubSequence(seq, seqLen, subSeq, subSeqLen);
    printf("%s\n", res ? "Yes" : "No");
    return 0;
}