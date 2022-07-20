#include <bits/stdc++.h>
using namespace std;

void findKthElem(vector<int>& seq, int lo, int hi, int k) {
    if(hi - lo <= 1) return;
    int pivot = seq[lo];
    int i = lo, j = hi;
    while (true) {
        while (seq[--j] > pivot) if(j == lo) break;
        while (seq[++i] < pivot) if(i == hi) break;
        if(i >= j) break;
        swap(seq[i], seq[j]);
    }
    swap(seq[j], seq[lo]);
    if(j + 1 < k)      findKthElem(seq, j + 1, hi, k);
    else if(j + 1 > k) findKthElem(seq, lo, j, k);
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> seq(n);
    for(auto& elem : seq) cin >> elem;
    findKthElem(seq, 0, seq.size(), seq.size() / 2);
    int lo = 0, hi = ceil(seq.size() / 2.0), sum = 0;
    while (lo < seq.size() / 2)
        sum += seq[hi++] - seq[lo++];
    if(seq.size() % 2 == 0)
        cout << "0 " << sum << endl;
    else 
        cout << "1 " << sum + seq[seq.size() / 2] << endl;
}