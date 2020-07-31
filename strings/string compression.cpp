/*
Take as input S, a string. Write a function that does basic string compression.
Print the value returned. E.g. for input “aaabbccds” print out a3b2c2d1s1.

Input Format
A single String S

Constraints
1 < = length of String < = 1000

Output Format
The compressed String.

Sample Input
aaabbccds
Sample Output
a3b2c2d1s1
Explanation
In the given sample test case 'a' is repeated 3 times consecutively, 'b' is repeated
twice, 'c' is repeated twice and 'd and 's' occurred only once.
*/

#include <iostream>
using namespace std;
int main() {
	char a[100];
	cin >> a;
	int frequency;
	for (int i = 0; a[i] != '\0'; i++) {
		frequency = 0;
		cout << a[i];
		while (a[i + 1] == a[i]) {
			frequency++;
			i++;
		}
		cout << frequency + 1;
	}
	return 0;
}