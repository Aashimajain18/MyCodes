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


//GRAPH ADJACENCY LIST
class graph {
	//v are the nuber of vertices
	int v;
	//array of lists
	list<int> *l;
public:
	graph(int v) {
		this->v = v;
		l = new list<int>[v];
	}

//for bidirectional edges
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);

	}
	void print_adj_list() {

		for (int i = 0; i < v; i++) {
			cout << " vertex " << i << "->";
			for (auto nbr : l[i]) {
				cout << nbr << ",";
			}
			cout << endl;
		}

	}

};


int main()
{
	/*
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	*/

	graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 2);
	g.print_adj_list();

	return 0;
}

