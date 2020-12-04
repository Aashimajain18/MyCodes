/*
Given an array of size n with 0s and 1s , flip at most k 0s to get the longest possible subarray
of 1s.

Input Format
First Line : n, size of array and k Second Line : n space separated numbers (0s or 1s)

Constraints
n <= 10^5 0 <= k <= n

Output Format
First Line : Size of subarray Second Line : Array after flipping k 0s

Sample Input
10 2
1 0 0 1 0 1 0 1 0 1
Sample Output
5
1 0 0 1 1 1 1 1 0 1
*/

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

	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int left = 0, right = 0, max_len = 0, zero_cnt = 0, ml, mr;
	for (int i = 0; i < n; i++) {
		if (a[right] == 0) {
			zero_cnt++;
		}
		if (zero_cnt > k) {
			while (zero_cnt > k) {
				if (a[left] == 0) {
					zero_cnt--;
				}
				left++;
			}
		}
		if (right - left + 1 > max_len) {
			max_len = right - left + 1;
			ml = left;
			mr = right;
		}
		right++;
	}
	cout << max_len << endl;
	for (int i = 0; i < n; i++) {
		if (i >= ml && i <= mr) {
			cout << 1 << " ";
		}
		else {
			cout << a[i] << " ";
		}
	}

	return 0;
}
