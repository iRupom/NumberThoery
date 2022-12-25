#include <bits/stdc++.h>
using namespace std;

int calculateGCD(int a, int b) {
	if (b == 0) return a;
	return calculateGCD(b, a % b);
}

int main(int argc, char const *argv[])
{
	int a, b;
	cout << "Enter two number : " << endl;

	cin >> a >> b;

	int gcd = calculateGCD(a, b);
	cout << "GCD of " << a << " and " << b << " is " << gcd << endl;

	// gcd with compiler method
	int gcd2 = __gcd(a, b);
	cout << "GCD with gcc compiler defined method is : " << gcd2 << endl;


	return 0;
}