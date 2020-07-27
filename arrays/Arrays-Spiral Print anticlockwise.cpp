/*
Take as input a 2-d array. Print the 2-D array in spiral form anti-clockwise.

Input Format
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints
Both M and N are between 1 to 10.

Output Format
All M * N integers separated by commas with 'END' written in the end(as shown in example).

Sample Input
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Sample Output
11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END
Explanation
For spiral level anti-clockwise traversal, Go for first column-> last row ->last column-> first row
and then do the same traversal for the remaining matrix .
*/

#include<bits/stdc++.h>
using namespace std;


int main() {
	int m, n, i, j;
	cin >> m >> n;
	int a[m][n];
	int vis[m][n];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cin >> a[i][j];
			vis[i][j] = 0;
		}
	}
	int cnt = 0;
	i = 0;
	j = 0;
	string dir = "DOWN";
	while (1) {
		cout << a[i][j] << ", ";
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
				j++;
			}
		}
		else if (dir == "RIGHT") {
			if (j + 1 < n && !vis[i][j + 1]) {
				j++;
			}
			else {
				dir = "UP";
				i--;
			}


		}

		else if (dir == "UP") {
			if (i - 1 >= 0 && !vis[i - 1][j]) {
				i--;
			}
			else {
				dir = "LEFT";
				j--;
			}


		}
		else if (dir == "LEFT") {
			if (j - 1 >= 0 && !vis[i][j - 1]) {
				j--;
			}
			else {
				dir = "DOWN";
				i++;
			}


		}

	}
	cout << "END" << endl;

	return 0;
}