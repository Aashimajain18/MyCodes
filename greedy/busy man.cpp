/*
You are actually very busy man. You have a big schedule of activities. Your aim is to do as much as
activities as possible.



In the given figure, if you go to date with crush, you cannot participate in the coding contest and you
can’t watch the movie. Also if you play DotA, you can’t study for the exam. If you study for the exam you
can’t sleep peacefully. The maximum number of activities that you can do for this schedule is 3.

Either you can

watch movie, play DotA and sleep peacefully (or)
date with crush, play DotA and sleep peacefully
Input Specifications

The first line consists of an integer T, the number of test cases. For each test case the first line consists
of an integer N, the number of activities. Then the next N lines contains two integers m and n, the start and
end time of each activity.

Output Specifications

For each test case find the maximum number of activities that you can do.

Input Constraints

1 <= T <=10
1 <= N <= 100000
0 <= start < end <= 1000000

Example

Sample Input: (empty lines just for clarity)
3
3
3 9
2 8
6 9

4
1 7
5 8
7 8
1 8

6
7 9
0 10
4 5
8 9
4 10
5 7

Sample Output:
1
2
3
 Submit solution!

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
#define om map<int, vector<int> >
#define um unordered_map<int, vector<int> >

int busy_man(vector<pair<int, int> > v, int n) {
	int ans = 1;
	int fin = v[0].second;
	for (int i = 1; i < n; ++i)
	{
		if (v[i].first >= fin) {
			ans++;
			fin = v[i].second;
		}
	}
	return ans;
}


bool compare( pair<int, int> &a, pair<int, int> &b)
{
	return (a.second < b.second);
}
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a, b;
		vector<pair<int, int> >act;
		for (int i = 0; i < n; ++i)
		{
			cin >> a >> b;

			act.push_back(make_pair(a, b));
		}
		sort(act.begin(), act.end(), compare);
		cout << busy_man(act, n) << endl;

	}

	return 0;


}



