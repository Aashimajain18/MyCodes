//you are given n stairs what is the number of ways you can reacg the top by taking max of k steps at each stair?

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

//top down approach
//space complexity-O(N)
//time complexity-O(NK)
int max_ways(int n, int k, int dp[]) {
	if (n == 0) {
		//means standing on ground and there is only one way to do that
		return 1;
	}

	if (dp[n] != 0) {
		return dp[n];
	}
//rec case
	int ways = 0;
	for (int i = 1; i <= k; i++)
	{
		if ((n - i) >= 0) {
			ways += max_ways(n - i, k, dp);
		}
	}
	return dp[n] = ways;

}

//bottom up approach
//space complexity-O(N)
//time complexity-O(NK)
int max_ways_bu(int n, int k) {
	int dp[100] = {0};
	dp[0] = 1; //start case
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) {
				dp[i] = dp[i] + dp[i - j];
			}
		}
	}
	//check dp array by printing
	for (int i = 0; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;

	return dp[n];
}

//bottom up approach optimized
//space complexity-O(N)
//time complexity-O(N)
int max_ways_bu_optimized(int n, int k) {
	int dp[100] = {0};
	dp[0] = dp[1] = 1; //start case
	for (int i = 2; i <= k; i++) {
		dp[i] = 2 * dp[i - 1];

	}
	for (int i = k + 1; i <= n; i++) {
		dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
	}

	//check dp array by printing
	for (int i = 0; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
	return dp[n];
}


int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	//int dp[100] = {0};
	cout << max_ways_bu(n, k) << endl;
	return 0;


}



