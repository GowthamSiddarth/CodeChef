/*
Chef is teaching a cooking course. There are N students attending the course, numbered 1 through N.

Before each lesson, Chef has to take attendance, i.e. call out the names of students one by one and mark which students are present. Each student has a first name and a last name. In order to save time, Chef wants to call out only the first names of students. However, whenever there are multiple students with the same first name, Chef has to call out the full names (both first and last names) of all these students. For each student that does not share the first name with any other student, Chef may still call out only this student's first name.

Help Chef decide, for each student, whether he will call out this student's full name or only the first name.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
N lines follow. For each valid i, the i-th of the following N lines contains two space-separated strings denoting the first and last name of student i.
Output
For each test case, print N lines. For each valid i, the i-th of these lines should describe how Chef calls out the i-th student's name ― it should contain either the first name or the first and last name separated by a space.

Constraints
1≤T≤100
2≤N≤100
all first and last names contain only lowercase English letters
the lengths of all first and last names are between 1 and 10 inclusive
Subtasks
Subtask #1 (100 points): original constraints

Example Input
1
4
hasan jaddouh
farhod khakimiyon
kerim kochekov
hasan khateeb
Example Output
hasan jaddouh
farhod
kerim
hasan khateeb

https://www.codechef.com/problems/ATTND
*/
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

string getFirstName(string fullName)
{
    return fullName.substr(0, fullName.find(" "));
}

map<string, int> getFirstNamesCount(vector<string> fullNames)
{
    map<string, int> firstNamesCount;
    for (int idx = 0; idx < fullNames.size(); idx++)
    {
        string firstName = getFirstName(fullNames[idx]);
        map<string, int>::iterator firstNameIdx = firstNamesCount.find(firstName);
        if (firstNameIdx == firstNamesCount.end())
        {
            firstNamesCount.insert(make_pair(firstName, 1));
        }
        else
        {
            firstNameIdx->second++;
        }
    }

    return firstNamesCount;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int numOfStudents;
        cin >> numOfStudents;
        cin.ignore();

        vector<string> fullNames(numOfStudents);
        for (size_t idx = 0; idx < numOfStudents; idx++)
        {
            getline(cin, fullNames[idx]);
        }

        map<string, int> firstNamesCount = getFirstNamesCount(fullNames);
        for (size_t idx = 0; idx < numOfStudents; idx++)
        {
            string firstName = getFirstName(fullNames[idx]);
            cout << (firstNamesCount[firstName] > 1) ? fullNames[idx] : firstName;
        }
    }

    return 0;
}