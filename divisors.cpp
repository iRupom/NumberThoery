#include <bits/stdc++.h>
using namespace std;

set<int> s;

void countDivisors(int n) {
	for (int i = 1; i < sqrt(n); i++) {
		if (n % i == 0) {
			int x = i;
			int y = n / x;

			s.insert(x);
			s.insert(y);
		}
	}
}

int main(int argc, char const *argv[])
{

	cout << "Enter the number : " << endl;
	int n;
	cin >> n;

	countDivisors(n);

	cout << "Number of divisors of " << n << " is " << s.size() << endl;

	cout << "Divisors are : " << endl;

	for (auto t : s) cout << t << endl;

	return 0;
}