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

void print(vector<int> v) {
	for (int i = 1; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

bool minHeap = false;


bool comparator(int a, int b) {
	if (minHeap) {
		return a < b;
	}
	else {
		return b < a;
	}
}


void heapify(vector<int>&v, int idx, int size) {
	//i here is index
	int left = 2 * idx;
	int right = left + 1;

	int min_idx = idx;
	int last = size - 1;
	if (left <= last && comparator(v[left], v[idx])) {
		min_idx = left;
	}
	if (right < last && comparator(v[right], v[min_idx])) {
		min_idx = right;
	}
	if (min_idx != idx) {
		//acts as base case as well
		swap(v[idx], v[min_idx]);
		heapify(v, min_idx, size);
	}
}

//ARRAY TO HEAP
//METHOD-2
//O(n)bool minHeap;

//BOTTOM TO TOP APPROACH
void build_heap(vector<int>&v) {

	for (int i = (v.size() - 1) / 2 ; i >= 1 ; i--)
	{
		heapify(v, i, v.size());

	}
}

void heapsort(vector<int> &arr) {
	build_heap(arr);
	int n = arr.size();
	//remove n-1 elements from the heap
	while (n > 1) {
		swap(arr[1], arr[n - 1]);
		n--;
		heapify(arr, 1, n);
	}
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	vector<int> v;
	v.push_back(-1);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	heapsort(v);
	print(v);



	return 0;

}
