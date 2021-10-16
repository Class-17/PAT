#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    vector<int> seq(k);
    for(auto& elem : seq) cin >> elem;
    vector<int> currSum(2, -1), maxSum(3);
    maxSum[0] = -1;
    maxSum[1] = seq[0];
    maxSum[2] = seq[seq.size() - 1];
    for(int i = 0; i < seq.size(); i++) {
        if(currSum[0] >= 0)
            currSum[0] += seq[i];
        else
            currSum[0] = currSum[1] = seq[i];
        if(currSum[0] > maxSum[0]) {
            maxSum[0] = currSum[0];
            maxSum[1] = currSum[1];
            maxSum[2] = seq[i];
        }
    }
    if(maxSum[0] == -1) maxSum[0] = 0;
    cout << maxSum[0] << ' ' << maxSum[1] << ' ' << maxSum[2] << endl;
    return 0;
}