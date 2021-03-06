/*
RJ is a very curious observer. On the first day of every month, he tries to figure out, for each of the seven days of the week, how many times that day occurs in the current month.

RJ got confused so badly doing this that he asks for your help! He asks several queries; in each query, he gives you the number of days in the current month and which day of the week is on the 1st of the current month.

For each query, you should tell him how many times each day of the week occurs.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains an integer W and a string S, separated by a space.
W denotes the number of days in the current month.
S is one of the strings "mon", "tues", "wed", "thurs", "fri", "sat" or "sun", denoting the day of the week on the 1st of the current month.
Output
For each query, print seven space-separated integers denoting the number of occurrences of Monday, Tuesday, Wednesday, Thursday, Friday, Saturday and Sunday.

Constraints
1 ≤ T ≤ 103
28 ≤ W ≤ 31
Subtasks
Subtask #1 (20 points): W = 28

Subtask #2 (80 points): original constraints

Example
Input:

2
28 mon
31 wed

Output:

4 4 4 4 4 4 4
4 4 5 5 5 4 4
Example
Example case 2: There are 4 Mondays, 4 Tuesdays, 5 Wednesdays, 5 Thursdays, 5 Fridays, 4 Saturdays and 4 Sundays.

https://www.codechef.com/problems/NW1
*/
#define NUM_OF_DAYS_IN_WEEK 7
#define MIN_DAYS_IN_MONTH 28
#define MAX_LEN 6

#include <stdio.h>
#include <string.h>

enum DayInWeek
{
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};

enum DayInWeek getNextDayInWeek(enum DayInWeek currDay)
{
    return (currDay + 1) % NUM_OF_DAYS_IN_WEEK;
}

enum DayInWeek getDayInWeekFromStr(char *dayInWeekStr)
{
    enum DayInWeek dayInWeek;
    switch (dayInWeekStr[0])
    {
    case 'm':
        dayInWeek = MON;
        break;

    case 't':
        dayInWeek = 'u' == dayInWeekStr[1] ? TUE : THU;
        break;

    case 'w':
        dayInWeek = WED;
        break;

    case 'f':
        dayInWeek = FRI;
        break;

    case 's':
        dayInWeek = 'u' == dayInWeekStr[1] ? SUN : SAT;
        break;
    }

    return dayInWeek;
}

void setNumOfOccOfEachDayInWeek(int numOfDaysInMonth, char firstDay[MAX_LEN], int *numOfOccOfEachDayInWeek)
{
    enum DayInWeek currDay = getDayInWeekFromStr(firstDay);
    int count = 0, extraDays = numOfDaysInMonth - MIN_DAYS_IN_MONTH;
    while (count < NUM_OF_DAYS_IN_WEEK)
    {
        numOfOccOfEachDayInWeek[currDay] = extraDays > 0 ? 5 : 4;
        extraDays--;
        count++;
        currDay = getNextDayInWeek(currDay);
    }
}

int main()
{
    char firstDay[MAX_LEN];
    memcpy(firstDay, "mon", 4);
    int numOfDaysInMonth = 29;
    int numOfOccOfEachDayInWeek[NUM_OF_DAYS_IN_WEEK] = {0};

    setNumOfOccOfEachDayInWeek(numOfDaysInMonth, firstDay, numOfOccOfEachDayInWeek);
    for (int idx = 0; idx < NUM_OF_DAYS_IN_WEEK; idx++)
    {
        printf("%d ", numOfOccOfEachDayInWeek[idx]);
    }

    return 0;
}