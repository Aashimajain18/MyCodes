/*You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Input Format
First line contains integer t as number of test cases. Next t lines contains two lines. For each test case, 1st line contains two integers n and m which represents the number of books and students and 2nd line contains n space separated integers which represents the number of pages of n books in ascending order.

Constraints
1 < t < 50
1< n < 100
1< m <= 50
1 <= Ai <= 1000

Output Format
Print the maximum number of pages that can be assigned to students.

Sample Input
1
4 2
12 34 67 90
Sample Output
113
Explanation
1st students : 12 , 34, 67 (total = 113)
2nd students : 90 (total = 90)
Print max(113, 90)*/

#include<iostream>
//#include <bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include<utility>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
#include<map>
#include<set>
using namespace std;

bool ispossible(int n, int m, int a[], int curr_min) {
	int student_used = 1;
	int pages_reading = 0;
	int i = 0;
	while (n--) {
		if (pages_reading + a[i] > curr_min) {
			student_used++;
			pages_reading = a[i];
			if (student_used > m) {
				return false;
			}
		}
		else {
			pages_reading += a[i];

		}
		i++;
	}

	return true;
}

int findpages(int n, int m, int a[]) {
	if (n < m) {
		return -1;
	}
	int start = a[n - 1];
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	int end = sum;
	int ans = INT_MAX;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (ispossible(n, m, a, mid)) {
			ans = min(ans, mid);
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return ans;
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << findpages(n, m, a) << endl;
	}
	return 0;
}
