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



// function to count the total
// number of ways to sum up to 'val'
long long int countWays(long long int notes[], long long int m, long long int val)
{
	long long int count[val + 1];
	memset(count, 0, sizeof(count));

	// base case
	count[0] = 1;

	// count ways for all values up
	// to 'val' and store the result
	for (long long int i = 1; i <= val; i++) {
		for (long long int j = 0; j < m; j++) {

			// if i >= notes[j] then
			// accumulate count for value 'i' as
			// ways to form value 'i-notes[j]'
			if (i >= notes[j]) {
				count[i] += count[i - notes[j]];
			}
		}
	}

	// required number of ways
	return count[val];

}

int32_t main() {



	long long int notes[] = {10, 20, 50, 100, 200, 500, 1000, 2000};
	long long int val = 2000;

	long long int m = sizeof(notes) / sizeof(notes[0]);
	cout << "Total number of ways = " << countWays(notes, m, val) << endl;
	return 0;
}
