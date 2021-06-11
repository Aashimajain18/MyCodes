/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/

//My dp solution
class Solution {
public:
    int max(int a,int b){
        if(a>b){
            return a;
        }
        return b;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> matrixxx(m,vector<int>(n));
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    matrixxx[i][j]=1;
                }
                else{
                    matrixxx[i][j]=0; 
                }
            }
         }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrixxx[i][j]==1){
                if(matrixxx[i-1][j]!=0 && matrixxx[i-1][j-1]!=0 && matrixxx[i][j-1]!=0){
                    matrixxx[i][j]=min(matrixxx[i-1][j-1],min(matrixxx[i-1][j],matrixxx[i][j-1]))+1;
                }
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<matrixxx[i][j]<<" ";
                ans=max(ans,matrixxx[i][j]);
            }
            cout<<endl;
        }
        return ans*ans;
    }
};


//same logic but slightly better code
/*
logic:-
To appy DP, we define the state as the maximal size (square = size * size) of the square that can be formed till point (i, j), denoted as dp[i][j].

For the topmost row (i = 0) and the leftmost column (j = 0), we have dp[i][j] = matrix[i][j] - '0', meaning that it can at most form a square of size 1 when the matrix has a '1' in that cell.

When i > 0 and j > 0, if matrix[i][j] = '0', then dp[i][j] = 0 since no square will be able to contain the '0' at that cell. If matrix[i][j] = '1', we will have dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1, which means that the square will be limited by its left, upper and upper-left neighbors.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                sz = max(dp[i][j], sz);
            }
        }
        return sz * sz;
    }
};


//solution-3
//O(1) space
/*
In the above code, it uses O(mn) space. Actually each time when we update dp[i][j], we only need dp[i-1][j-1], dp[i-1][j] (the previous row) and dp[i][j-1] (the current row). So we may just keep two rows.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<int> pre(n, 0), cur(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    cur[j] = matrix[i][j] - '0';
                } else {
                    cur[j] = min(pre[j - 1], min(pre[j], cur[j - 1])) + 1;
                }
                sz = max(cur[j], sz);
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        return sz * sz;
    }
};


