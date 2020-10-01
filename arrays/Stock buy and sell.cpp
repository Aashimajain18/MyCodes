/*The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Input:
First-line contains the number of test cases T. The first line of each test case contains an integer value N denoting the number of days, followed by an array of stock prices of N days.

Output:
For each test case, print all of the days with profit in a new line, and if there is no profit then print "No Profit".

User Task:
Complete stockBuySell()  function and print all the days with profit in a single line. And if there is no profit then print "No Profit". You do not require to return since the function is void.

Constraints:
1 <= T <= 100
2 <= N <= 104
0 <= Ai <= 104

Example
Input:
2
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67
Output:
(0 3) (4 6)
(1 4) (5 9)

Explanation:
Testcase 1: We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit.

Note: Output format is as follows - (buy_day sell_day) (buy_day sell_day)
For each input, the output should be in a single line.*/



// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, i;
		cin >> n;
		int price[n];
		for (i = 0; i < n; i++) cin >> price[i];
		// function call
		stockBuySell(price, n);
	}
	return 0;
}
// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
	// code here
	int cnt = 0;

	for (int i = 1; i < n; i++) {

		if (price[i] > price[i - 1]) {
			cout << "(" << i - 1 << " ";
			cnt++;
			while (price[i] >= price[i - 1] && i < n) {
				i++;
			}
			cout << i - 1 << ")" << " ";

		}

	}
	if (cnt == 0) {
		cout << "No Profit";
	}
	cout << endl;
	return;
}