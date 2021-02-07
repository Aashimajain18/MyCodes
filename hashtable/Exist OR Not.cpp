/*
Given an array arr of n length. You will be given Q queries for the array. Each query contains a
number N.You have to determine whether a number exist in the array or not

Input Format
First line of input contains number of test cases T. First line of each case contains an
integer L denoting the length of the array. The next line contains L space separated integers.
The next line contains an integer Q denoting the number of queries. The next Q lines contains a
number N to be searched in the array.

Constraints
1<=t<=12
1<=L<=10^5 (n=number of elements in array).
-10^5<=A[i]<=10^5 (A[i]=ith element of array).

1<=Q<=10^4
-10^5<=x<=10^5

Output Format
For each Query print “Yes” if the number is present and “No” if it’s not.

Sample Input
1
6
12 3 -67 67 34 2
4
4
5
67
7
Sample Output
No
No
Yes
No
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

	long long int t;
	cin >> t;
	while (t--) {
		long long int n;
		cin >> n;
		long long int a[n];
		unordered_map<long long int, bool>m;
		for (long long int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]] = true;
		}
		long long int q;
		cin >> q;
		while (q--) {
			long long int query;
			cin >> query;
			if (m[query] == true) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		// cout << endl;
	}
	return 0;
}
