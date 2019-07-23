/*
Chef wants to prepare a Cook-Off contest with 5 problems chosen from a set of N problems. He has marked the difficulty of each problem within a range identified by one of the following strings: "cakewalk", "simple", "easy", "easy-medium", "medium", "medium-hard", "hard". According to this page, a Cook-Off contest must have problems of the following difficulties:

exactly one "cakewalk";
exactly one "simple";
exactly one "easy";
one "easy-medium" or one "medium";
one "medium-hard" or one "hard".
Given the information about the N problems, can you advise Chef if it's possible to pick 5 problems and form a valid Cook-Off contest?

Input
The first line of input contains one integer T denoting the number of test cases.
T test cases follow.
The first line of each test case contains a single integer N.
Then N lines follow; the i-th line contains a single string si, denoting the difficulty of the i-th problem.
Output
For each test case, output "Yes" if it's possible to pick 5 problems and form a valid Cook-Off contest; otherwise, output "No".

Constraints
1 ≤ T ≤ 100000
5 ≤ N ≤ 100000
sum of N in all test cases ≤ 600000
si can only be one of the following strings:
"cakewalk"
"simple"
"easy"
"easy-medium"
"medium"
"medium-hard"
"hard"
Subtask #1 (11 points):

N = 5
Subtask #2 (27 points):

5 ≤ N ≤ 15
T ≤ 100
Subtask #3 (62 points):

original constraints
Example
Input:
3
5
easy
medium
medium-hard
simple
cakewalk
7
simple
simple
medium
medium
easy-medium
cakewalk
easy
7
cakewalk
simple
easy
easy-medium
medium
medium-hard
hard

Output:
Yes
No
Yes

Explanation
Example case 2: There are neither problems of "medium-hard" level nor "hard" level, so it's impossible to form a Cook-Off contest.

https://www.codechef.com/problems/C00K0FF
*/
#define MAX_LEN 12
#define NUM_OF_LEVELS 5

#include <stdio.h>

enum DifficultyLevel
{
    CAKEWALK = 0,
    SIMPLE = 1,
    EASY = 2,
    EASY_MEDIUM = 3,
    MEDIUM = 3,
    MEDIUM_HARD = 4,
    HARD = 4
};

enum DifficultyLevel getDifficultyLevel(char *difficulty)
{
    int idx = 0;
    enum DifficultyLevel difficultyLevel;
    switch (difficulty[0])
    {
    case 'c':
        difficultyLevel = CAKEWALK;
        break;
    case 's':
        difficultyLevel = SIMPLE;
        break;
    case 'e':
        while ('\0' != difficulty[idx] && '-' != difficulty[idx])
        {
            idx++;
        }

        difficultyLevel = '\0' == difficulty[idx] ? EASY : EASY_MEDIUM;
        break;
    case 'm':
        while ('\0' != difficulty[idx] && '-' != difficulty[idx])
        {
            idx++;
        }

        difficultyLevel = '\0' == difficulty[idx] ? MEDIUM : MEDIUM_HARD;
        break;
    case 'h':
        difficultyLevel = HARD;
        break;
    }

    return difficultyLevel;
}

enum Boolean
{
    FALSE,
    TRUE
};

void updateCounts(int *counts, enum DifficultyLevel difficultyLevel)
{
    counts[difficultyLevel] = counts[difficultyLevel] + 1;
}

enum Boolean allDifficultyLevelsExist(int *counts)
{
    int idx = 0;
    while (idx < NUM_OF_LEVELS && counts[idx] > 0)
    {
        idx++;
    }

    return NUM_OF_LEVELS == idx ? TRUE : FALSE;
}

int main()
{
    int t;
    scanf("%d", &t);
    
    while (t--)
    {
        int numOfQuestions;
        scanf("%d\n", &numOfQuestions);
        
        char difficultyLevelStr[MAX_LEN];
        
        int itr = 0;
        int counts[NUM_OF_LEVELS] = {0};
        enum Boolean allDiffLevelsExists = FALSE;
        while (!allDiffLevelsExists && itr < numOfQuestions)
        {
            scanf("%s", difficultyLevelStr);
            enum DifficultyLevel difficultyLevel = getDifficultyLevel(difficultyLevelStr);
            updateCounts(counts, difficultyLevel);
            allDiffLevelsExists = allDifficultyLevelsExist(counts);
            itr++;
        }
    
        printf("%s\n", allDiffLevelsExists ? "Yes" : "No");
        while (itr < numOfQuestions)
        {
            scanf("%s", difficultyLevelStr);
            itr++;
        }
    }
    
    return 0;
}