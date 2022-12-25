#include <bits/stdc++.h>
using namespace std;

void eulerPhi(int n) {
	// prime factorization
	int ans = n;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ans *= (i - 1);
			ans /= i;

			while (n % i == 0) {
				n /= i;
			}
		}
	}

	// if number itself a prime
	if (n > 1) {
		ans *= (n - 1);
		ans /= n;
	}

	cout << ans << endl;
}

int main(int argc, char const *argv[])
{

	int n;
	cin >> n;

	eulerPhi(n);


	return 0;
}