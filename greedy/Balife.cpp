/*Given an array A of size n, In a single operation you can subtract one from A[i] and add it to either A[i-1] (if i>0) or A[i+1] (if i < n-1).
Find the minimum number of operation required to make all the array elements same.
If it is not possible to do , print -1.

Input Format
The First line contains the size of the array N The Second line contains the N number of elements

Constraints
0 < N < 100000

Output Format
Output Number denoting the minimum number of operations required.

Sample Input
8
16 17 15 0 20 1 1 2
Sample Output
23*/

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
	int a[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	int avg = sum / n;
	if (avg * n != sum) {
		cout << -1 << endl;
	}
	else {
		int b[n];
		for (int i = 0; i < n; i++) {
			b[i] = avg - a[i];
		}
		for (int i = 1; i < n; i++) {
			b[i] = b[i - 1] + b[i];
		}

		int maxi = INT_MIN;
		for (int i = 0; i < n; i++) {
			maxi = max(maxi, abs(b[i]));
		}
		cout << maxi << endl;
	}

	return 0;
}
