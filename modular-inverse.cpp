/*
basics of modular inverse
(a * b) % m = ( (a % m) * ( b % m ) )%m
( a / b ) % m = ( ( a * ( b^-1 ) ) % m

according to fermat's little theorem
(a^m-1)%m === 1 % m
so ( a^m-2 ) % m === a^-1 % m
*/

#include <bits/stdc++.h>
using namespace std;

int power(int base, int p, int mod) {

	int result = 1;
	while (p) {
		if (p % 2 == 1) {
			result = (result * base) % mod;
			p--;
		}
		else {
			base = (base * base) % mod;
			p /= 2;
		}
	}

	return result % mod;
}

int main(int argc, char const *argv[])
{
	// input a and b and m
	// operation will be (a / b) % m

	cout << "Enter a b and m : " << endl;
	int a, b, m;
	cin >> a >> b >> m;

	// calculating b^-1 by ( a^m-2 ) % m
	int x = power(b, m - 2, m);

	// now we have (a * x)%m

	int ans = (a * x) % m;
	cout << ans << endl;


	return 0;
}