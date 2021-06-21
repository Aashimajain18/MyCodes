/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999

*/

//My solution
class Solution {
public:
    
    int minCost(vector<int>& cost,int n,int dp[]) {
        if(n==0 ||  n==1){
            return cost[n];
        }
        if(dp[n]!=0){
            return dp[n];
        }
        dp[n]=min(minCost(cost,n-1,dp),minCost(cost,n-2,dp))+ cost[n];
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp[n];
        for(int i=0;i<n;i++){
            dp[i]=0;
        }
        return min(minCost(cost,n-1,dp),minCost(cost,n-2,dp));
    }
};
