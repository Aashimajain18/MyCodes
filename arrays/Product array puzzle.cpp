#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include <utility>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
#include<map>
#include<set>
using namespace std;


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
		int a[n];
		int p_all = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			p_all *= a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cout << p_all / a[i] << " ";
		}
		cout << endl;

	}
	return 0;


}
