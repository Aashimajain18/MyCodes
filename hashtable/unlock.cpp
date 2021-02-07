/*
Shekhar is a bomb defusal specialist. He once encountered a bomb that can
be defused only by a secret code. He is given a number N and a number K. And he is also
given permutation of first N natural numbers . The defusal code is the largest permutation
possible by doing atmost K swaps among a pair of the given permutation. Help him to find the
final permutation.

Input Format
First line contains ​an integer N and an integer k. The next line contains N space separated
integers denoting the given permutation.

Constraints
1 <= n <= 10^5 1<= K <= 10^9

Output Format
The final permutation of the numbers with every number separated by a space with other number.

Sample Input
5 2
3 4 1 2 5
Sample Output
5 4 3 2 1
Explanation
First we can swap 5 with 3 which gives us 5 4 1 2 3 and then we can swap 3 and 1 which gives
us 5 4 3 2 1.
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
	unordered_map<int, int>m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]] = i;
	}
	int num = n;
	for (int i = 0; i < n; i++) {
		if (k > 0) {

			if (a[i] != num) {
				int idx = m[num];
				int val = a[i];
				swap(a[i], a[idx]);
				m[num] = i;
				m[val] = idx;
				k--;

			}
			num--;

		}
		if (k <= 0) {
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";

	}
	cout << endl;

	return 0;
}
