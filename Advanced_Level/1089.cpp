#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int>& ori, const vector<int>& seq) {
    for(int i = 0; i < ori.size(); i++)
        if(ori[i] != seq[i])  return false;
    return true;
}

void seqCopy(vector<int>& A, vector<int>& B) {
    for(int i = 0; i < A.size(); i++)
        A[i] = B[i];
}

bool InsertSort(vector<int>& ori, vector<int>& seq) {
    bool isRight = false;
    for(int i = 1; i < ori.size(); i++) {
        int t = ori[i], j = i;
        while(j > 0 && t < ori[j - 1]) {
            ori[j] = ori[j - 1];
            ori[--j] = t;
        }
        if(isRight) {
            seqCopy(seq, ori);
            return true;
        } 
        isRight = compare(ori, seq);
    }  
    return false;  
}

bool MergeSort(vector<int>& ori, vector<int>& seq) {
    bool isRight = false;
    for(int step = 2; step / 2 < ori.size(); step *= 2) {
        for(int i = 0; i < ori.size(); i += step)
            sort(ori.begin() + i, min(ori.begin() + i + step, ori.end()));
        if(isRight) {
            seqCopy(seq, ori);
            return true;
        } 
        isRight = compare(ori, seq);
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> oriA(n);
    vector<int> oriB(n);
    for(int i = 0; i < n; i++) {
        cin >> oriA[i];
        oriB[i] = oriA[i];
    }
    vector<int> seq(n);
    for(auto& elem : seq) 
        cin >> elem;
    if(InsertSort(oriA, seq))
        cout << "Insertion Sort\n";   
    else if(MergeSort(oriB, seq))
        cout << "Merge Sort\n";
    for(int i = 0; i < seq.size(); i++)
        cout << seq[i] << (i < seq.size() - 1 ? ' ' : '\n'); 
    return 0;
}