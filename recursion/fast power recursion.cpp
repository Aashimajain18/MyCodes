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
//calculate a^n
int power(a, n) {
	if (n == 0) {
		return 1;

	}
	return a * power(a, n - 1);
}


int fast_power(a, n) {
	if (n == 0) {
		return 1;

	}
	int smaller_ans = fast_power(a, n / 2);
	smaller_ans *= smaller_ans;
	if (n & 1) {
		return smaller_ans * a;
	}
	return smaller_ans;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, n;
	cin >> a >> n;

	return 0;


}



