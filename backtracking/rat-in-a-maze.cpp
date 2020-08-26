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

bool rat_in_maze(char maze[][10], int sol[][10], int i, int j, int m, int n) {
	if (i == m && j == n) {
		sol[m][n] = 1;
		//print the path
		for (int i = 0; i <= m; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		return true;
	}
//rat should not go outside the grid
	if (i > m || j > n) {
		return false;
	}
	if (maze[i][j] == 'X') {
		return false;
	}
//assume solution exits through current cell
	sol[i][j] = 1;
	bool rightsucess = rat_in_maze(maze, sol, i, j + 1, m, n);
	bool downsucess = rat_in_maze(maze, sol, i + 1, j, m, n);

//backtracking
	sol[i][j] = 0;

	if (rightsucess || downsucess) {
		return true;
	}
	return false;
}

int32_t main()
{

	char maze[10][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00",
	};

	int sol[10][10] = {0};
	int m = 4;
	int n = 4;

	bool ans = rat_in_maze(maze, sol, 0, 0, m - 1, n - 1);
	if (ans == false) {
		cout << "path not found" << endl;
	}

	return 0;


}
