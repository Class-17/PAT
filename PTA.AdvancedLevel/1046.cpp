#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, total = 0;
    cin >> N;
    vector<int> dists(N + 1);
    dists[0] = 0;
    for(int i = 1; i < dists.size(); i++) {
        cin >> dists[i];
        total += dists[i];
        dists[i] = total;
    }
    cin >> N;
    while (N--) {
        int l, r;
        cin >> l >> r;
        if(l > r) swap(l, r);
        int leftDist = dists[r - 1] - dists[l - 1];
        cout << min(leftDist, total - leftDist) << endl;
    }
    return 0;
}