/*
You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. You need to find the maximum sum of consecutive numbers.

Input Format
First line contains integer t which is number of test case.
For each test case, it contains an integer n which is the size of array and next line contains n space separated integers denoting the elements of the array.

Constraints
1<=t<=100
1<=n<=1000
|Ai| <= 10000

Output Format
Print the maximum circular sum for each testcase in a new line.

Sample Input
1
7
8 -8 9 -9 10 -11 12
Sample Output
22
Explanation
Maximum Circular Sum = 22 (12 + 8 - 8 + 9 - 9 + 10)
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

int bitonic(int arr[], int n)
{
	// Length of increasing subarray
	// ending at all indexes
	int inc[n];

	// Length of decreasing subarray
	// starting at all indexes
	int dec[n];
	int i, max;

	// length of increasing sequence
	// ending at first index is 1
	inc[0] = 1;

	// length of increasing sequence
	// starting at first index is 1
	dec[n - 1] = 1;

	// Step 1) Construct increasing sequence array
	for (i = 1; i < n; i++)
		inc[i] = (arr[i] >= arr[i - 1]) ? inc[i - 1] + 1 : 1;

	// Step 2) Construct decreasing sequence array
	for (i = n - 2; i >= 0; i--)
		dec[i] = (arr[i] >= arr[i + 1]) ? dec[i + 1] + 1 : 1;

	// Step 3) Find the length of
	// maximum length bitonic sequence
	max = inc[0] + dec[0] - 1;
	for (i = 1; i < n; i++)
		if (inc[i] + dec[i] - 1 > max)
			max = inc[i] + dec[i] - 1;

	return max;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {

//Time Complexity : O(n)
//Auxiliary Space : O(n)

		int n;
		cin >> n;
		int a[1000];


		for (int j = 0; j < n; j++)
		{
			cin >> a[j];

		}

		cout << bitonic(a, n) << endl;


	}




	return 0;
}



