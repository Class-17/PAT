#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string num; int k;
    cin >> num >> k;
    auto transe = [&]() {
        for (int i = 0; i < k; i++) {
            auto reNum = num;
            reverse(begin(reNum), end(reNum));
            if (num == reNum) return i;
            int cast = 0;
            for (int i = num.size() - 1; i >= 0; --i) {
                int temp = num[i] - '0' + reNum[i] - '0' + cast;
                num[i] = temp % 10 + '0';
                cast = temp / 10;
            }
            if (cast > 0) num.insert(0, 1, cast + '0');
        }
        return k;
    };
    int step = transe();
    cout << num << endl << step << endl;
    return 0;
}