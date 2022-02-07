#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> courses(k);
    vector<string> name_id(n);
    for (int i = 0; i < n; ++i) {
        int course_num;
        cin >> name_id[i] >> course_num;
        while (course_num--) {
            int course; cin >> course;
            courses[course - 1].push_back(i);
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << i + 1 << ' ' << size(courses[i]) << '\n';
        sort(begin(courses[i]), end(courses[i]), [&](auto a, auto b) {
            return name_id[a] < name_id[b];});
        for (auto &name : courses[i])
            cout << name_id[name] << '\n';
    }
    return 0;
}