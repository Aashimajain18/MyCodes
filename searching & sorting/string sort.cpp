/*
Nishant is a very naughty boy in Launchpad Batch. One day he was playing with strings,
and randomly shuffled them all. Your task is to help Nishant Sort all the strings
( lexicographically ) but if a string is present completely as a prefix in another string, then string with longer length should come first. Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - then sorted order should have - Batman, bat.

Input Format
N(integer) followed by N strings.

Constraints
N<=1000

Output Format
N lines each containing one string.

Sample Input
3
bat
apple
batman
Sample Output
apple
batman
bat
Explanation
In mathematics, the lexicographic or lexicographical order (also known as lexical order,
ictionary order, alphabetical order or lexicographic(al) product) is a generalization of
he way words are alphabetically ordered based on the alphabetical order of their component letters.


*/
#include<bits/stdc++.h>

using namespace std;

bool compare( string a, string b)
{
	int l1 = a.length(); int l2 = b.length(); int flag = -1;
	for (int i = 0; i < min(l1, l2); i++) {
		if (a[i] != b[i])
			flag = 0;
	}
	if (flag == -1) // means there is a prefix match
		return l1 > l2; // so sort decreasing order of length
	else
		return a < b; //sorting in normal dictionary order when no prefix match
}


int main()
{
	int n, i;
	cin >> n;
	string a[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);
	for (i = 0; i < n; i++) {
		cout << a[i] << endl;
	}


	return 0;
}