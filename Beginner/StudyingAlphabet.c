/*
Not everyone probably knows that Chef has younder brother Jeff. Currently Jeff learns to read.

He knows some subset of the letter of Latin alphabet. In order to help Jeff to study, Chef gave him a book with the text consisting of N words. Jeff can read a word iff it consists only of the letters he knows.

Now Chef is curious about which words his brother will be able to read, and which are not. Please help him!

Input
The first line of the input contains a lowercase Latin letter string S, consisting of the letters Jeff can read. Every letter will appear in S no more than once.

The second line of the input contains an integer N denoting the number of words in the book.

Each of the following N lines contains a single lowecase Latin letter string Wi, denoting the ith word in the book.

Output
For each of the words, output "Yes" (without quotes) in case Jeff can read it, and "No" (without quotes) otherwise.

Constraints
1 ≤ |S| ≤ 26
1 ≤ N ≤ 1000
1 ≤ |Wi| ≤ 12
Each letter will appear in S no more than once.
S, Wi consist only of lowercase Latin letters.
Subtasks
Subtask #1 (31 point): |S| = 1, i.e. Jeff knows only one letter.
Subtask #2 (69 point)	: no additional constraints
Example
Input:
act
2
cat
dog

Output:
Yes
No
Explanation
The first word can be read.

The second word contains the letters d, o and g that aren't known by Jeff.

https://www.codechef.com/problems/ALPHABET
*/
#define MAX_NUM_OF_LETTERS 26
#define MAX_WORD_SIZE 12
#define NUM_OF_ALPHABETS 26

#include <string.h>
#include <stdio.h>

enum Boolean
{
    FALSE,
    TRUE
};

void readLetters(char *letters, enum Boolean *lettersReadStatus)
{
    int idx = 0;
    while ('\0' != letters[idx])
    {
        lettersReadStatus[letters[idx] - 'a'] = TRUE;
        idx++;
    }
}

enum Boolean canReadWord(char *word, enum Boolean *lettersReadStatus)
{
    int idx = 0;
    while ('\0' != word[idx] && TRUE == lettersReadStatus[word[idx] - 'a'])
    {
        idx++;
    }

    return '\0' == word[idx] ? TRUE : FALSE;
}

int main()
{
    char letters[MAX_NUM_OF_LETTERS + 1];
    memcpy(letters, "act", 4);

    enum Boolean lettersReadStatus[NUM_OF_ALPHABETS] = {FALSE};
    readLetters(letters, lettersReadStatus);

    char word[MAX_WORD_SIZE + 1];
    memcpy(word, "dog", 4);
    
    enum Boolean res = canReadWord(word, lettersReadStatus);
    printf("%s\n", res ? "Yes" : "No");

    return 0;
}