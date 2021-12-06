#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> chain(n + 1);
    chain[0] = 0;
    for(int i = 1; i < chain.size(); i++) {
        cin >> chain[i];
        chain[i] += chain[i - 1];
    }
    vector<pair<int, int>> solutions;
    int minPay = INT_MAX;
    for(int i = 1; i < chain.size(); i++) {
        int obj = chain[i - 1] + m;
        int loc = lower_bound(chain.begin() + i, chain.end(), obj)
                   - chain.begin();
        if(loc == chain.size()) continue;
        if(chain[loc] - chain[i - 1] == minPay)
            solutions.emplace_back(make_pair(i, loc));
        else if(chain[loc] - chain[i - 1] < minPay) {
            minPay = chain[loc] - chain[i - 1];
            solutions.clear();
            solutions.emplace_back(make_pair(i, loc));
        }
    }
    for(auto& solution : solutions)
        cout << solution.first << '-' << solution.second << endl;
    return 0;
}