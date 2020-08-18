//there is probabaly a slight error in the bottom up approach here
#include<iostream>
using namespace std;
//Top Downn
//space complexity=o(N)
//time complexity=o(N)
int steps(int n, int *dp) {
	if (n == 1) {
		return 0;
	}
	//---------------Every DP Code
	if (dp[n] != 0) {
		return dp[n];
	}

	//Base Case
	int x, y, z, ans;
	x = y = z = INT_MAX;

	x = steps(n - 1, dp) + 1;

	if (n % 2 == 0) {
		y = steps(n / 2, dp) + 1;
	}

	if (n % 3 == 0) {
		z = steps(n / 3, dp) + 1;
	}

	ans = min(x, min(y, z));
	return dp[n] = ans;
}

//bottom up approach
//space complexity=o(N)
//time complexity=o(N)
int min_steps_bu(int n) {
	int dp[100] = {0};
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		int opt1, opt2, opt3;
		opt1 = opt2 = opt3 = INT_MAX;
		if (n % 2 == 0) {
			opt2 = dp[i / 2] ;
		}
		if (n % 3 == 0) {
			opt1 = dp[i / 3] ;
		}
		else {
			opt3 = dp[i - 1] ;
		}
		dp[i] = min(opt1, min(opt2, opt3)) + 1;
	}

	return dp[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int dp[1000] = {0};

	cout << steps(n, dp) << endl;

	cout << min_steps_bu(n) << endl;

	return 0;
}