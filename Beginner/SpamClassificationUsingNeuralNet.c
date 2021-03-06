/*
Neural nets are extremely popular in the Machine Learning domain. A neural net is composed of multiple layers. It has an input layer in which you input the parameter x (the input of the program). The input is then passed through multiple hidden layers, finally getting one output at the final layer, called the output layer.

We have a very simple neural net, which consist of N hidden layers. Each layer contains one neuron. Each neuron has two values associated with it: wi, and bi, denoting the weight and the bias of the neuron. If you give the neuron an input of x, it produces an output of (wi * x) + bi.

Thus, an input x gets transformed by the neural net as follows. The first hidden neuron takes the input x and produces y = w1 * x + b1, which acts as the input for the second neuron. Then, the second neuron takes input y and produces an output of z = w2 * y + b2. This keeps happening and you get a single output at the end from the N-th neuron.

There are some users and we want to find if they are spamming or not. They have integer user-ids, which range from minX to maxX (both inclusive). So we take each of these user-ids and feed it as input to the first layer of the neural net. If the final output is even, then that user is not a spammer, otherwise, the user is a spammer. You have to count the number of non-spammers and spammers.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, minX, maxX.
Each of the next N lines contains two space-separated integers wi and bi denoting the weight and the bias of the i-th neuron.
Output
For each test case, output two space-separated integers denoting the number of non-spammers and the number of spammers, respectively.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ minX ≤ maxX ≤ 109
1 ≤ wi, bi ≤ 109
Example
Input
3
1 1 2
1 2
2 1 4
2 4
2 3
3 2 1000000000
2 4
2 2
5 4

Output
1 1
0 4
999999999 0
Explanation
Example 1. There is a single neuron with weight = 1 and bias = 2. Let us check the output for x = 1: w * x + b = 1 * 1 + 2 = 3. Output for x = 2 would be 2 * 1 + 2 = 4. You can see that one of these is even and the other is odd. So, there is one spammer and one non-spammer.

Example 2. There are two neurons with weights 2 each, but bias 4, 3 respectively.

x = 1, y = 2 * 1 + 4 = 6. z = 2 * 6 + 3 = 15
x = 2, y = 2 * 2 + 4 = 8. z = 2 * 8 + 3 = 19
x = 3, y = 2 * 3 + 4 = 10. z = 2 * 10 + 3 = 23
x = 4, y = 2 * 4 + 4 = 12. z = 2 * 12 + 3 = 27
You can see that all of these are odd and hence signify that they are spammers. So, there are 0 non-spammers and 4 spammers.

https://www.codechef.com/problems/SPAMCLAS
*/
#define MAX_NUM_OF_LAYERS 100000

#include <stdio.h>

enum UserType
{
    SPAM,
    NON_SPAM
};

enum Boolean
{
    FALSE,
    TRUE
};

enum Boolean isEven(int num)
{
    return 0 == num % 2;
}

enum Boolean isOutputEven(int weight, enum Boolean isInputEven, int bias)
{
    if (isEven(weight))
    {
        return isEven(bias);
    }
    else if (isEven(bias))
    {
        return isInputEven;
    }
    else
    {
        return !isInputEven;
    }
}

enum UserType getUserType(int *weights, int *bias, int numOfLayers, enum Boolean isInputEven)
{
    enum Boolean outputEven = isInputEven;
    for (int idx = 0; idx < numOfLayers; idx++)
    {
        outputEven = isOutputEven(weights[idx], outputEven, bias[idx]);
    }

    return outputEven ? NON_SPAM : SPAM;
}

int getNumOfOddsInRange(int min, int max)
{
    int numOfItems = max - min + 1;
    return isEven(numOfItems) ? numOfItems / 2 : !isEven(min) ? numOfItems / 2 + 1 : numOfItems / 2;
}

void countSpammersAndNonSpammers(int *weights, int *bias, int numOfLayers, int minInput, int maxInput, int *spamCount, int *nonSpamCount)
{
    enum UserType oddInputUserType = getUserType(weights, bias, numOfLayers, FALSE);
    enum UserType evenInputUserType = getUserType(weights, bias, numOfLayers, TRUE);

    int numOfOddsInRange = getNumOfOddsInRange(minInput, maxInput);
    int numOfEvensInRange = (maxInput - minInput + 1) - numOfOddsInRange;

    *spamCount = (SPAM == oddInputUserType) * numOfOddsInRange + (SPAM == evenInputUserType) * numOfEvensInRange;
    *nonSpamCount = (NON_SPAM == oddInputUserType) * numOfOddsInRange + (NON_SPAM == evenInputUserType) * numOfEvensInRange;
}

int main()
{
    int numOfLayers = 3, minInput = 2, maxInput = 1000000000;
    int weights[MAX_NUM_OF_LAYERS] = {2, 2, 5};
    int bias[MAX_NUM_OF_LAYERS] = {4, 2, 4};

    int spamCount, nonSpamCount;
    countSpammersAndNonSpammers(weights, bias, numOfLayers, minInput, maxInput, &spamCount, &nonSpamCount);

    printf("%d %d\n", nonSpamCount, spamCount);

    return 0;
}