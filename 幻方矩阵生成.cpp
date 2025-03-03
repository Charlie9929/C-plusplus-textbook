#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 40;
int magicSquare[MAXN][MAXN];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			magicSquare[i][j] = 0;
		}
	}
	int row = 1, col = (n + 1) / 2;
	magicSquare[row][col] = 1;

	for (int k = 2; k <= n * n; ++k) {
		int newrow, newcol;
		if (row == 1 && col != n) {
			newrow = n;
			newcol = col + 1;
		}
		else if (col == n && row != 1) {
			newrow = row - 1;
			newcol = 1;
		}
		else if (col == n && row == 1) {
			newrow = row + 1;
			newcol = col;

		}
		else {
			newrow = row - 1;
			newcol = col + 1;
			if (newrow < 1) newrow = n;
			if (newcol > n) newcol = 1;
			if (magicSquare[newrow][newcol] != 0) {
				newrow = row + 1;
				newcol = col;
			}
		}
		magicSquare[newrow][newcol] = k;
		row = newrow;
		col = newcol;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; j++) {
			if (j != n) {
				cout << magicSquare[i][j] << " ";
			}
			else {
				cout << magicSquare[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}