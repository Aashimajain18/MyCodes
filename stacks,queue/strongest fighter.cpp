/*
There is a group of MMA fighters standing together in a line. Given the value of their strengths, find the strength of the strongest fighter in continuous sub-groups of size k.

Input Format
First line contains an integer N, the number of fighters Followed by N integers where i'th integer denotes the strength of i'th fighter. Next line contains the size of sub-group k

Constraints
1<=N<=10^7
1<=k<=N
1 <= Ai <= 100000

Output Format
Space separated integers in a single line denoting strength of strongest fighters in the groups.

Sample Input
5
1 3 1 4 5
3
Sample Output
3 4 5
Explanation
First sub-group: 1 3 1 --> Max strength is 3
Second sub-group: 3 1 4 --> Max strength is 4
Third sub-group: 1 4 5 --> Max strength is 5
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
//same as spoj arraysub

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	int a[100000];
	int k;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> k;

	//We have to process first k elements separtely
	deque<int> Q(k);
	int i;
	for (i = 0; i < k; i++) {

		while (!Q.empty() && a[i] > a[Q.back()]) {
			Q.pop_back();
		}
		Q.push_back(i);

	}
	//Process the remaining elements
	for (; i < n; i++) {
		cout << a[Q.front()] << " ";

		//1. Remove the elements which are not the part of the window(Contraction)
		while ((!Q.empty() && (Q.front() <= i - k))) {
			Q.pop_front();
		}

		//2. Remove the elements which are not useful and are in window
		while (!Q.empty() && a[i] >= a[Q.back()]) {
			Q.pop_back();
		}

		//3. Add the new elements(Expansion)
		Q.push_back(i);
	}

	cout << a[Q.front()] << endl;


	return 0;


	return 0;
}



