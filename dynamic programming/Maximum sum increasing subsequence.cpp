/*

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
#include<set>
using namespace std;

int maxSumIS(int arr[], int n)
{
	int i, j, max = 0;
	int dp[n];

	/* Initialize dp values
	for all indexes */
	for ( i = 0; i < n; i++ )
		dp[i] = arr[i];

	/* Compute maximum sum values
	in bottom up manner */
	for ( i = 1; i < n; i++ )
		for ( j = 0; j < i; j++ )
			if (arr[i] > arr[j] &&
			        dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];

	/* Pick maximum of
	all dp values */
	for ( i = 0; i < n; i++ )
		if ( max < dp[i] )
			max = dp[i];

	return max;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int a[n];

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << maxSumIS(a, n) << endl;
	}
	return 0;
}