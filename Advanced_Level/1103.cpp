#include <bits/stdc++.h>
using namespace std;

int n, k, p, maxFacSum = 0;

vector<int> factors, temp;

void dfs(int hi, int loK, int sum, int facSum) {
    if(sum > n) return;
    if(hi == k) {
        if(sum == n && facSum > maxFacSum) {
            factors = temp;
            maxFacSum = facSum;
        }
        return;
    }
    for(int i = loK; i > 0 ; i--) {
        temp[hi] = i;
        dfs(hi + 1, i, sum + int(pow(i, p)), facSum + i);
    } 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> p;
    temp.resize(k);
    dfs(0, int(pow(n, 1.0 / p)), 0, 0);
    if(maxFacSum == 0) 
        cout << "Impossible\n";
    else {
        cout << n << " = ";
        for(int i = 0; i < factors.size() - 1; i++)
            cout << factors[i] << '^' << p << " + ";
        cout << factors[factors.size() - 1] << '^' << p << endl;
    }
    return 0;
}