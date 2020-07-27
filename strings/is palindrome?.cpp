/*
Take as input N, a number. Take N more inputs and store that in an array. Write a recursive function which tests if the array is a palindrome and returns a Boolean value. Print the value returned.

Input Format
Enter a number N , add N more numbers

Constraints
None

Output Format
Display the Boolean result

Sample Input
4
1
2
2
1
Sample Output
true
*/
#include<iostream>
#include <algorithm>


using namespace std;
int main() {
	int n, i;
	cin >> n;
	int s[n];
	for (i = 0; i < n; i++) {
		cin >> s[i];
	}
	string check = "true";
	for (i = 0; i < n; i++) {
		// if at any instance ith position from starting
		// not equals ith position from back , then check=false
		if (s[i] != s[n - i - 1]) {
			check = "false";
		}
	}
	cout << check << endl;


}