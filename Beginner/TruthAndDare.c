/*
Ram and Shyam are playing a game of Truth and Dare. In this game, Shyam will ask Ram to perform tasks of two types:

Truth task: Ram has to truthfully answer a question.
Dare task: Ram has to perform a given task.
Each task is described by an integer. (If a truth task and a dare task are described by the same integer, they are still different tasks.) You are given four lists of tasks:

Tr,1,Tr,2,…,Tr,tr: the truth tasks Ram can perform.
Dr,1,Dr,2,…,Dr,dr: the dare tasks Ram can perform.
Ts,1,Ts,2,…,Ts,ts: the truth tasks Shyam can ask Ram to perform.
Ds,1,Ds,2,…,Ds,ds: the dare tasks Shyam can ask Ram to perform.
Note that the elements of these lists are not necessarily distinct, each task may be repeated any number of times in each list.

Shyam wins the game if he can find a task Ram cannot perform. Ram wins if he performs all tasks Shyam asks him to. Find the winner of the game.

Let's take an example where Ram can perform truth tasks 3, 2 and 5 and dare tasks 2 and 100, and Shyam can give him truth tasks 2 and 3 and a dare task 100. We can see that whichever truth or dare tasks Shyam asks Ram to perform, Ram can easily perform them, so he wins. However, if Shyam can give him dare tasks 3 and 100, then Ram will not be able to perform dare task 3, so Shyam wins.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer tr.
The second line contains tr space-separated integers Tr,1,Tr,2,…,Tr,tr.
The third line contains a single integer dr.
The fourth line contains dr space-separated integers Dr,1,Dr,2,…,Dr,dr.
The fifth line contains a single integer ts.
The sixth line contains ts space-separated integers Ts,1,Ts,2,…,Ts,ts.
The seventh line contains a single integer ds.
The eighth line contains ds space-separated integers Ds,1,Ds,2,…,Ds,ds.
Output
For each test case, print a single line containing the string "yes" if Ram wins the game or "no" otherwise.

Constraints
1≤T≤100
1≤tr,dr,ts,ds≤100
1≤Tr,i≤100 for each valid i
1≤Dr,i≤100 for each valid i
1≤Ts,i≤100 for each valid i
1≤Ds,i≤100 for each valid i
Example Input
4
2
1 2
3
1 3 2
1
2
2
3 2
2
1 2
3
1 3 2
1
2
3
3 2 4
3
3 2 5
2
2 100
1
2
1
100
2
1 2
3
1 3 2
1
2
3
3 2 2
Example Output
yes
no
yes
yes
Explanation
Example case 1: Ram's truth tasks are [1,2] and his dare tasks are [1,3,2]. Shyam's truth tasks are [2] and his dare tasks are [3,2]. Ram can perform all tasks Shyam gives him.

Example case 2: Ram's truth tasks are [1,2] and his dare tasks are [1,3,2]. Shyam's truth tasks are [2] and his dare tasks are [3,2,4]. If Shyam asks Ram to perform dare task 4, Ram will not be able to do it.

https://www.codechef.com/problems/TRUEDARE
*/
#define MAX_NUM_OF_TASKS 100

#include <stdio.h>

enum Boolean
{
    FALSE,
    TRUE
};

struct Tasks
{
    int tasks[MAX_NUM_OF_TASKS], numOfTasks;
};

int encodeTaskIdToIdx(int taskId)
{
    return taskId - 1;
}

void updateTasksOfRam(struct Tasks *tasksOfRam, enum Boolean *tasksRamCanDo)
{
    for (int idx = 0; idx < tasksOfRam->numOfTasks; idx++)
    {
        int taskIdx = encodeTaskIdToIdx(tasksOfRam->tasks[idx]);
        tasksRamCanDo[taskIdx] = TRUE;
    }
}

enum Boolean canRamDoTasksByShyam(struct Tasks *tasksByShyam, enum Boolean *tasksRamCanDo)
{
    int idx = 0;
    while (idx < tasksByShyam->numOfTasks && tasksRamCanDo[encodeTaskIdToIdx(tasksByShyam->tasks[idx])])
    {
        idx++;
    }

    return tasksByShyam->numOfTasks == idx ? TRUE : FALSE;
}

enum Boolean canRamWin(struct Tasks *truthTasksOfRam, struct Tasks *dareTasksOfRam, struct Tasks *truthTasksByShyam, struct Tasks *dareTasksByShyam)
{
    enum Boolean truthTasksRamCanDo[MAX_NUM_OF_TASKS] = {FALSE};
    enum Boolean dareTasksRamCanDo[MAX_NUM_OF_TASKS] = {FALSE};

    updateTasksOfRam(truthTasksOfRam, truthTasksRamCanDo);
    updateTasksOfRam(dareTasksOfRam, dareTasksRamCanDo);

    return canRamDoTasksByShyam(truthTasksByShyam, truthTasksRamCanDo) && canRamDoTasksByShyam(dareTasksByShyam, dareTasksRamCanDo);
}

int main()
{
    int numOfTruthTasksOfRam = 2, numOfDareTasksOfRam = 3;
    struct Tasks truthTasksOfRam = {{1, 2}, numOfTruthTasksOfRam};
    struct Tasks dareTasksOfRam = {{1, 3, 2}, numOfDareTasksOfRam};

    int numOfTruthTasksByShyam = 1, numOfDareTasksByShyam = 2;
    struct Tasks truthTasksByShyam = {{2}, 1};
    struct Tasks dareTasksByShyam = {{3, 2}, 2};

    enum Boolean ramWin = canRamWin(&truthTasksOfRam, &dareTasksOfRam, &truthTasksByShyam, &dareTasksByShyam);
    printf("%s\n", ramWin ? "yes" : "no");

    return 0;
}