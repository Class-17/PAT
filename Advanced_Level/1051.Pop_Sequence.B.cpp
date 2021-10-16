#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n, k;
	cin >> m >> n >> k;
	vector<int> seq(n);
	auto check = [&]()->bool {
		vector<int> right(n);
        set<int> nums;
		int right_max = 0;
		for (int i = n - 1; i >= 0; --i) {
            auto it = nums.upper_bound(seq[i]);
			right[i] = (it != end(nums) ? *it : 0);
			nums.insert(seq[i]);
		}
		int cap = 0, left_max = 0;
		for (int i = 0; i < n; ++i) {
			if (seq[i] - cap  > m) return false;
			if (seq[i] < right[i] && left_max > right[i]) return false;
			left_max = max(seq[i], left_max);
			cap++;
		}
		return true;
	};
	for (int i = 0; i < k; ++i) {
		for (auto & x : seq) cin >> x;
		cout << (check() ? "YES" : "NO") << endl;
	}
	return 0;
}
