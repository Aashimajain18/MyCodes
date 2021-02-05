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
#define om map<int, vector<int> >
#define um unordered_map<int, vector<int> >

//time complexity is O(N^2)
//complexity can be reduced to O(NlogN) by using binary search

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int dp[n + 1];
	dp[0] = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = INT_MAX;
	}


	for (int i = 0; i < n; i++) {

		for (int length = 0; length < n; length++)
		{
			if (dp[length] < a[i] && a[i] < dp[length + 1]) {
				dp[length + 1] = a[i];
			}
		}
	}

	/*	//binary search method
		for (int i = 0; i < n; i++) {
			int length = upper_bound(dp, dp + n + 1, a[i]) - dp;
			if (dp[length - 1] < a[i] && a[i] < dp[length]) {
				dp[length ] = a[i];

			}
		}
	*/
	int lis = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dp[i] != INT_MAX) {
			lis = i;
		}
	}
	cout << lis << endl;


}