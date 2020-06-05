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

	int n;
	cin >> n;
	int mid = ((n + 1) / 2) - 1;
	for (int i = 0; i < n; i++) {


		for (int j = 0; j < n; j++) {
			if (i == mid) {
				cout << "*";

			}
			else if (j == 0 && i < mid) {
				cout << "*";

			}
			else if (j == n - 1 && i > mid) {
				cout << "*";

			}
			else if (j == mid) {
				cout << "*";

			}
			else if (i == 0 && j > mid) {
				cout << "*";
			}
			else if (i == n - 1 && j < mid) {
				cout << "*";
			}
			else {
				cout << " ";
			}

		}
		cout << endl;

	}
	return 0;
}


