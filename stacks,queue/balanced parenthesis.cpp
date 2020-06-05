/*
You are given a string of brackets i.e. '{', '}' , '(' , ')', '[' , ']' .
You have to check whether the sequence of parenthesis is balanced or not.
For example, "(())", "(())()" are balanced and "())(", "(()))" are not.

Input Format
A string of '(' , ')' , '{' , '}' and '[' , ']' .

Constraints
1<=|S|<=10^5

Output Format
Print "Yes" if the brackets are balanced and "No" if not balanced.

Sample Input
(())
Sample Output
Yes
Explanation
(()) is a balanced string.
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
#include<bits/stdc++.h>

using namespace std;

bool is_bal(string s) {
	int i, n = s.size();
	stack<char> St;
	for (i = 0; i < n; i++) {
		if (s[i] == '{') {
			St.push(s[i]);
		}
		else if (s[i] == '}') {
			if (St.empty())  return false;
			char on_top = St.top();
			if (on_top == '{') {
				St.pop();
			}
			else {
				return false;
			}
		}
		else if (s[i] == '(') {
			St.push(s[i]);

		}
		else if (s[i] == ')') {
			if (St.empty())  return false;
			char on_top = St.top();
			if (on_top == '(') {
				St.pop();
			}
			else {
				return false;
			}
		}
		else if (s[i] == '[') {
			St.push(s[i]);

		}
		else if (s[i] == ']') {
			if (St.empty())  return false;
			char on_top = St.top();
			if (on_top == '[') {
				St.pop();
			}
			else {
				return false;
			}
		}
	}
	if (St.empty()) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	string s;
	cin >> s;
	if (is_bal(s)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}

