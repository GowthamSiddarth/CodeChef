/*
The citizens of Byteland regularly play a game. They have blocks each denoting some integer from 0 to 9. These are arranged together in a random manner without seeing to form different numbers keeping in mind that the first block is never a 0. Once they form a number they read in the reverse order to check if the number and its reverse is the same. If both are same then the player wins. We call such numbers palindrome

Ash happens to see this game and wants to simulate the same in the computer. As the first step he wants to take an input from the user and check if the number is palindrome and declare if the user wins or not 

Input
The first line of the input contains T, the number of test cases. This is followed by T lines containing an integer N.

Output
For each input output "wins" if the number is a palindrome and "losses" if not.

Constraints
1<=T<=20 
1<=N<=10000 
Input:
3
331
666
343

Output:
losses
wins
wins

https://www.codechef.com/problems/PALL01
*/
#include <stdio.h>

enum Boolean
{
    FALSE,
    TRUE
};

int reverse(int num)
{
    int sum = 0;
    while (num)
    {
        sum = sum * 10 + num % 10;
        num = num / 10;
    }

    return sum;
}

enum Boolean isPalindrome(int num)
{
    return num == reverse(num) ? TRUE : FALSE;
}

int main()
{
    int num = 343;
    enum Boolean res = isPalindrome(num);

    switch (res)
    {
    case TRUE:
        printf("wins\n");
        break;

    case FALSE:
        printf("losses\n");
        break;
    }

    return 0;
}