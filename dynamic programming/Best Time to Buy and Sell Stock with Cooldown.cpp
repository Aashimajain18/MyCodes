/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if (!n) return 0;
        
		/* S0 -> Idle, S1->buy, S2-> sell */
        vector<int>s0(n, 0);
        vector<int>s1(n, 0);
        vector<int>s2(n, 0);
    
        s0[0] = 0; s1[0] = -prices[0]; s2[0] = 0;
        for (int i = 1; i < n; i++) {
            s0[i] = max(s0[i-1], s2[i-1]);
            s1[i] = max(s1[i-1], s0[i-1]-prices[i]);
            s2[i] = s1[i-1]+prices[i];
        }
        
        return max(s0[n-1], s2[n-1]);
    }
};
