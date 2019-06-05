/*
You visit a doctor on a date given in the format yyyy:mm:dd. Your doctor suggests you to take pills every alternate day starting from that day. You being a forgetful person are pretty sure won’t be able to remember the last day you took the medicine and would end up in taking the medicines on wrong days.

So you come up with the idea of taking medicine on the dates whose day is odd or even depending on whether dd is odd or even. Calculate the number of pills you took on right time before messing up for the first time.

Note:
Every year that is exactly divisible by four is a leap year, except for years that are exactly divisible by 100; the centurial years that are exactly divisible by 400 are still leap years. For example, the year 1900 is not a leap year; the year 2000 is a leap year.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, in the format yyyy:mm:dd
Output:
For each testcase, output in a single line the required answer.

Constraints
1≤T≤1000
1900≤yyyy≤ 2038
yyyy:mm:dd is a valid date
Sample Input:
1
2019:03:31
Sample Output:
1
EXPLANATION:
You can take pill on the right day only on 31st March. Next you will take it on 1st April which is not on the alternate day.

https://www.codechef.com/problems/MEDIC
*/
#include <malloc.h>
#include <math.h>
#include <stdio.h>

struct Date
{
    int date, month, year;
};

enum NumType
{
    ODD,
    EVEN
};

enum NumType getNumType(int num)
{
    return 0 == num % 2 ? EVEN : ODD;
}

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isLeapYear(int year)
{
    return 0 == year % 400 || (0 == year % 4 && 0 != year % 100) ? TRUE : FALSE;
}

enum MonthType
{
    FEB = 28,
    _30Days = 30,
    _31Days = 31,
};

enum MonthType getMonthType(int monthIdx)
{
    switch (monthIdx)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return _31Days;
    case 4:
    case 6:
    case 9:
    case 11:
        return _30Days;
    case 2:
        return FEB;
    }
}

int getNumOfDaysInMonth(enum MonthType monthType, int year)
{
    return FEB == monthType ? isLeapYear(year) ? monthType + 1 : monthType : monthType;
}

int getNumOfDaysInRange(int startDate, int endDate)
{
    int numOfDaysInRange = endDate - startDate + 1;
    return EVEN == getNumType(numOfDaysInRange) ? numOfDaysInRange / 2 : numOfDaysInRange / 2 + 1;
}

int getNumOfPillsTakenCorrectly(struct Date *date)
{
    enum MonthType monthType = getMonthType(date->month);
    int numOfDaysInMonth = getNumOfDaysInMonth(monthType, date->year);
    switch (monthType)
    {
    case _31Days:
        return getNumOfDaysInRange(date->date, numOfDaysInMonth);
    case _30Days:
        return getNumOfDaysInRange(date->date, numOfDaysInMonth) + getNumOfDaysInRange(EVEN == getNumType(date->date) ? 2 : 1, getNumOfDaysInMonth(_31Days, date->year));
    case FEB:
        return getNumOfDaysInRange(date->date, numOfDaysInMonth) + (28 == numOfDaysInMonth ? getNumOfDaysInRange(EVEN == getNumType(date->date) ? 2 : 1, getNumOfDaysInMonth(_31Days, date->year)) : 0);
    }
}

struct Date *parseDate(char *date)
{
    struct Date *parsedDate = (struct Date *)malloc(sizeof(struct Date));
    int idx = 0, numOfColons = 0;

    while ('\0' != date[idx])
    {
        int placeValue = 0 == numOfColons ? 3 : 1;
        int value = 0;
        while ('\0' != date[idx] && ':' != date[idx])
        {
            value = value + (date[idx] - '0') * pow(10, placeValue);
            idx++;
            placeValue--;
        }

        switch (numOfColons)
        {
        case 0:
            parsedDate->year = value;
            break;
        case 1:
            parsedDate->month = value;
        case 2:
            parsedDate->date = value;
        }

        if (':' == date[idx])
        {
            numOfColons++;
            idx++;
        }
    }

    return parsedDate;
}

int main()
{
    char *date = "2017:06:06";
    struct Date *parsedDate = parseDate(date);

    int numOfPillsTakenCorrectly = getNumOfPillsTakenCorrectly(parsedDate);
    printf("%d\n", numOfPillsTakenCorrectly);

    return 0;
}