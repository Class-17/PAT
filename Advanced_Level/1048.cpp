#include <bits/stdc++.h>
using namespace std;

string findSolution(vector<int>& coins, int m) {
    int lo = 0, hi = coins.size() - 1;
    while (lo < hi) {
        if(coins[lo] + coins[hi] == m)
            return to_string(coins[lo]) + " " + to_string(coins[hi]);
        if(coins[lo] + coins[hi] < m) lo++;
        else                          hi--; 
    }
    return "No Solution";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for(auto& coin : coins)
        cin >> coin;
    sort(coins.begin(), coins.end());
    cout << findSolution(coins, m) << endl;
    return 0;
}