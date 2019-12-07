/*
Little kids, Jack and Evan like playing their favorite game Glass-and-Stone. Today they want to play something new and came across Twitter on their father's laptop.

They saw it for the first time but were already getting bored to see a bunch of sentences having at most 140 characters each. The only thing they liked to play with it is, closing and opening tweets.

There are N tweets on the page and each tweet can be opened by clicking on it, to see some statistics related to that tweet. Initially all the tweets are closed. Clicking on an open tweet closes it and clicking on a closed tweet opens it. There is also a button to close all the open tweets. Given a sequence of K clicks by Jack, Evan has to guess the total number of open tweets just after each click. Please help Evan in this game.

Input
First line contains two integers N K, the number of tweets (numbered 1 to N) and the number of clicks respectively (1 ≤ N, K ≤ 1000). Each of the following K lines has one of the following.
CLICK X , where X is the tweet number (1 ≤ X ≤ N)
CLOSEALL

Output
Output K lines, where the ith line should contain the number of open tweets just after the ith click.

Example
Input:
3 6
CLICK 1
CLICK 2
CLICK 3
CLICK 2
CLOSEALL
CLICK 1

Output:
1
2
3
2
0
1

Explanation:

Let open[x] = 1 if the xth tweet is open and 0 if its closed.
Initially open[1..3] = { 0 , 0 , 0 }. Here is the state of open[1..3] after each click and corresponding count of open tweets.

CLICK 1 : { 1, 0, 0 }, open count = 1
CLICK 2 : { 1, 1, 0 }, open count = 2
CLICK 3 : { 1, 1, 1 }, open count = 3
CLICK 2 : { 1, 0, 1 }, open count = 2
CLOSEALL : { 0, 0, 0 }, open count = 0
CLICK 1 : { 1, 0, 0 }, open count = 1

https://www.codechef.com/problems/TWTCLOSE
*/
#include <malloc.h>
#include <stdio.h>

enum TweetStatus
{
    CLOSE,
    OPEN
};

enum ActionType
{
    CLOSE_ALL,
    CLICK
};

struct Action
{
    enum ActionType actionType;
    int tweetId;
};

void resetTweetsStatus(int *tweetsStatus, int numOfTweets, enum TweetStatus resetValue)
{
    for (int idx = 0; idx < numOfTweets; ++idx)
    {
        tweetsStatus[idx] = resetValue;
    }
}

enum TweetStatus toggleTweetStatus(enum TweetStatus currStatus)
{
    return CLOSE == currStatus ? OPEN : CLOSE;
}

int *getOpenTweetCountAfterEveryAction(struct Action *actions, int numOfActions, int numOfTweets)
{
    int *tweetsStatus = (int *)calloc(numOfTweets, sizeof(int));
    int *tweetsCount = (int *)calloc(numOfActions, sizeof(int));

    for (int idx = 0; idx < numOfActions; ++idx)
    {
        struct Action currAction = actions[idx];
        if (CLOSE_ALL == currAction.actionType)
        {
            resetTweetsStatus(tweetsStatus, numOfTweets, CLOSE);
        }
        else
        {
            int currTweetId = currAction.tweetId;
            tweetsStatus[currTweetId - 1] = toggleTweetStatus(tweetsStatus[currTweetId - 1]);
            int countTillPrevAction = idx > 0 ? tweetsCount[idx - 1] : 0;
            tweetsCount[idx] = OPEN == tweetsStatus[currTweetId - 1] ? countTillPrevAction + 1 : countTillPrevAction - 1;
        }
    }
    
    free(tweetsStatus);
    return tweetsCount;
}

enum ActionType getActionType(char *action)
{
    return 'I' == action[2] ? CLICK : CLOSE_ALL;
}

int main()
{
    int numOfTweets, numOfActions;
    scanf("%d %d\n", &numOfTweets, &numOfActions);
    
    struct Action *actions = (struct Action *)malloc(sizeof(struct Action) * numOfActions);

    char buff[9];
    int tweetId;
    for (int idx = 0; idx < numOfActions; ++idx)
    {
        scanf("%s", buff);
        enum ActionType actionType = getActionType(buff);
        actions[idx].actionType = actionType;
        
        if (CLICK == actionType)
        {
            scanf("%d\n", &tweetId);
            actions[idx].tweetId = tweetId;
        }
        else
        {
            actions[idx].tweetId = 0;
        }
        
    }
    
    int *openTweetsCountAfterEveryAction = getOpenTweetCountAfterEveryAction(actions, numOfActions, numOfTweets);
    for (int idx = 0; idx < numOfActions; ++idx) {
        printf("%d\n", openTweetsCountAfterEveryAction[idx]);
    }
    
    return 0;
}