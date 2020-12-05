/*Given an integer N, how many structurally unique binary search trees are there that store values 1...N?
Input:
First line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains a single line of input containing N.
Ouput:
For each testcase, in a new line, print the answer.
Constraints:
1<=T<=15
1<=N<=11
Example:
Input:
2
2
3
Output:
2
5
Explanation:
Testcase1:
for N = 2, there are 2 unique BSTs
     1               2
      \            /
       2         1
Testcase2:
for N = 3, there are 5 possible BSTs
  1              3        3         2      1
    \           /        /           /    \      \
     3        2         1        1    3      2
    /       /                \                      \
   2      1               2                        3
*/

#include <iostream>
using namespace std;

//catalan number
int countTrees(int n) {
	int T[n + 1] = {0} ;
	T[0] = 1;
	T[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			T[i] += T[j] * T[i - j - 1];
		}
	}
	return T[n];
}

int main() {
	//code
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << countTrees(n) << endl;
	}
	return 0;
}
