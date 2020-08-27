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

int lic(int a[], int n) {
	int dp[n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		cout << dp[i] << " ";
		if (dp[i] > max) {
			max = dp[i];
		}
	}
	cout << endl;
	return max;

}

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
	cout << lic(a, n) << endl;

}



