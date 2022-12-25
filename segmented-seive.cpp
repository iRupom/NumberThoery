#include <bits/stdc++.h>
using namespace std;


vector<int> primes;

void seive(int MAX) {
	int arr[MAX];
	memset(arr, 1, sizeof(arr));
	arr[0] = arr[1] = 0;
	for (int i = 2; i * i <= MAX; i++) {
		if (arr[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				arr[j] = 0;
			}
		}
	}

	for (int i = 2; i <= MAX; i++) {
		if (arr[i]) {
			primes.push_back(i);
		}
	}
}

void segmentedSeive(int left, int right) {
	if (left == 1) left++;
	int mx = right - left + 1;
	int arr[mx + 1];
	memset(arr, 1, sizeof(arr));

	for (int i = 0; primes[i]*primes[i] <= right; i++) {

		int ind = (left / primes[i]) * primes[i];
		if (ind < left) ind += primes[i];

		for (; ind <= right; ind += primes[i]) {
			arr[ind - left] = 0;
		}
	}

	for (int i = 0; i < mx; i++) {
		if (arr[i]) {
			cout << left + i << " ";
		}
	}

	cout << endl;
}

int main(int argc, char const *argv[])
{
	// I assume that maximum value of segement is 10^5
	// at first i run a seive function to calculate all the prime numbers in
	// the range

	seive(100000);

	int testCases;
	cin >> testCases;

	while (testCases--) {

		// taking Left and Right segment value
		int left, right;
		cin >> left >> right;
		segmentedSeive(left, right);
	}


	return 0;
}