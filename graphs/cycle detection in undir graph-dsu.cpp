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
#include<set>
using namespace std;

class graph {
	int V;
	list<pair<int, int> >l;
public:
	graph(int V) {
		this->V = V;
	}

	void addEdge(int u, int v) {
		l.push_back(make_pair(u, v));
	}

	//DSU FIND
	//time complexity=O(N)
	int findSet(int i, int parent[]) {
		if (parent[i] == -1) {
			return i;

		}
		return findSet(parent[i], parent);
	}
	//DSU UNION
	void unionSet(int x, int y, int parent[]) {
		int S1 = findSet(x, parent);
		int S2 = findSet(y, parent);
		if (S1 != S2) {
			parent[S1] = S2;
		}

		return;

	}

	bool contains_cycle() {
		//we will use DSU logic to check if graph contains cycle or not
		int *parent = new int[V];
		for (int i = 0; i < V; i++)
		{
			parent[i] = -1;
		}
		//iterate over the edge list
		for (auto edge : l) {
			int i = edge.first;
			int j = edge.second;
			int S1 = findSet(i, parent);
			int S2 = findSet(j, parent);
			if (S1 != S2) {
				unionSet(S1, S2, parent);
			}
			else {
				cout << "Same parents " << S1 << " and " << S2 << endl;
				return true;
			}

		}
		delete [] parent;
		return false;
	}
};


int32_t main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);
	g.contains_cycle();
	cout << endl;
	return 0;


}
