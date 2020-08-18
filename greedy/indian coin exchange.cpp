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

int coin_exchange(int *coins, int n, int money) {
	int ans = 0;
	while (money > 0) {
		int idx = upper_bound(coins, coins + n, money) - 1 - coins;
		//cout << coins[idx] << "+";

		money = money - coins[idx];
		ans++;
	}
	return ans;
}


int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int t = sizeof(coins) / sizeof(int);
	cout << coin_exchange(coins, t, n);
	cout << endl;
	return 0;
}






