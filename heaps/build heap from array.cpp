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
	for (int i = 0; i < v.size(); ++i)
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


//ARRAY TO HEAP
//METHOD-1
//O(Nlog(N))
//TOP TO BOTTOM APPROACH
void build_heap(vector<int>&v) {

	for (int i = 2; i < v.size(); i++)
	{
		int index = i;
		int parent = index / 2;

		while (index > 1 && comparator(v[index], v[parent])) {
			swap(v[index], v[parent]);
			index = parent;
			parent  = parent / 2;
		}


	}

}
void heapify_with_vector(vector<int>&v, int i) {
	//i here is index
	int left = 2 * i;
	int right = left + 1;

	int min_i = i;
	if (left < v.size() && comparator(v[left], v[i])) {
		min_i = left;
	}
	if (right < v.size() && comparator(v[right], v[min_i])) {
		min_i = right;
	}
	if (min_i != i) {
		//acts as base case as well
		swap(v[i], v[min_i]);
		heapify_with_vector(v, min_i);
	}
}

//ARRAY TO HEAP
//METHOD-2
//O(n)bool minHeap;

//BOTTOM TO TOP APPROACH
void build_heap_optimized(vector<int>&v) {

	for (int i = (v.size() - 1) / 2 ; i >= 1 ; i--)
	{
		heapify_with_vector(v, i);

	}

}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	print(v);
	build_heap_optimized(v);
	print(v);



	return 0;


}



