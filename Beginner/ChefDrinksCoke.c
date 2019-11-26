/*
Chef went to the store in order to buy one can of coke. In the store, they offer N cans of coke (numbered 1 through N). For each valid i, the current temperature of the i-th can is Ci and its price is Pi.

After buying a can of coke, Chef wants to immediately start walking home; when he arrives, he wants to immediately drink the whole can. It takes Chef M minutes to get home from the store.

The ambient temperature outside is K. When a can of coke is outside, its temperature approaches the ambient temperature. Specifically, if its temperature is t at some point in time:

if t>K+1, then one minute later, its temperature will be t−1
if t<K−1, then one minute later, its temperature will be t+1
if K−1≤t≤K+1, then one minute later, its temperature will be K
When Chef drinks coke from a can, he wants its temperature to be between L and R (inclusive). Find the cheapest can for which this condition is satisfied or determine that there is no such can.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains five space-separated integers N, M, K, L and R.
N lines follow. For each i (1≤i≤N), the i-th of these lines contains two space-separated integers Ci and Pi.
Output
For each test case, print a single line containing one integer — the price of the can Chef should buy, or −1 if it is impossible to buy a can such that Chef's condition is satisfied.

Constraints
1≤T≤1,000
1≤N≤100
1≤M≤100
|Ci|≤50 for each valid i
|K|≤50
−50≤L≤R≤50
1≤Pi≤106 for each valid i
Example Input
2
3 2 5 4 6
1 6
2 8
8 10
3 5 10 20 30
21 20
22 22
23 23
Example Output
8
-1
Explanation
Example case 1: Chef should buy the second can (with price 8), even though the first can is cheaper. If Chef bought the first can, its temperature would be 3 when he got home, and that is outside the range [4,6].

Example case 2: No matter which can Chef buys, when he gets home, its temperature will be less than 20, so there is no suitable can available in the store.

https://www.codechef.com/problems/COKE
*/
#define MAX_NUM_OF_CANS 100

#include <limits.h>
#include <stdio.h>

struct CokeCan
{
    int initTemp, price;
};

int min(int x, int y)
{
    return x < y ? x : y;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int getTempAfterReachingHome(int currTemp, int minutesToReachHome, int ambientTemp)
{
    return currTemp <= ambientTemp ? min(currTemp + minutesToReachHome, ambientTemp) : max(currTemp - minutesToReachHome, ambientTemp);
}

int getPriceOfCanChefShouldBuy(struct CokeCan *cokeCans, int numOfCans, int minutesToReachHome, int ambientTemp, int lowTemp, int highTemp)
{
    int minPrice = INT_MAX;
    for (int idx = 0; idx < numOfCans; idx++)
    {
        struct CokeCan currCan = cokeCans[idx];
        if ((lowTemp > ambientTemp && currCan.initTemp <= ambientTemp) || (highTemp < ambientTemp && currCan.initTemp >= ambientTemp))
        {
            continue;
        }

        int tempAfterReachingHome = getTempAfterReachingHome(currCan.initTemp, minutesToReachHome, ambientTemp);
        if (tempAfterReachingHome >= lowTemp && tempAfterReachingHome <= highTemp && currCan.price < minPrice)
        {
            minPrice = currCan.price;
        }
    }

    return INT_MAX == minPrice ? -1 : minPrice;
}

int main()
{
    struct CokeCan cokeCans[MAX_NUM_OF_CANS] = {{21, 20}, {22, 22}, {23, 23}};
    int numOfCans = 3, minutesToReachHome = 5, ambientTemp = 10, lowTemp = 20, highTemp = 30;

    int priceOfCanChefShouldBuy = getPriceOfCanChefShouldBuy(cokeCans, numOfCans, minutesToReachHome, ambientTemp, lowTemp, highTemp);
    printf("%d\n", priceOfCanChefShouldBuy);

    return 0;
}