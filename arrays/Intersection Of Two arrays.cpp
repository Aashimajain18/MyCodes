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

	int n;
	cin >> n;
	int a[n], b[n];
	unordered_map<int, int>mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		mp[a[i]] += 1;
	}

	std::vector<int> v;
	for (int i = 0; i < n; i++) {
		if (mp[b[i]] > 0) {
			v.push_back(b[i]);
			mp[b[i]] -= 1;
		}
	}
	sort(v.begin(), v.end());
	cout << "[";
	for (int i = 0; i < v.size() - 1; i++) {
		cout << v[i] << ", ";
	}
	cout << v[v.size() - 1];
	cout << "]";
	return 0;
}
