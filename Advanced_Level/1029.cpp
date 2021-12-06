#include <bits/stdc++.h>
using namespace std;

int getMedian(vector<int>& seqA, vector<int>& seqB) {
    int pA = 0, pB = 0, p = 0, median = 0;
    while (p <= (seqA.size() + seqB.size() - 1) / 2) {
        if(pA < seqA.size() && pB < seqB.size()) {
            if(seqA[pA] < seqB[pB]) median = seqA[pA++];
            else                    median = seqB[pB++];
        }
        else if(pA < seqA.size()) median = seqA[pA++];
        else if(pB < seqB.size()) median = seqB[pB++];
        p++;
    }
    return median;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> seqA(n); 
    for(auto& elem : seqA) cin >> elem;
    cin >> n;
    vector<int> seqB(n); 
    for(auto& elem : seqB) cin >> elem;
    cout << getMedian(seqA, seqB) << endl;
    return 0;
}