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
    int maxN = 0, lo = 0, hi = 0;
    while (lo < n && hi < n) {
        while (hi < n && seq[hi] <= seq[lo] * p)
            hi++;
        maxN = max(maxN, hi - lo);
        lo++;
    }
    cout << maxN << endl;
    return 0;
}