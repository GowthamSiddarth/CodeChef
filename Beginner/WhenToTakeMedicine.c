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

enum NumType
{
    ODD,
    EVEN
};

enum NumType getNumType(int num)
{
    return 0 == num % 2 ? EVEN : ODD;
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

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isLeapYear(int year)
{
    return 0 == year % 400 || (0 == year % 4 && 0 != year % 100) ? TRUE : FALSE;
}

int numOfOddDaysInRange(int startDate, int endDate)
{
    int numOfDaysInRange = endDate - startDate + 1;
    return EVEN == getNumType(numOfDaysInRange) ? numOfDaysInRange / 2 : (EVEN == getNumType(startDate) ? numOfDaysInRange / 2 : numOfDaysInRange / 2 + 1);
}

int numOfPillsTakenCorrectly(int date, int month, int year)
{
    enum MonthType monthType = getMonthType(month);
    switch (monthType)
    {
    case _31Days:
        return numOfOddDaysInRange(date, getNumOfDaysInMonth(monthType, year));
    case _30Days:
    case FEB:
        return numOfOddDaysInRange(date, getNumOfDaysInMonth(monthType, year)) + numOfOddDaysInRange(1, getNumOfDaysInMonth(_31Days, year));
    }
}