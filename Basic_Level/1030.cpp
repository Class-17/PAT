#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p;
    cin >> n >> p;
    vector<long long> seq(n);
    for(auto& elem : seq) 
        cin >> elem;
    sort(seq.begin(), seq.end());
    int maxN = 0;
    for(int i = 0; i < seq.size(); i++)
        maxN = max(maxN, int(upper_bound(seq.begin() + i, seq.end(), 
                          seq[i] * p) - seq.begin() - i));
    cout << maxN << endl;
    return 0;
}