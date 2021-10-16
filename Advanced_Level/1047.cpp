#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<vector<int>> courses(k);
    vector<char*> name_id(n);
    for (int i = 0; i < n; ++i) {
        int course_num;
        name_id[i] = new char(5);
        scanf("%s %d", name_id[i], &course_num);
        while (course_num--) {
            int course; cin >> course;
            courses[course - 1].push_back(i);
        }
    }
    for (int i = 0; i < k; ++i) {
        printf("%d %d\n", i + 1, courses[i].size());
        sort(begin(courses[i]), end(courses[i]), [&](auto a, auto b) {
            return strcmp(name_id[a], name_id[b]) < 0;
        });
        for (auto & name : courses[i])
            printf("%s\n", name_id[name]);
    }
    return 0;
}