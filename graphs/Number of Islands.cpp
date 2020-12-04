/*Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

//method-1 {dfs}
class Solution {
public:


	void eraseIslands_dfs(vector<vector<char>>& grid, int i, int j) {
		int m = grid.size(), n = grid[0].size();
		if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
			return;
		}
		grid[i][j] = '0';
		eraseIslands_dfs(grid, i - 1, j);
		eraseIslands_dfs(grid, i + 1, j);
		eraseIslands_dfs(grid, i, j - 1);
		eraseIslands_dfs(grid, i, j + 1);
	}

	int numIslands(vector<vector<char>>& grid) {

		int m = grid.size(), islands = 0;
		int n = grid[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1') {
					islands++;
					eraseIslands_dfs(grid, i, j);
				}
			}
		}
		return islands;
	}
};

//method-2 {bfs}
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1') {
					islands++;
					grid[i][j] = '0';
					queue<pair<int, int>> todo;
					todo.push({i, j});
					while (!todo.empty()) {
						pair<int, int> p = todo.front();
						todo.pop();
						for (int k = 0; k < 4; k++) {
							int r = p.first + offsets[k], c = p.second + offsets[k + 1];
							if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
								grid[r][c] = '0';
								todo.push({r, c});
							}
						}
					}
				}
			}
		}
		return islands;
	}
};