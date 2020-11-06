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
#define ll long long int

void selection_sort(ll a[], ll n) {
	ll j;
	for (ll i = 0; i < n - 1; i++)
	{
		ll min = i;
		for (ll j = i; j <= n - 1; j++)
		{
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
	return;
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	selection_sort(a, n);
	for (ll i = 0; i < n; i++) {
		cout << a[i] << endl;
	}


	return 0;
}
