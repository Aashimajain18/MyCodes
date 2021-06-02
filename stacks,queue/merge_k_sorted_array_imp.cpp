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

typedef pair < int, pair<int, int> >custom_node;
//each node will store value,arr_idx and element_idx in this order only

vector<int> merge_k_sorted_arrays(vector<vector<int> >arr) {
	vector<int> result;
	//by default greater will sort according to the first element
	priority_queue < custom_node, vector<custom_node>, greater<custom_node> > pq; //min heap

	//insert the 0th element of every array in the pq
	for (int i = 0; i < arr.size(); i++)
	{
		pq.push({arr[i][0], {i, 0}});

	}
	//remove the elements one by one from the heap and add them to result vector
	while (!pq.empty()) {
		custom_node current = pq.top();
		pq.pop();
		int element = current.first;
		int x = current.second.first; //row in which element is present
		int y = current.second.second; //col in which element is present
		result.push_back(element);
//you need to push in PQ the next element of current element i.e. x,y+1
		if (y + 1 < arr[x].size()) {
			pq.push({arr[x][y + 1], {x, y + 1}});
		}


	}
	return result;



}

int32_t main() {

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	vector<vector<int> >arr {{2, 6, 12, 15}, {1, 3, 14, 20}, {3, 5, 8, 10}};
	vector<int> output = merge_k_sorted_arrays(arr);
	for (auto x : output) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}



