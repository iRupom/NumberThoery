#include <bits/stdc++.h>
using namespace std;

bool arr[1000];

void seive(int n) {
	memset(arr, 1, sizeof(arr));

	int limit = sqrt(n);

	arr[0] = arr[1] = false;

	for (int i = 2; i <= limit; i++) {
		if (arr[i]) {
			for (int j = i * i; j <= n; j += i) {
				arr[j] = false;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (arr[i]) cout << i << " ";
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	seive(n);

	return 0;
}