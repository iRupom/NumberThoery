#include <bits/stdc++.h>
using namespace std;

void modulo(string s, int m) {
	/*
	string holds a big integer number that can not fit in normal long long.
	So we store this number as string and every time we checking the number if it
	can divisible by m
	*/

	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		ans = ans * 10 + (s[i] - '0');
		ans = ans % m;
	}

	if (ans % m == 0) cout << "Divisible" << endl;
	else cout << "Not divisible" << endl;
}

int main(int argc, char const *argv[])
{
	string s;
	cout << "Enter the number string : " << endl;
	cin >> s;
	cout << "Enter the number for modulo : " << endl;
	int m;
	cin >> m;

	modulo(s, m);

	return 0;
}