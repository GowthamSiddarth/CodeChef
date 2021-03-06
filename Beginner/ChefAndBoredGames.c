/*
Chef has recently been playing a lot of chess in preparation for the ICCT (International Chef Chess Tournament).

Since putting in long hours is not an easy task, Chef's mind wanders elsewhere. He starts counting the number of squares with odd side length on his chessboard..

However, Chef is not satisfied. He wants to know the number of squares of odd side length on a generic N∗N chessboard.

Input:
The first line will contain a single integer T, the number of test cases.
The next T lines will have a single integer N, the size of the chess board.
Output:
For each test case, print a integer denoting the number of squares with odd length.

Constraints
1≤T≤100
1≤N≤1000
Sample Input:
    2
    3
    8
Sample Output:
    10
    120

https://www.codechef.com/problems/PCJ18B
*/
#include <stdio.h>

int getNumOfSquaresFittingInChessBoardWithSize(int chessBoardSize, int squareSize)
{
    int numOfSquaresFittingInOneAxis = chessBoardSize - squareSize + 1;
    return numOfSquaresFittingInOneAxis * numOfSquaresFittingInOneAxis;
}

int getNumOfSquaresWithOddSizeFittingInChessBoard(int chessBoardSize)
{
    int count = 0;
    for (int squareSize = 1; squareSize <= chessBoardSize; squareSize = squareSize + 2)
    {
        count = count + getNumOfSquaresFittingInChessBoardWithSize(chessBoardSize, squareSize);
    }

    return count;
}

int main()
{
    int chessBoardSize = 6;
    int numOfSquaresWithOddSizeFittingInChessBoard = getNumOfSquaresWithOddSizeFittingInChessBoard(chessBoardSize);

    printf("%d\n", numOfSquaresWithOddSizeFittingInChessBoard);
    return 0;
}