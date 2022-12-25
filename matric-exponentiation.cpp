#include<bits/stdc++.h>
using namespace std;

#define N 101

void matrixMul(int resultMatrix[][N], int A[][N], int dimention) {
	int res[N][N];

	for (int i = 0; i < dimention; i++) {
		for (int j = 0; j < dimention; j++) {
			res[i][j] = 0;

			for (int k = 0; k < dimention; k++) {
				res[i][j] += resultMatrix[i][k] * A[k][j];
			}
		}
	}

	for (int i = 0; i < dimention; i++) {
		for (int j = 0; j < dimention; j++) {
			resultMatrix[i][j] = res[i][j];
		}
	}
}
void matrixExpo(int BaseMatrix[][N], int dimention, int power) {

	int Result[N][N];

	for (int i = 0; i < dimention; i++) {
		for (int j = 0; j < dimention; j++) {
			if (i == j) Result[i][j] = 1;
			else Result[i][j] = 0;
		}
	}

	while (power) {
		if (power % 2 == 1) {
			matrixMul(Result, BaseMatrix, dimention);
			power--;
		}
		else {
			matrixMul(BaseMatrix, BaseMatrix, dimention);
			power /= 2;
		}
	}

	for (int i = 0; i < dimention; i++) {
		for (int j = 0; j < dimention; j++) {
			BaseMatrix[i][j] = Result[i][j];
		}
	}


}

int main(int argc, char const *argv[])
{
	int power, dimention;
	cout << "Enter dimension of metrix : " << endl;

	cin >> dimention ;
	cout << "Power of the matrix : " << endl;

	cin >> power;

	int BaseMatrix[N][N];

	for (int i = 0; i < dimention; i++) {
		for (int j = 0; j < dimention; j++) {
			cin >> BaseMatrix[i][j];
		}
	}

	matrixExpo(BaseMatrix, dimention, power);

	// printing the matrix

	for (int i = 0; i < dimention; i++) {
		for (int j = 0; j < dimention; j++) {
			cout << BaseMatrix[i][j] << " ";
		}

		cout << endl;
	}

	return 0;
}