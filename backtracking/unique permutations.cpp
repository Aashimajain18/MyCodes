/*
Given a string containing duplicates, print all its distinct permutations such that there are no
duplicate permutations and all permutations are printed in a lexicographic order.

Input Format
The first and only line of the test case contains the input string.

Constraints
Length of the string <= 8

Output Format
Print all the distinct permutations in a lexicographic order such that each permutation is in a new
ine. Note that there should not be any duplicate permutations.

Sample Input
ABA
Sample Output
AAB
ABA
BAA
Explanation
The possible permutations for the given string are { "AAB" , "AAB" , "ABA" , "BAA" } . We skip the
repeating "AAB" permutation and only print it in once. Also we print the final output in
lexicographical order.

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
#include<set>
#include<map>
using namespace std;

void permute(char *a, int i, set<string>&s) {
	//Base Case
	if (a[i] == '\0') {
		//
		string t(a);
		s.insert(t);
		return;
	}
	//Rec Case
	for (int j = i; a[j] != '\0'; j++) {
		swap(a[i], a[j]);
		permute(a, i + 1, s);
		//Backtracking
		swap(a[i], a[j]);
	}

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char a[100];
	cin >> a;
	set<string>s;
	permute(a, 0, s);
//loop over the set
	for (auto str : s) {
		cout << str << endl;
	}

	return 0;
}