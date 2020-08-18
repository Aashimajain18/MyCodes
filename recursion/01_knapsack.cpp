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

int profit(int n, int c, int *wt, int *price) {
	if (n == 0 || c == 0) {
		return 0;
	}
	int ans = 0;
	int inc, exc;
	inc = exc = INT_MIN;
	if (wt[n - 1] <= c) {
		inc = price[n - 1] + profit(n - 1, c - wt[n - 1], wt, price);
	}
	exc = 0 + profit(n - 1, c, wt, price);
	ans = max(inc, exc);
	return ans;
}

int32_t main()
{

	int wt[] = {1, 2, 3, 5};
	int price[] = {40, 20, 30, 100};
	int n = 4;
	int c = 7;
	cout << profit(n, c, wt, price) << endl;
	return 0;


}



