/*Take as input x and n, two numbers. Write a function to calculate x raise to power n. Target complexity is O(logn). NOTE: Try both recursive and bitmasking approach.

Input Format
Enter the number N and its power P

Constraints
None

Output Format
Display N^P

Sample Input
2
3
Sample Output
8*/

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

//time complexity=O(logN)
int pow(int x, int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return x;
	}
	int val = pow(x, n / 2);
	if (n % 2 == 0) {
		return val * val;
	}
	else {
		return x * val * val;
	}
}

int power(int x, int n) {
	int ans = 1;
	while (n > 0) {
		int last_bit = (n & 1);
		if (last_bit) {
			ans = ans * x;
		}
		x = x * x;
		n = n >> 1;
	}
	return ans;
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int x, n;
	cin >> x >> n;
	cout << power(x, n) << endl;
	return 0;
}
