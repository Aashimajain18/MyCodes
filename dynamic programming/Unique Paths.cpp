/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10^9.
*/
class Solution {
public:
    int ans=0;
    
    void uniquePathsans(int m, int n,int i,int j) {
        if(i==m-1 && j==n-1){
            ans++;
            return;
        }
        if(i==m || j==n){
            return;
        }
        //down
        uniquePathsans(m,n,i+1,j);
        //up
        uniquePathsans(m,n,i,j+1);
        return;
        
    }
    
    //top down dp
        int uniquePathsansdp(int m, int n,int i,int j,int dp[100][100]) {
        if(i<0 && j<0){
            return 0;
        }
        if(i==0 || j==0){
            return 1;
        }
            if(dp[i][j]!=0){
                return dp[i][j];
            }
        dp[i][j]=uniquePathsansdp(m,n,i-1,j,dp)+uniquePathsansdp(m,n,i,j-1,dp);
        
        return dp[i][j];
        
    }
    
    //bottom up
      int uniquePathsdp(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
    
    
    int uniquePaths(int m, int n) {
         //uniquePathsans(m,n,0,0);
        //return ans;
        int dp[100][100]={0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=0;
            }
        }
        return uniquePathsansdp(m,n,m-1,n-1,dp);
    }
};
