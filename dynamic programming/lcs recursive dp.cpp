#include<iostream>
//#include <bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include<utility>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
#include<map>
#include<set>
using namespace std;

int lcs(string s1, string s2, int i, int j, int dp[100][100]) {
	if (i == s1.length() || j == s2.length()) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (s1[i] == s2[j]) {
		dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1, dp);
	}
	int op1 = lcs(s1, s2, i + 1, j, dp);
	int op2 = lcs(s1, s2, i, j + 1, dp);
	return dp[i][j] = max(op1, op2);
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1 = "ABCD";
	string s2 = "ABEDG";
	int n1 = s1.length();
	int n2 = s2.length();

	// vector<vector<int> > dp(n1, vector<int> (n2, -1));
	int dp[100][100] = { -1};

	cout << lcs(s1, s2, 0, 0, dp) << endl;
	return 0;
}
