#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n, k;
	cin >> m >> n >> k;
	vector<int> seq(n);
	auto check = [&]()->bool {
		vector<int> st;
		int p = 0;
		for (int i = 1; i <= n; ++i) {
			st.push_back(i);
			if (size(st) > m) return false;
			while (!st.empty() && st.back() == seq[p]) {
				st.pop_back();
				p++;
			}
		}
		return st.empty();	
	};
	for (int i = 0; i < k; ++i) {
		for (auto & x : seq) cin >> x;
		cout << (check() ? "YES" : "NO") << endl;
	}
	return 0;
}
