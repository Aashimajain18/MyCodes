/*You are given an empty chess board of size N*N. Find the number of ways to place N queens on the board, such that no two queens can kill each other in one move. A queen can move vertically, horizontally and diagonally.

Input Format
A single integer N, denoting the size of chess board.

Constraints
1<=N<=11

Output Format
A single integer denoting the count of solutions.

Sample Input
4
Sample Output
2*/

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

bool canPlace(int board[][100], int n, int x, int y) {

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

int count_NQueen(int n, int board[][100], int i) {
	//Base Case
	if (i == n) {
		//Print the board
		// for(int x=0;x<n;x++){
		// 	for(int y=0;y<n;y++){
		// 		cout<<board[x][y]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;
		return 1;
	}
	//Rec Case
	//Try to place queen at every column/position in the current row
	int cnt = 0;
	for (int j = 0; j < n; j++) {
		if (canPlace(board, n, i, j)) {
			board[i][j] = 1;
			int aageKaCount = count_NQueen(n, board, i + 1);
			cnt += aageKaCount;
			board[i][j] = 0;
		}
	}
	return cnt;
}


bool NQueen(int n, int board[][100], int i) {
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


	int board[100][100] = {0};
	int n;
	cin >> n;

	cout << count_NQueen(n, board, 0);

	return 0;

}
