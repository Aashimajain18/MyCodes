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

int min_money(int a[], int w) {
	int dp[w + 1];
	dp[0] = 0;
	dp[1] = a[0];
	for (int i = 2; i <= w; i++)
	{
		dp[i] = min(a[i], dp[i - 1] + dp[1]);
	}
	return dp[w];
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n, w;
	cin >> n >> w;
	int a[w];
	for (int i = 0; i < w; i++) {
		cin >> a[i];
	}

	cout << min_money(a, w) << endl;

	return 0;
}
