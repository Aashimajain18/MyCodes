/*
The Planet Earth is under a threat from the aliens of the outer space and the Marvel
Avengers team is busy fighting against them. Meanwhile, The Incredible Hulk has to defeat
an enemy who is N steps above the level where he is standing (assume it as the 0th level). Hulk,
because of his incredible jumping ability can take jumps in power of 2. In order to defeat
the enemy as quickly as possible he has to reach the Nth step in minimum moves possible.
Help Hulk to find the same and contribute in saving the Mother Earth.



Input Format
The first line contains the number of test cases T. T test cases follow: The first line
of each test case contains a number N.

Constraints
1 <= T <= 10
1 <= N <= 10^5

Output Format
Output T lines, containing the minimum number of moves required by Hulk to reach the Nth step

Sample Input
3
3
4
5
Sample Output
2
1
2
Explanation
Let total steps is n, find the nearest integer which is of power 2 and less then n. let it would be k.
now remaining steps to cover is n-k and result = 1 + min steps for (n-k) remaining steps.
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

int set_bits(int n) {
	//O(log N)
	int cnt = 0;
	while (n != 0) {
		int last_bit = n & 1;
		if (last_bit == 1) {
			cnt++;
		}
		n = n >> 1;
	}
	return cnt;
}
int set_bits_FAST(int n) {
	//O(number of setbits) is the time complexity
	int cnt = 0;
	while (n > 0) {
		n = n & (n - 1);

		cnt++;
	}
	return cnt;
}

//built in function to find set bits is "__builtin_popcount(n)"

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << set_bits(n) << endl;
	}

}


