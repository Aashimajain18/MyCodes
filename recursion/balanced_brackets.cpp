
/*
generate balanced brackets using N pairs of round barckets
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
using namespace std;

void brackets(char *out, int i, int n, int open, int close) {
	if (i == 2 * n) {
		out[i] = '\0';
		cout << out << endl;
		return ;
	}
	if (open < n) {
		out[i] = '(';
		brackets(out, i + 1, n, open + 1, close);
	}
	if (close < open) {
		out[i] = ')';
		brackets(out, i + 1, n, open, close + 1);
	}
	return ;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	char out[1000];
	int idx = 0;
	brackets(out, idx, n, 0, 0);
	return 0;


}



