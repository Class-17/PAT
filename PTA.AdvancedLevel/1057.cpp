#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5;

struct BIT {
    int arr[MAXN + 1];

    BIT() {memset(arr, 0, MAXN);}

    int lowbit(int x) {
        return x & (-x);
    }

    void update(int x, int val) {
        for (int i = x; i <= MAXN; i += lowbit(i))
            arr[i] += val;
    }

    int get_sum(int x) {
        int sum = 0;
        for (int i = x; i > 0; i -= lowbit(i))
            sum += arr[i];
        return sum;
    }
} seq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> st;
    while (n--) {
        string op; cin >> op;
        if (op == "Pop") {
            if (st.empty()) cout << "Invalid" << endl;
            else {
                seq.update(st.back(), -1);
                cout << st.back() << endl;
                st.pop_back();
            }
        }
        else if (op == "PeekMedian") {
            auto find_median = [&]()->string {
                if (st.empty()) return "Invalid";
                int median = (st.size() + 1) / 2;
                int lo = 1, hi = MAXN;
                while (lo < hi) {
                    int mid = lo + (hi - lo) / 2;
                    int sum = seq.get_sum(mid);
                    if (sum < median) lo = mid + 1;
                    else              hi = mid;
                }
                return to_string(lo);
            };
            cout << find_median() << endl;
        }
        else {
            int num; cin >> num;
            seq.update(num, 1);
            st.push_back(num);
        }
    }
    return 0;
}