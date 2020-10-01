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

class DSU {
	int *parent;
	int *rank;
public:
	DSU(int n) {
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++)
		{
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int i) {
		if (parent[i] == -1) {
			return i;

		}
		return parent[i] = find(parent[i]);
	}


	void unionSet(int x, int y) {
		int S1 = find(x);
		int S2 = find(y);
		if (S1 != S2) {
			if (rank[S1] < rank[S2]) {
				parent[S1] = S2;
				rank[S2] += rank[S1];
			}
			else {
				parent[S2] = S1;
				rank[S1] += rank[S2];

			}
		}

		return;

	}
};

class Graph {
	vector<vector<int> > edgelist;
	int V;
public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int x, int y, int w) {
		edgelist.push_back({w, x, y}); //sorting will be done on the basis of first parameter hence we wrote w first
	}

	int kruksal_mst() {
		//sort all the edges based on their weights
		sort(edgelist.begin(), edgelist.end());

		//init a DSU
		DSU s(V);


		int ans = 0;
		for (auto edge : edgelist) {
			//edge here is a vector containing 3 elements
			int w = edge[0];
			int u = edge[1];
			int v = edge[2];
			//take that edge in mst if it doesn't form a cycle
			if (s.find(u) != s.find(v)) {
				s.unionSet(u, v);
				ans += w;
			}
		}
		return ans;
	}

};

int32_t main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

//in this code indexing is zero based
	Graph g(4);
	g.addEdge(0, 1, 1);
	g.addEdge(1, 3, 3);
	g.addEdge(3, 2, 4);
	g.addEdge(2, 0, 2);
	g.addEdge(0, 3, 2);
	g.addEdge(1, 2, 2);
	cout << g.kruksal_mst() << endl;

	return 0;


}
