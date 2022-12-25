#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 10000007

void binaryExpo(ll base, ll power) {

	ll result = 1;

	while (power) {
		if (power % 2 == 1) {
			result = (result * base) % mod;
			power--;
		}

		else {
			base = (base * base) % mod;
			power /= 2;
		}
	}

	cout << result << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--) {
		ll base, power;
		cin >> base >> power;

		binaryExpo(base, power);

	}

	return 0;
}