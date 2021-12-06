#include <bits/stdc++.h>
using namespace std;

struct Info {
    string name;
    double score;
    int num;
    Info(string name, double score = 0, int num = 0) :
        name(name), score(score), num(num) {}
    friend bool operator < (Info A, Info B) {
        if(int(A.score) == int(B.score))
            if(A.num == B.num) return A.name < B.name;
            else               return A.num < B.num;
        return A.score > B.score;
    }
};


int main()
{
    int N;
    cin >> N;
    vector<Info> school;
    map<string, int> schName;

    for(int i = 0; i < N; i++) {
        string ID, schoolName;
        double score;
        cin >> ID >> score >> schoolName;

        for(auto& c : schoolName) c = tolower(c);
        if(ID[0] == 'T') score *= 1.5;
        if(ID[0] == 'B') score /= 1.5;

        if(schName.find(schoolName) != schName.end()) {
            school[schName[schoolName]].score += score;
            school[schName[schoolName]].num++;
        }
        else {
            Info sch(schoolName, score, 1);
            school.emplace_back(sch);
            schName.insert(make_pair(schoolName, school.size() - 1));
        }      
    }

    sort(school.begin(), school.end());
    cout << school.size() << endl;
    for(int i = 0, rank = 1; i < school.size(); i++) {
        if(i != 0 && (int(school[i].score) < int(school[i - 1].score)))
            rank = i + 1;
        cout << rank << ' ' << school[i].name << ' ' 
             << int(school[i].score) << ' ' << school[i].num << endl;
    }
    return 0;
}