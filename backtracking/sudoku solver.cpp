
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
#include<map>
#include<set>
using namespace std;

bool canplace(int mat[][50], int i, int j, int n, int number) {
	//check for row
	for (int i = 0; i < n; i++)
	{
		if (mat[i][j] == number) {
			return false;
		}
	}
	//check for column
	for (int j = 0; j < n; j++)
	{
		if (mat[i][j] == number) {
			return false;
		}
	}
	//check for grid
	int rootN = sqrt(n);
	int start_x = (i / rootN) * rootN;
	int start_y = (j / rootN) * rootN;
	for (int x = start_x; x < start_x + rootN; x++) {
		for (int y = start_y; y < start_y + rootN; y++) {
			if (mat[x][y] == number) {
				return false;
			}

		}

	}

	return true;

}

bool solveSudoku(int mat[][50], int i, int j, int n) {
	if (i == n) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
		return true;
	}



	if (j == n) {
		return solveSudoku(mat, i + 1, 0, n);
	}
	//if the place is already filled then we skip it and move to next place
	if (mat[i][j] != 0) {
		return solveSudoku(mat, i, j + 1, n);
	}
	//recursive case
	//fill the current cell with possible options
	for (int number = 1; number <= n; number++) {
		if (canplace(mat, i, j, n, number)) {
			//assume
			mat[i][j] = number;
			bool couldWeSolve = solveSudoku(mat, i, j + 1, n);
			if (couldWeSolve) {
				return true;
			}


		}
	}
	mat[i][j] = 0;// else backtracking
	return false;

}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int mat[50][50] = {0};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}


	solveSudoku(mat, 0, 0, n);
	return 0;

}
