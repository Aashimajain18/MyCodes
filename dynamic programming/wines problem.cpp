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

//tc-O(2^n)
int simple_recursive_wines(int wines[], int i, int j, int y) {
	//base case
	if (i > j) {
		return 0;
	}

//recursive case
	int opt1 = wines[i] * y + simple_recursive_wines(wines, i + 1, j, y + 1);
	int opt2 = wines[j] * y + simple_recursive_wines(wines, i, j - 1, y + 1);
	return max(opt1, opt2);
}



//2D Dp problem...i.e we make a 2D array
//top down approach
//time complexity reduced to-O(N^2)
int wines_dp(int wines[], int i, int j, int y, int dp[][100]) {
	//base case
	if (i > j) {
		return 0;
	}

	if (dp[i][j] != 0) {
		return dp[i][j];
	}

//recursive case
	int opt1 = wines[i] * y + wines_dp(wines, i + 1, j, y + 1, dp);
	int opt2 = wines[j] * y + wines_dp(wines, i, j - 1, y + 1, dp);
	dp[i][j] = max(opt1, opt2);
	return dp[i][j];
}

int32_t main()
{



	int wines[] = {2, 3, 5, 1, 4};
	int dp[100][100];
	int n = sizeof(wines) / sizeof(int);
	cout << wines_dp(wines, 0, n - 1, 1, dp) << endl;


	return 0;


}



