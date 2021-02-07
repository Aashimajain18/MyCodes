#include<iostream>
//#include <bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include<utility>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
#include<map>
#include<set>
using namespace std;


int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int i = 0;
		stack<string>st;
		int len = s.length() - 1;
		while (i <= len) {
			string x = "";
			while (s[i] != '.' && i <= len) {
				x = x + s[i];
				i++;
			}
			st.push(x);
			i++;
		}
		while (!st.empty()) {

			cout << st.top();
			st.pop();
			if (st.empty()) {
				break;
			}
			cout << ".";
		}
		cout << endl;

	}
	return 0;
}
