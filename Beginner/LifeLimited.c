/*
Recently the company Life Ltd created a new logo for themselves. You are asked to test the design of the logo.

The logo is a 3 * 3 square grid with 9 cells. Each cell contains some lower case english letter. This logo will be considered good if there exist three cells in the shape of an L that contain the letter 'l' (lower case 'L') in each of them. That is, there should be a cell with 'l', its cell directly beneath it should also have 'l' and the cell to the right of the second cell should also have 'l'.

Your task is to tell whether the logo is good or not.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of the test cases follows.
Each of the next three lines contains a description of the logo, i-th of the line contains three characters which denote the i-th row of the logo.
Output
For each test case, output yes or no according to the answer to the problem.

Constraints
1≤T≤100
Example Input
3
laz
lla
aaa
ala
lla
aaa
lll
lll
lll
Example Output
yes
no
yes
Explanation:
Testcase1: The L shaped cells with 'l' in each of them is shown in bold here:

laa

lla

aaa

https://www.codechef.com/problems/LIFELTD
*/

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isLShapeFound(char logo[3][3], int startXIdx, int startYIdx)
{
    return 'l' == logo[startXIdx][startYIdx] && 'l' == logo[startXIdx + 1][startYIdx] && 'l' == logo[startXIdx + 1][startYIdx + 1] ? TRUE : FALSE;
}

enum Boolean isLogoGood(char logo[3][3])
{
    return isLShapeFound(logo, 0, 0) || isLShapeFound(logo, 0, 1) || isLShapeFound(logo, 1, 0) || isLShapeFound(logo, 1, 1) ? TRUE : FALSE;
}