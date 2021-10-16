#include <bits/stdc++.h>
using namespace std;

double getScore(int x, int y) {
    return INT_MAX - (x * x + y * y);
}

int main()
{
    int N;
    cin >> N;
    pair<double, string> cham(0, "None");
    pair<double, string> rookie(INT_MAX, "None");
    while (N--) {
        pair<double, string> player;
        int x, y;
        cin >> player.second >> x >> y;
        player.first = getScore(x, y);
        cham = max(cham, player);
        rookie = min(rookie, player);
    }
    cout << cham.second << ' ' << rookie.second << endl;
    return 0;
}