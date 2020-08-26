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

//given a string find all it's permutations.

void permute(char *a, int i) {
	//Base Case
	if (a[i] == '\0') {
		cout << a << endl;
		return;
	}
	//Rec Case
	for (int j = i; a[j] != '\0'; j++) {
		swap(a[i], a[j]);
		permute(a, i + 1);
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
	permute(a, 0);


	return 0;
}