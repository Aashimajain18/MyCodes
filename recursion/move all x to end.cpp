/*
Take as input str, a string. Write a recursive function which moves all ‘x’ from the
string to its end.
E.g. for “abexexdexed” return “abeedeedxxx”.
Print the value returned

Input Format
Single line input containing a string

Constraints
Length of string <= 1000

Output Format
Single line displaying the string with all x's moved at the end

Sample Input
axbxc
Sample Output
abcxx
Explanation
All x's are moved to the end of string while the order of remaining characters remain
the same.
*/
#include<iostream>
#include<string>
using namespace std;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void appendX2end(string &str, int index, int org_len) {
	if (index == str.length()) {
		str.append((org_len - str.length()), 'x');
		return;
	}
	if (str[index] == 'x') {
		str.erase(str.begin() + index);//Erases the single character at iterator position pos
		appendX2end(str, index, org_len);
	}
	else {
		appendX2end(str, index + 1, org_len);
	}
}
int main() {
	c_p_c();
	string str;
	cin >> str;
	appendX2end(str, 0, str.length());
	cout << str;
	return 0;
}

