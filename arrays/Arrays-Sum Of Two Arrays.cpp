/*
Take as input N, the size of array. Take N more inputs and store that in an array.
 Take as input M, the size of second array and take M more inputs and store that in
  second array. Write a function that returns the sum of two arrays. Print the value
  returned.

Input Format
Constraints
Length of Array should be between 1 and 1000.

Output Format
Sample Input
4
1 0 2 9
5
3 4 5 6 7
Sample Output
3, 5, 5, 9, 6, END
Explanation
Sum of [1, 0, 2, 9] and [3, 4, 5, 6, 7] is [3, 5, 5, 9, 6] and the first digit
represents carry over , if any (0 here ) .
*/
#include<bits/stdc++.h>

using namespace std;


int main() {
	int n, i, m, carry = 0;
	cin >> n;
	int a[n];
	for (i = n; i > 0; i--) {
		cin >> a[i];
	}
	cin >> m;
	int b[m];
	for (i = m; i > 0; i--) {
		cin >> b[i];
	}
	int c[max(m, n)];
	for (i = 1; i <= max(m, n); i++) {
		if (m >= n) {
			if (i <= n) {
				int num = (a[i] + b[i] + carry);
				c[i] = num % 10;
				carry = num / 10;
			}
			else {
				int num = (b[i] + carry);
				c[i] = num % 10;
				carry = num / 10;

			}
		}
		else {
			if (i <= m) {
				int num = (a[i] + b[i] + carry);
				c[i] = num % 10;
				carry = num / 10;
			}
			else {
				int num = (a[i] + carry);
				c[i] = num % 10;
				carry = num / 10;

			}

		}

	}

	if (carry)
		cout << carry << ", ";

	for (i = max(m, n); i > 0; i--) {

		cout << c[i] << ", ";
	}
	cout << "END";
	return 0;
}


