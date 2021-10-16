/*
1070 Mooncake (25point(s))

Code Size 16 KB    Time limit 150 ms    Memory Limit 64 MB

Mooncake is a Chinese bakery product traditionally eaten during the Mid-Autumn Festival. 
Many types of fillings and crusts can be found in traditional mooncakes according to the 
region's culture. Now given the inventory amounts and the prices of all kinds of the mooncakes, 
together with the maximum total demand of the market, you are supposed to tell the maximum 
profit that can be made.

Note: partial inventory storage can be taken. The sample shows the following situation: given 
three kinds of mooncakes with inventory amounts being 180, 150, and 100 thousand tons, and the 
prices being 7.5, 7.2, and 4.5 billion yuans. If the market demand can be at most 200 thousand 
tons, the best we can do is to sell 150 thousand tons of the second kind of mooncake, and 50 
thousand tons of the third kind. Hence the total profit is 7.2 + 4.5/2 = 9.45 (billion yuans).

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive 
integers N (≤1000), the number of different kinds of mooncakes, and D (≤500 thousand tons), 
the maximum total demand of the market. Then the second line gives the positive inventory 
amounts (in thousand tons), and the third line gives the positive prices (in billion yuans) 
of N kinds of mooncakes. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the maximum profit (in billion yuans) in one line, accurate up 
to 2 decimal places.

Sample Input:

3 200

180 150 100
7.5 7.2 4.5

Sample Output:

9.45

*/

#include<cstdio>
#include<algorithm>
using namespace std;
struct mooncake
{
    double record;
    double worth;
    double price;
}per[1000];

bool cmp(mooncake a, mooncake b)
{
    return a.price > b.price;
}

int main()
{
    int N, D;
    double profit = 0.0;
    scanf("%d %d", &N, &D);
    for(int i = 0; i < N; i++)
        scanf("%lf", &per[i].record);
    for(int i = 0; i < N; i++)
    {
        scanf("%lf", &per[i].worth);
        per[i].price = per[i].worth / per[i].record;
    }
    sort(per, per + N, cmp);
    for(int i = 0; i < N && D > 0; i++)
    {
        if(per[i].record > D)
        {
            profit += per[i].price * D;
            break;
        }
        else
        {
            profit += per[i].worth;
            D -= per[i].record;
        }     
    }
    printf("%.2lf\n", profit);
    return 0;
}