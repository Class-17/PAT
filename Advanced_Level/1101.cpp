#include <bits/stdc++.h>
using namespace std;

void getRec(vector<int>& seq, vector<pair<int, int>>& rec) {
    int leftMax = 0, rightMin = INT_MAX;
    for(int i = 0; i < seq.size(); i++) {
        rec[i].first = leftMax;
        leftMax = max(seq[i], leftMax);
    }
    for(int i = seq.size() - 1; i >= 0; i--) {
        rec[i].second = rightMin;
        rightMin = min(seq[i], rightMin);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> seq(n);
    for(auto& elem : seq)
        cin >> elem;
    vector<pair<int, int>> rec(n);
    getRec(seq, rec);
    vector<int> ans;
    for(int i = 0; i < seq.size(); i++)
        if(seq[i] > rec[i].first && seq[i] < rec[i].second)
            ans.emplace_back(seq[i]);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << (i < ans.size() - 1 ? ' ' : '\0');
    cout << endl;
    return 0;
}