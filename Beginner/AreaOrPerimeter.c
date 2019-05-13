/*
Write a program to obtain length (L) and breadth (B) of a rectangle and check whether its area is greater or perimeter is greater or both are equal.

Input:
First line will contain the length (L) of the rectangle.
Second line will contain the breadth (B) of the rectangle.
Output:
Output 2 lines.

In the first line print "Area" if area is greater otherwise print "Peri" and if they are equal print "Eq".(Without quotes).

In the second line print the calculated area or perimeter (whichever is greater or anyone if it is equal).

Constraints
1≤L≤1000
1≤B≤1000
Sample Input:
1
2
Sample Output:
Peri
6

EXPLANATION:
Area = 1 * 2 = 2

Peri = 2(1 + 2) = 6

Since Perimeter is greater than Area, hence the output is

Peri
6

https://www.codechef.com/problems/AREAPERI
*/
#include <stdio.h>

int getAreaOfRectangle(int length, int width)
{
    return length * width;
}

int getPerimeterOfRectangle(int length, int width)
{
    return 2 * (length + width);
}

int main()
{
    int length = 1, width = 2;
    int areaOfRectangle = getAreaOfRectangle(length, width);
    int perimeterOfRectangle = getPerimeterOfRectangle(length, width);

    if (areaOfRectangle > perimeterOfRectangle)
    {
        printf("Area\n%d", areaOfRectangle);
    }
    else if (areaOfRectangle < perimeterOfRectangle)
    {
        printf("Peri\n%d", perimeterOfRectangle);
    }
    else
    {
        printf("Eq\n%d", areaOfRectangle);
    }

    return 0;
}