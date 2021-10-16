#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> cards(N);
    for(int i = 0; i < N; i++) {
        cin >> cards[i];
        cards[i] = abs(cards[i] - i - 1);
    }
    sort(cards.begin(), cards.end(), [](int a, int b) {
        return a > b;});

    int p = 0, frontDiff = -1, cnt = 0;
    while (p < cards.size()) {
        if(cards[p] == frontDiff) {
            cnt++;
            if(p + 1 == cards.size())
                cout << cnt;
        }
        else {
            if(cnt != 0)  {
                cout << cnt << endl;
                cnt = 0;
            }
            if(p + 1 < cards.size() && cards[p] == cards[p + 1]) {
                frontDiff = cards[p];
                cout << cards[p] << " ";
                cnt = 1;
            }
        }
        p++;
    }
    return 0;
}