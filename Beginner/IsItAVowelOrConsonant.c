/*
Write a program to take a character (C) as input and check whether the given character is a vowel or a consonant.

NOTE:− Vowels are 'A', 'E', 'I', 'O', 'U'. Rest all alphabets are called consonants.

Input:
First line will contain the character C.
Output:
Print "Vowel" if the given character is a vowel, otherwise print "Consonant".

Constraints
C will be an upper case English alphabet
Sample Input:
Z
Sample Output:
Consonant

https://www.codechef.com/problems/VOWELTB
*/

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isVowel(char c)
{
    return 'A' == c || 'E' == c || 'I' == c || 'O' == c || 'U' == c ? TRUE : FALSE;
}