
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

bool canPlace(int board[][10], int n, int x, int y) {

	//check for Column
	for (int k = 0; k < x; k++) {
		if (board[k][y] == 1) {
			return false;
		}
	}
	//check for Left Diag
	int i = x, j = y;
	while (i >= 0 and j >= 0) {
		if (board[i][j] == 1) {
			return false;
		}
		i--; j--;
	}

	//check for Right Diag
	i = x, j = y;
	while (i >= 0 and j < n) {
		if (board[i][j] == 1) {
			return false;
		}
		i--; j++;
	}
	return true;
}

bool NQueen(int n, int board[][10], int i) {
	//Base Case
	if (i == n) {
		//you have sucessfully placed queens in N columns
		//Print the board
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		// return true;
		//if in base case we return false instead of true then our code will continue to search for more possible configurations and hence we can print all cases
		cout << endl;

		return false;
	}
//recursive case
	//try to place the queen in the current row and call on the remaining part
	for (int j = 0; j < n; j++) {
		//check if ith , jth place is safe to keep the queen
		if (canPlace(board, n, i, j)) {
			//place the queen assuming i,j is the right position
			board[i][j] = 1;
			//
			bool nextQuennRakhPaenge = NQueen(n, board, i + 1);
			if (nextQuennRakhPaenge) {
				return true;
			}
			//if (nextQuennRakhPaenge) is false it means that i,j is not the right position
			board[i][j] = 0; //backtracking

		}


	}
	//we have checked for all places in the current row and couldn't place the queen
	return false;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int board[10][10] = {0};
	int n;
	cin >> n;

	NQueen(n, board, 0);

	return 0;

}
