#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; 
    cin >> n >> k;
    map<string, set<int>> info;
    for (int i = 0; i < k; ++i) {
        int course_id, student_num;
        cin >> course_id >> student_num;
        for (int j = 0; j < student_num; ++j) {
            string name; cin >> name;
            info[name].insert(course_id);
        }
    }
    for (int i = 0; i < n; ++i) {
        string name; cin >> name;
        cout << name << " " << size(info[name]);
        for (auto &id : info[name])
            cout << " " << id;
        cout << '\n';
    }
    return 0;
}