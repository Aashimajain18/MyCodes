/*
One of the important aspect of object oriented programming is readability of the code. To enhance the readability of code, developers write function and variable names in Camel Case. You are given a string, S, written in Camel Case. FindAllTheWordsContainedInIt.

Input Format
A single line contains the string.

Constraints
|S|<=1000

Output Format
Print words present in the string, in the order in which it appears in the string.

Sample Input
IAmACompetitiveProgrammer
Sample Output
I
Am
A
Competitive
Programmer
Explanation
There are 5 words in the string.
*/
#include<iostream>
#include <algorithm>

using namespace std;

using namespace std;
void camelcase(string str) {
	cout << str[0];
	for (int i = 1; i < str.size(); i++) {
		if ((str[i] - 'A') >= 0 && (str[i] - 'A') < 26) {
			cout << endl << str[i];
		}
		else {
			cout << str[i];
		}
	}
	cout << endl;
}

int main() {
	string str;
	cin >> str;
	camelcase(str);
	return 0;
}