#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;

	// count how many divisors for each number from 1 to n
	int divs[n + 1];
	memset(divs, 0, sizeof(divs));
	for (int i = 1; i <= 100; i++) {
		for ( int j = i; j <= n; j += i) {
			divs[j]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << i << " : " << divs[i] << "\n";
	}


	return 0;
}
