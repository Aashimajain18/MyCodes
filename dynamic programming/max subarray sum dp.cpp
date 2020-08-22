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

//time complexity-O(N)
//space complexity-O(N) because of dp array
int max_sum(int arr[], int n) {
	int dp[100] = {0};
	dp[0] = arr[0] > 0 ? arr[0] : 0;
	int max_so_far = dp[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = dp[i - 1] + arr[i];
		if (dp[i] < 0) {
			dp[i] = 0;
		}
		max_so_far = max(dp[i], max_so_far);
	}

	return max_so_far;
}

//space optimized
//space complexity-O(1) because we are storing only one past value in a single variable curreentsum instead of a whole array
//time complexity o(n)
//kadane's algorithm

int max_sum_optimized(int arr[], int n) {
	int max_sum = 0;
	int currentsum = 0;


	for (int i = 0; i < n; ++i)
	{
		currentsum = currentsum + arr[i];
		if (currentsum < 0) {
			currentsum = 0;
		}
		max_sum = max(currentsum, max_sum)	;
	}
	return max_sum ;


}



int32_t main()
{



	int arr[] = { -3, 2, 5, -1, 6, 3, -2, 7, -5, 2};

	int n = sizeof(arr) / sizeof(int);
	cout << max_sum(arr, n) << endl;


	return 0;


}