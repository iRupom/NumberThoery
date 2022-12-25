#include <bits/stdc++.h>
using namespace std;

#define N 3

int result[N][N];


void matrixMultiply(int result[][N], int A[][N], int dimension) {
	int res[N][N];

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			res[i][j] = 0;
			for (int k = 0; k < dimension; k++) {
				res[i][j] += result[i][k] * A[k][j];
			}
		}
	}

	// storing multiplication result in result matrix

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			result[i][j] = res[i][j];
		}
	}
}

void calcFiboWithMatrix(int base[][N], int dimension, int power) {

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			if (i == j) result[i][j] = 1;
			else result[i][j] = 0;
		}
	}

	while (power) {
		if (power % 2 == 1) {
			matrixMultiply(result, base, dimension);
			power--;
		}
		else {
			matrixMultiply(base, base, dimension);
			power /= 2;
		}
	}
}

int main(int argc, char const *argv[])
{
	int a = 0, b = 1, n;
	int dimension = 2;
	int base[N][N];

	cout << "Give me N : " << endl;
	cin >> n;

	base[0][0] = 0;
	base[0][1] = base[1][0] = base[1][1] = 1;

	calcFiboWithMatrix(base, dimension, n - 1);

	cout << "N-th element in fibonacci series is : " << endl;
	int ans = result[0][1] * a + result[1][1] * b;
	cout << ans << endl;


	return 0;
}