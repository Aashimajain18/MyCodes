/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


Constraints:

1 <= n <= 8

*/


// We have to make all the possible strings which can be made using n open paranthesis and n closed paranthesis.
// But the only condition is the string needs to be balanced.
// example :
// for n = 2
//         "(())" , "()()" are balanced string but "))((" , "())(" are not balanced.

//         So we can easily see tha we can put open bracket anytime it is not depending upon the number of closed paranthesis.
//         But we can put a closed paranthesis only when we have at least one unbalanced open paranthesis before it.



class Solution {

	void recur(int open, int closed, int &n, string str, vector<string>&ans)
	{
		if (open == n && closed == n) {
			ans.push_back(str);
			return;
		}

		if (open < n)
		{
			recur(open + 1, closed, n, str + "(", ans);
		}
		if (closed < n && open > closed)
		{
			recur(open, closed + 1, n, str + ")", ans);
		}
		return;
	}

public:
	vector<string> generateParenthesis(int n) {

		vector<string>ans;
		recur(0, 0, n, "", ans);
		return ans;
	}
};