#include <bits/stdc++.h>
using namespace std;

int checkCycle(vector<int>& seq, vector<bool>& visited, int p) {
    if(visited[p] || seq[p] == p) return 0;
    int swapN = 1, i = p;
    do {
        if(seq[i] != 0) swapN++;
        else            swapN--;
        visited[i] = true;
        i = seq[i];
    } while (i != p);
    return swapN;
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
    vector<bool> visited(n);
    int total = 0;
    for(int i = 0; i < seq.size(); i++)
        total += checkCycle(seq, visited, i);
    cout << total << endl;
    return 0;
}