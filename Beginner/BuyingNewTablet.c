/*
Chef decided to buy a new tablet. His budget is B, so he cannot buy a tablet whose price is greater than B. Other than that, he only has one criterion — the area of the tablet's screen should be as large as possible. Of course, the screen of a tablet is always a rectangle.

Chef has visited some tablet shops and listed all of his options. In total, there are N available tablets, numbered 1 through N. For each valid i, the i-th tablet has width Wi, height Hi and price Pi.

Help Chef choose a tablet which he should buy and find the area of such a tablet's screen, or determine that he cannot buy any tablet.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and B.
N lines follow. For each i (1≤i≤N), the i-th of these lines contains three space-separated integers Wi, Hi and Pi.
Output
For each test case, print a single line. If Chef cannot buy any tablet, it should contain the string "no tablet" (without quotes). Otherwise, it should contain a single integer — the maximum area of the screen of a tablet Chef can buy.

Constraints
1≤T≤100
1≤N≤100
1≤B≤1,000,000
1≤Pi≤1,000,000 for each valid i
1≤Wi,Hi≤10,000 for each valid i
Example Input
3
3 6
3 4 4
5 5 7
5 2 5
2 6
3 6 8
5 4 9
1 10
5 5 10
Example Output
12
no tablet
25
Explanation
Example case 1: The first tablet (with screen area 3⋅4=12) is the best option for Chef, since Chef cannot afford the second one and the third one has a smaller screen.

Example case 2: Chef's budget is 6, but all tablets have higher prices, so Chef cannot buy any tablet.

Example case 3: The price of the only tablet is exactly equal to Chef's budget, so he is able to buy it.

https://www.codechef.com/problems/TABLET
*/

struct Tablet
{
    int width, height, price;
};

int getAreaOfLargestTablet(struct Tablet *tablets, int numOfTablets, int budget)
{
    int maxArea = -1;
    for (int idx = 0; idx < numOfTablets; idx++)
    {
        int currTabletArea;
        if (tablets[idx].price <= budget && (currTabletArea = tablets[idx].height * tablets[idx].width) > maxArea)
        {
            maxArea = currTabletArea;
        }
    }

    return maxArea;
}
