/*
You are at a casino. There are N stacked cards on pile . Each card has a number written on it.
 Then there will be Q iterations. In ith iteration, you start picking up the cards in Ai-1th pile from
 the top one by one and check whether the number written on the card is divisible by the ith prime number.
 f the number is divisible, you stack that card on pile Bi. Otherwise, you stack that card on pile Ai.
 After Q iterations, cards can only be on pile B1, B2, B3, . . . BQ, AQ . Output numbers on these cards
 from top to bottom of each piles in order of B1, B2, B3, . . . BQ, AQ .

Input Format
First line contains N and Q. The next line contains N space separated integers representing the initial
pile of cards i.e., A0. The leftmost value represents the bottom plate of the pile.

Constraints
N < 10^5

Output Format
Output N lines, each line containing the number written on the card.

Sample Input
5 1
3 4 7 6 5
Sample Output
4
6
3
7
5
Explanation
Initially:

A0 = [3, 4, 7, 6, 5]<-TOP

After 1st iteration:

A0 = []<-TOP

A1 = [5, 7, 3]<-TOP

B1 = [6, 4]<-TOP

Now first print B1 from top to bottom then A1 from top to bottom.


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
#include<map>
using namespace std;


int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int i, j, n, q;

	//prime seive
	int N = 100001;
	int seivearray[N];
	for (i = 0; i < N; i++) {
		seivearray[i] = 1;
	}
	// 1 means prime
	// 0 means not prime
	seivearray[0] = 0; seivearray[1] = 0;
	for (i = 2; i < N; i++) { // whose multiples to be cancelled
		if (seivearray[i] == 1) {
			// if the number is prime
			for (j = i * 2; j < N; j += i) { // multiples of prime//j=i*i can also be used for optimization
				seivearray[j] = 0;
			}
		}
	}
	// copy primes to the new array
	// here primes[i]= ith prime number
	int primes[N], k = 1;
	for (i = 2; i < N; i++) {
		if (seivearray[i] == 1) {
			primes[k] = i;
			k++;
		}
	}

	cin >> n >> q;
	int arr[n];
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	stack<int> a[q + 1], b[q + 1];
	for (i = 0; i < n; i++) {
		a[0].push(arr[i]);
	}
	for (i = 1; i <= q; i++) {
		// stored in prime vector
		int ith_prime = primes[i];

		while (!a[i - 1].empty()) {
			int x = a[i - 1].top();
			a[i - 1].pop();
			if (x % ith_prime == 0) {
				b[i].push(x);
			}
			else {
				a[i].push(x);
			}
		}

	}
	for (i = 1; i <= q; i++) {
		while (!b[i].empty()) {
			cout << b[i].top() << '\n';
			b[i].pop();
		}
	}
	while (!a[q].empty()) {
		cout << a[q].top() << '\n';
		a[q].pop();
	}

	return 0;
}


























