/*
Write a code which inputs two numbers m and n and creates a matrix of size m x n (m rows and n columns)
in which every elements is either X or 0. The Xs and 0s must be filled alternatively, the matrix should
have outermost rectangle of Xs, then a rectangle of 0s, then a rectangle of Xs, and so on.

Examples:

Input: m = 3, n = 3
Output: Following matrix
X X X
X 0 X
X X X

Input: m = 4, n = 5
Output: Following matrix
X X X X X
X 0 0 0 X
X 0 0 0 X
X X X X X

Input:  m = 5, n = 5
Output: Following matrix
X X X X X
X 0 0 0 X
X 0 X 0 X
X 0 0 0 X
X X X X X

Input:  m = 6, n = 7
Output: Following matrix
X X X X X X X
X 0 0 0 0 0 X
X 0 X X X 0 X
X 0 X X X 0 X
X 0 0 0 0 0 X
X X X X X X X
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include <utility>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
#include<map>
#include<set>
using namespace std;


int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int m, n, i, j;
		cin >> m >> n;
		char a[m][n];
		int vis[m][n];
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				vis[i][j] = 0;
			}
		}
		int cnt = 0;
		i = 0;
		j = 0;
		string dir = "DOWN";
		bool val = true; //for X
		int change = 0;
		while (1) {
			if (change == 4) {
				if (val == true) {
					val = false;
				}
				else {
					val = true;
				}
				change = 0;
			}
			if (val) {
				a[i][j] = 'X';
			}
			else {
				a[i][j] = '0';
			}

			// cout << a[i][j] << " ";
			vis[i][j] = 1;
			cnt++;

			if (cnt == m * n) {
				break;
			}

			if (dir == "DOWN") {
				if (i + 1 < m && !vis[i + 1][j]) {
					i++;
				}
				else {
					dir = "RIGHT";
					change++;
					j++;
				}
			}
			else if (dir == "RIGHT") {
				if (j + 1 < n && !vis[i][j + 1]) {
					j++;
				}
				else {
					dir = "UP";
					change++;
					i--;
				}


			}

			else if (dir == "UP") {
				if (i - 1 >= 0 && !vis[i - 1][j]) {
					i--;
				}
				else {
					dir = "LEFT";
					change++;
					j--;
				}


			}
			else if (dir == "LEFT") {
				if (j - 1 >= 0 && !vis[i][j - 1]) {
					j--;
				}
				else {
					dir = "DOWN";
					change++;
					i++;
				}


			}

		}
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				cout << a[i][j] << " ";

			}
			cout << endl;
		}

		return 0;


	}
}
