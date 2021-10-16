#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    map<int, pair<string, int>> stus; 
    while (N--) {
        int testN, num;
        string ID;
        cin >> ID >> testN >> num;
        stus.insert(make_pair(testN, make_pair(ID, num)));
    }
    cin >> N;
    while (N--) {
        int testN;
        cin >> testN;
        cout << stus[testN].first << " " << stus[testN].second << endl;
    }
    return 0;
}