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
//space complexity=o(N)
//time complexity=o(N)
int fib(int n, int dp[]) {
	//base case
	if (n == 0 || n == 1) {
		return n;
	}
	//look up in dp array to check if we have already computed for n
	if (dp[n] != 0) {
		return dp[n];
	}
	int ans;
	ans = fib(n - 1, dp) + fib(n - 2, dp);
	return dp[n] = ans;

}


//bottom up approach
//space complexity=o(N)
//time complexity=o(N)
int fib_bu(int n) {
	int dp[100] = {0};
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

//bottom up approach with space optimization
//space complexity=o(1)
int fib_space_optimized(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	int a = 0;
	int b = 1;
	int c;
	for (int i = 2; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;

}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int dp[100] = {0};
	cout << fib(n, dp) << endl;
	cout << fib_bu(n) << endl;
	cout << fib_space_optimized(n);
	return 0;


}



