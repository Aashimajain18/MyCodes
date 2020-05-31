/*
Given an integer n, write a function that returns count of trailing zeroes in n!.



Input Format
A single integer N.

Constraints
1 <= N <= 10^9

Output Format
A single integer denoting the count of trailing zeroes in N!

Sample Input
5
Sample Output
1
Explanation
Factorial of 5 is 120 which has one trailing 0.
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



int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	long long int n, ans = 0;
	cin >> n;
	int cnt = 0;
	int i = 5;
	while (n / i > 0) {
		ans = ans + n / i;
		i *= 5;
	}
	cout << ans << endl;
}
