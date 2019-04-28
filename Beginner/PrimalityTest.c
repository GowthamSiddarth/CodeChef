/*
Alice and Bob are meeting after a long time. As usual they love to play some math games. This times Alice takes the call and decides the game. The game is very simple, Alice says out an integer and Bob has to say whether the number is prime or not. Bob as usual knows the logic but since Alice doesn't give Bob much time to think, so Bob decides to write a computer program.

Help Bob accomplish this task by writing a computer program which will calculate whether the number is prime or not .

Input
The first line of the input contains T testcases, T lines follow

Each of T line contains an integer N which has to be tested for primality

Output
For each test case output in a separate line, "yes" if the number is prime else "no"

Constraints
1<=T<=20 1<=N<=10000 1<=M<=10000

Input:
5
23
13
20
1000
99991

Output:
yes
yes
no
no
yes

https://www.codechef.com/problems/PRB01
*/
#include <math.h>
#include <stdio.h>

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isPrime(int num)
{
    int limit = sqrt(num);
    for (int i = 2; i <= limit; i++)
    {
        if (0 == num % i)
            return FALSE;
    }

    return TRUE;
}

int main()
{
    int num = 99991;
    enum Boolean numIsPrime = isPrime(num);
    printf("%s\n", numIsPrime ? "yes" : "no");

    return 0;
}