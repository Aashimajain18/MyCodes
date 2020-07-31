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
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int t;
	cin >> t;
	while (t--) {
		int key;
		cin >> key;

		bool present = binary_search(a, a + n, key);
		if (present) {
			cout << "present" << endl;
		}
		else {
			cout << "not present" << endl;

		}


//to get the index of the element
		//below given all functions take log(n) time
		//lower_bound or upper_bound stl functions give the address
		auto lb = lower_bound(a, a + n, key); //it will return the first bucket that is greater than or equal to the key
		cout << "lower bound of the given key is " << (it - a) << endl;

		auto ub = upper_bound(a, a + n, key); //it will return the first bucket that is strictly greater than to the key
		cout << "upper bound of the given key is " << (it - a) << endl;

//upper_bound -lower_bound will give the freq of the given key in the sorted array


//occurence freq
		cout << "occurence freq" << ub - lb << endl;
	}

	return 0;


}
