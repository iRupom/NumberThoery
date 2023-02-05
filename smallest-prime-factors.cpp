#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// find smallest primes factors of number from 2 to n
	int n; cin >> n;
	vector<int> spf(n + 1, 0);
	for (int i = 2; i <= n; i++) {
		spf[i] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			spf[j] = min(spf[j], i);
		}
	}

	for (auto x : spf) cout << x << " "; cout << endl;

	return 0;
}