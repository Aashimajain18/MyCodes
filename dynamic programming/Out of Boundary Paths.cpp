/*
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent four cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:


Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
Example 2:


Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
 

Constraints:

1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow <= m
0 <= startColumn <= n
*/

//My solution
//bruteforce
//gives TLE-> o(N^4)
class Solution {
public:
    //long long int res=0;
    int Paths(int m, int n, int N,int i,int j) {
    if (i == m || j == n || i < 0 || j < 0) {
        return 1;
    }
    if (N == 0){
        return 0;
    }
    return findPaths(m, n, N - 1, i - 1, j)
        + findPaths(m, n, N - 1, i + 1, j)
        + findPaths(m, n, N - 1, i, j - 1)
        + findPaths(m, n, N - 1, i, j + 1);
  
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        //vector<int,int>v(m,vector<int>(n));
        long long int res=Paths(m,n,maxMove,startRow,startColumn);
        return res%(1000000007);
    }
};

//O(m*n*N) solution
//top down dp

class Solution {
public:
    int MOD = 1e9 + 7;
    int steps[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int dp[55][55][55];
    int helper(int N, int m, int n, int r, int c) {
        
        if(N>=0 && (r<0 || r>=m || c<0 || c>=n))  // valid case
            return 1;
        
        if(N==0 && r>=0 && r<m && c>=0 && c<n)  // invalid case
            return 0;
        
        if(dp[N][r][c] != -1)
            return dp[N][r][c];
        
        int ways=0;
        for(int i=0; i<4; ++i) {
            ways = (ways + (helper(N-1, m, n, r+steps[i][0], c+steps[i][1]))%MOD)%MOD;
        }
        
        return dp[N][r][c] = ways;
    }
    
    
    int findPaths(int m, int n, int N, int i, int j) {
        
        for(int i=0; i<=N; ++i)
            for(int j=0; j<=m; ++j)
                for(int k=0; k<=n; ++k)
                    dp[i][j][k] = -1;
        
        return helper(N, m, n, i, j);
    }
};
