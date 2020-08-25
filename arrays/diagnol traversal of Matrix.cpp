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
using namespace std;
#define om map<int, vector<int> >
#define um unordered_map<int, vector<int> >



bool isValid(int i, int j, int R, int C)
{
	if (i < 0 || i >= R || j >= C || j < 0) return false;
	return true;
}

void diagonalOrder(int R, int C, int arr[][1000])
{
	/* through this for loop we choose each element of first column
	as starting point and print diagonal starting at it.
	arr[0][0], arr[1][0]....arr[R-1][0] are all starting points */
	for (int k = 0; k < R; k++)
	{
		cout << arr[k][0] << " ";
		int i = k - 1;  // set row index for next point in diagonal
		int j = 1;        //    set column index for next point in diagonal

		/* Print Diagonally upward */
		while (isValid(i, j, R, C))
		{
			cout << arr[i][j] << " ";
			i--;
			j++;    // move in upright direction
		}
		cout << endl;
	}

	/* through this for loop we choose each element of last row
	   as starting point (except the [0][c-1] it has already been
	   processed in previous for loop) and print diagonal starting at it.
	   arr[R-1][0], arr[R-1][1]....arr[R-1][c-1] are all starting points */

	//Note : we start from k = 1 to C-1;
	for (int k = 1; k < C; k++)
	{
		cout << arr[R - 1][k] << " ";
		int i = R - 2; // set row index for next point in diagonal
		int j = k + 1; // set column index for next point in diagonal

		/* Print Diagonally upward */
		while (isValid(i, j, R, C))
		{
			cout << arr[i][j] << " ";
			i--;
			j++; // move in upright direction
		}
		cout << endl;
	}
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int m, n;
	cin >> m >> n;
	int arr[1000][1000] = {0};
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n ; j++)
		{
			cin >> arr[i][j];
		}
	}

	diagonalOrder(m, n, arr);

	// for (int k = 1; k <= n + m - 1; k++)
	// {

	// 	for (int i = 0; i < m; i++)
	// 	{
	// 		for (int j = 0; j < n; j++)
	// 		{
	// 			if (i + j == k - 1) {
	// 				cout << arr[j][i] << " ";
	// 			}
	// 		}
	// 	}
	// 	cout << endl;
	// }



	return 0;


}



