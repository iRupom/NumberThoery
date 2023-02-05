#include <bits/stdc++.h>
using namespace std;


const int N = 1e6 + 9;
int spf[N];

int32_t main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 1; i < N; i++) {
		spf[i] = i;
	}

	for (int i = 2; i < N; i++) {
		for (int j = i; j < N; j += i) {
			spf[j] = min(spf[j], i);
		}
	}

	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		vector<int> ans;

		while (n > 1) {
			ans.push_back(spf[n]);
			n /= spf[n];
		}

		for (auto x : ans) cout << x << " "; cout << endl;
	}

	return 0;
}