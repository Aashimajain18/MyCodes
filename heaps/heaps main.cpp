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

class Heap {
	vector<int>v;
	bool minHeap;

	bool compare(int a, int b) {
		if (minHeap) {
			return a < b;
		}
		else {
			return b < a;
		}
	}


	void heapify(int i) {
		//i here is index
		int left = 2 * i;
		int right = left + 1;

		int min_i = i;
		if (left < v.size() && compare(v[left], v[i])) {
			min_i = left;
		}
		if (right < v.size() && compare(v[right], v[min_i])) {
			min_i = right;
		}
		if (min_i != i) {
			//acts as base case as well
			swap(v[i], v[min_i]);
			heapify(min_i);
		}
	}

public:

	Heap(int default_size = 10, bool type = true) {
		v.reserve(default_size);
		v.push_back(-1);//to block first index of the array
		minHeap = type;

	}

	void push(int d) {

		v.push_back(d);
		int index = v.size() - 1;
		int parent = index / 2;

		while (index > 1 && compare(v[index], v[parent])) {
			swap(v[index], v[parent]);
			index = parent;
			parent  = index / 2;
		}
	}
	int top() {
		return v[1];
	}
//Remove Min
	void pop() {
		int index  = v.size() - 1;
		swap(v[1], v[index]);
		v.pop_back();
		heapify(1);
	}

	bool empty() {
		return v.size() == 1;
	}


};



int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*
	//give some initial size,and type->min or max
		Heap h;
		//if we write heap(10,false) then it will behave as a max heap
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int no;
			cin >> no;
			h.push(no);

		}
		while (!h.empty()) {
			cout << h.top() << " ";
			h.pop();
		}
		*/


	return 0;


}



