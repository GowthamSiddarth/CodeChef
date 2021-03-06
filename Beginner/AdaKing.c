/*
Chef Ada is training to defend her title of World Chess Champion.

To train her calculation skills, Ada placed a king on a chessboard. Remember that a chessboard has 8 rows and 8 columns (for the purposes of this problem, both the rows and the columns are numbered 1 through 8); let's denote the square in row r and column c by (r,c). A king on a square (r,c) can move to another square (r′,c′) if and only if (r′−r)2+(c′−c)2≤2.

Ada placed her king on the square (R,C). Now, she is counting the number of squares that can be visited (reached) by the king in at most K moves. Help Ada verify her answers.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers R, C and K.
Output
For each test case, print a single line containing one integer — the number of squares the king can visit.

Constraints
1≤T≤512
1≤R,C,K≤8
Example Input
1
1 3 1
Example Output
6
Explanation
Example case 1: The king can stay on its original square or move to one of the squares circled in the following figure.

https://codechef_shared.s3.amazonaws.com/download/Images/CK102TST/ADAKNG/ADAKNG.png

https://www.codechef.com/problems/ADAKNG
*/
#include <stdio.h>

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x < y ? x : y;
}

int getNumOfMovesAvailable(int row, int col, int numOfMovesLeft)
{
    int maxRow = min(row + numOfMovesLeft, 8);
    int minRow = max(row - numOfMovesLeft, 1);
    int maxCol = min(col + numOfMovesLeft, 8);
    int minCol = max(col - numOfMovesLeft, 1);

    return (maxRow - minRow + 1) * (maxCol - minCol + 1);
}

int main()
{
    int row = 1, col = 3, numOfMovesLeft = 1;
    int numOfMovesAvailable = getNumOfMovesAvailable(row, col, numOfMovesLeft);

    printf("%d\n", numOfMovesAvailable);
    return 0;
}