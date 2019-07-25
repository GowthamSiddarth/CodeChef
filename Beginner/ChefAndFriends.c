/*
Chef decided to find the connections with all of his friends in an unnamed social network. He calls a user of the social network his friend if there is a common substring of the string "chef" and the nickname of that user with length ≥ 2.

Given a list of users of the social network, compute the number of Chef's friends.

Input
The first line of the input contains a single integer N denoting the number of users in the social network.
N lines follow. Each of these lines contains a single string u denoting the nickname of one user.
Output
Print a single line containing one integer — the number of Chef's friends.

Constraints
1 ≤ N ≤ 5,000
3 ≤ |u| ≤ 20
each character of each user's nickname is either a lowercase English letter ('a'-'z') or '.'
the first character of each user's nickname is a lowercase English letter
Subtasks
Subtask #1 (100 points): original constraints

Example
Input:

4
gennady.korotkevich
kefaa
fhlasek
chemthan

Output:

3
Explanation
gennady.korotkevich is a friend to Chef because he has "ch" at the end of his nickname, which is also a substring of "chef" with length 2
the common substring with kefaa is "ef" and the common substring with chemthan is "che"

https://www.codechef.com/problems/FRK
*/