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
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}


		//time complexity O(n^2)
		//method-1

		/*	int max_sum = 0;
			int count = 0;
			vector<int>neg_case;
			for (int j = 0; j < n; j++)
			{
				int cur_sum = 0;

				for (int i = j; i < n + j; i++)
				{
					cur_sum = cur_sum + a[i % n];
					neg_case.push_back(cur_sum);
					if (cur_sum < 0) {
						cur_sum = 0;
						count++;
					}
					max_sum = max(cur_sum, max_sum)	;
				}
			}
			if (count == n * n) {
				cout << *max_element(neg_case.begin(), neg_case.end()) << endl;
			}
			else {
				cout << max_sum << endl;
			}
			*/

		//time complexity O(n)
		//method-2
		int count = 0;
		int total_sum = 0;
		int max_sum = INT_MIN;
		int min_sum = INT_MAX;
		int cur_sum = 0;
		vector<int>neg_case;
		//kadane algorithm for max sum
		for (int j = 0; j < n; j++) {
			total_sum = total_sum + a[j];
			cur_sum = cur_sum + a[j];
			neg_case.push_back(cur_sum);

			if (cur_sum < 0) {
				cur_sum = 0;
				count++;

			}

			max_sum = max(cur_sum, max_sum)	;
		}
		int cur_sum2 = 0;
		//kadane algorithm for min sum
		for (int j = 0; j < n; j++) {
			cur_sum2 = cur_sum2 + a[j];
			if (cur_sum2 > 0) {
				cur_sum2 = 0;
			}

			min_sum = min(cur_sum2, min_sum);

		}
		if (count == n) {
			cout << *max_element(neg_case.begin(), neg_case.end()) << endl;
		}
		else {
			int max_sum2 = total_sum - min_sum;
			int ans = max(max_sum, max_sum2);
			cout << ans << endl;
		}

	}




	return 0;


}



