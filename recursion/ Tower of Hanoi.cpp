/*
Using a helper stick (peg), shift all rings from peg A to peg B using peg C.
All rings are initally placed in ascending order, smallest being on top.
No bigger ring can be placed over a smaller ring.

Input Format
Single line input containing a single integer N denoting the no of rings.

Constraints
1 <= N <= 10

Output Format
Print the instructions to move all the rings from peg A to B in a new line each.
Each line should follow format : Moving ring i from A/B/C to A/B/C

Sample Input
4
Sample Output
Moving ring 1 from A to C
Moving ring 2 from A to B
Moving ring 1 from C to B
Moving ring 3 from A to C
Moving ring 1 from B to A
Moving ring 2 from B to C
Moving ring 1 from A to C
Moving ring 4 from A to B
Moving ring 1 from C to B
Moving ring 2 from C to A
Moving ring 1 from B to A
Moving ring 3 from C to B
Moving ring 1 from A to C
Moving ring 2 from A to B
Moving ring 1 from C to B
*/


#include<iostream>
#include<string>
using namespace std;

void towerofhanoi(int n, char src, char helper, char dest) {
	if (n == 0) {
		return;
	}
	towerofhanoi(n - 1, src, dest, helper);
	cout << "Moving ring " << n << " from " << src << " to " << dest << endl;
	towerofhanoi(n - 1, helper, src, dest);
}

int main() {
	int t;
	cin >> t;
	towerofhanoi(t, 'A', 'C', 'B');
}