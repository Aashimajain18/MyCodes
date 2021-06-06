/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/

//my bottom up dp solution
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int dp[1000][1000];
                for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                dp[i][j]=INT_MAX;
            }              
                }
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            int x=triangle[i].size();
            for(int j=0;j<x;j++){
                if(j==0){
                    dp[i][j]=dp[i-1][j]+triangle[i][j];
                }
                 if(j>0){
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
                }
            }
        }
        int m=triangle[n-1].size();
        int ans=INT_MAX;
        for(int k=0;k<m;k++){
            ans=min(ans,dp[n-1][k]);
        }
        
// cout<<dp[0][0];
//         cout<<endl;
//         for(int i=1;i<n;i++){
//             int x=triangle[i].size();
//             for(int j=0;j<x;j++){
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
      
        return ans;
    }
};


//solution 2 
//o(1) space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& T) {
        for (int i = T.size() - 2; ~i; i--) 
            for (int j = T[i].size() - 1; ~j; j--) 
                T[i][j] += min(T[i+1][j], T[i+1][j+1]);
        return T[0][0];
    }
};


//solution-3
//top down
class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>>& t,vector<vector<int>>& dp){
        
        if(i<0 || i>=t.size() || j<0 ||j>=t[i].size()) return 0;
         if(dp[i][j]) return dp[i][j];
        int s1=t[i][j]+solve(i+1,j+1,t,dp);
        int s2=t[i][j]+solve(i+1,j,t,dp);
       
        dp[i][j]=min(s1,s2);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
     int n=triangle.size();
        vector<vector<int> > dp(n,vector<int> (n));
        return solve(0,0,triangle,dp);
    }
};

