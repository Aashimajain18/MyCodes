/*
You are given an balanced expression. You have to find if it contains duplicate parentheses or not.
A set of parentheses are duplicate if same subexpression is surrounded by multiple parenthesis.

Input Format
First line contains integer t as number of test cases.
Next t lines contains one balanced expression each.

Constraints
1 < t < 100
1< expression < 100

Output Format
Print "Duplicate" if the expression has any redundancy. Else print "Not Duplicates".

Sample Input
2
(((a+(b))+(c+d)))
((a+(b))+(c+d))
Sample Output
Duplicate
Not Duplicates
Explanation
For 1st test case : The subexpression "a+(b)" is surrounded by two pairs of brackets.
*/
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


bool is_duplicate(string s) {
	int i, n = s.size();
	stack<char> st;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ')') {
			if (st.top() == '(') {
				return true;

			}
			else {
				while (!st.empty() and st.top() != '(') {
					st.pop();
				}

				st.pop();
			}
		}
		else {
			st.push(s[i]);
		}

	}
	return false;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, i;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (is_duplicate(s)) {
			cout << "Duplicate" << endl;
		}
		else {
			cout << "Not Duplicates" << endl;

		}
	}


	return 0;
}




















