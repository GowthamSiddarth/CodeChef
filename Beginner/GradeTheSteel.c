/*
A certain grade of steel is graded according to the following conditions.

Hardness must be greater than 50.
Carbon content must be less than 0.7.
Tensile strength must be greater than 5600.


The grades are as follows:
Grade is 10 if all three conditions are met.
Grade is 9 if conditions (i) and (ii) are met.
Grade is 8 if conditions (ii) and (iii) are met.
Grade is 7 if conditions (i) and (iii) are met.
Garde is 6 if only one condition is met.
Grade is 5 if none of three conditions are met.

Write a program, if the user gives values of hardness, carbon content and tensile strength of the steel under consideration and display the grade of the steel.
Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains three numbers hardness, carbon content and tensile strength of the steel.

Output
Print Grade of the steel depending on Conditions.

Constraints
1 ≤ T ≤ 1000
0≤ hardness, carbon content, tensile strength ≤ 10000
Example
Input

3 
53 0.6 5602
45 0 4500
0 0 0 
Output

10
6
6

https://www.codechef.com/problems/FLOW014
*/
#define HARDNESS_THRESHOLD 50
#define CARBON_CONTENT_LIMIT 0.7
#define TENSILE_STRENGTH_THRESHOLD 5600

#include <stdio.h>

enum Grade
{
    FIVE = 5,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN
};

enum Grade steelScoreGradeMap[] = {FIVE, SIX, SIX, NINE, SIX, SEVEN, EIGHT, TEN};

enum Grade getGradeOfSteel(int hardness, float carbonContent, int tensileStrength)
{
    int score = 0;
    score = hardness > HARDNESS_THRESHOLD ? score | 1 : score;
    score = carbonContent < CARBON_CONTENT_LIMIT ? score | 2 : score;
    score = tensileStrength > TENSILE_STRENGTH_THRESHOLD ? score | 4 : score;

    return steelScoreGradeMap[score];
}

int main()
{
    int hardness = 45, tensileStrength = 4500;
    float carbonContent = 0.6;

    enum Grade steelGrade = getGradeOfSteel(hardness, carbonContent, tensileStrength);
    printf("%d\n", steelGrade);

    return 0;
}