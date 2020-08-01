#include<iostream>
#include<queue>//by default it is a max heap
#include<vector>
using namespace std;

class Fun {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main() {
	//priority_queue<int> hmax;//for max heap
	//priority_queue<int,vector<int>,greater<int> > h;//for min heap
	priority_queue<int, vector<int>, greater<int> > h;


	int a[] = {4, 3, 2, 1, 5, 7, 6};
	int n = 7;

	for (int i = 0; i < n; i++) {
		h.push(a[i]);
	}
	while (!h.empty()) {
		cout << h.top() << " ";
		h.pop();
	}

	return 0;
}