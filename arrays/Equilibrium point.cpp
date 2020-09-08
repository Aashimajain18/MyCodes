/*
Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array.
Equilibrium position in an array is a position such that the sum of elements before it is equal to
he sum of elements after it.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases
ollow. First line of each test case contains an integer N denoting the size of the array. Then in
the next line are N space separated values of the array A.

Output:
For each test case in a new  line print the position at which the elements are at equilibrium if no
quilibrium point exists print -1.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= Ai <= 108

Example:
Input:
2
1
1
5
1 3 5 2 2

Output:
1
3

Explanation:
Testcase 1: Since its the only element hence its the only equilibrium point.
Testcase 2: For second test case equilibrium point is at position 3 as elements below it (1+3) = elements
after it (2+2).

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
#include<set>
using namespace std;

int equilibrium(int arr[], int n)
{
	int sum = 0; // initialize sum of whole array
	int leftsum = 0; // initialize leftsum

	/* Find sum of the whole array */
	for (int i = 0; i < n; ++i)
		sum += arr[i];

	for (int i = 0; i < n; ++i)
	{
		sum -= arr[i]; // sum is now right sum for index i

		if (leftsum == sum)
			return i + 1;

		leftsum += arr[i];
	}

	/* If no equilibrium index found, then return 0 */
	return -1;
}

int32_t main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int a[n];

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << equilibrium(a, n) << endl;

	}
	return 0;


}
