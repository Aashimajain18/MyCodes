
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include <utility>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
#include<map>
#include<set>
using namespace std;

class Graph {
	//adjacency list
	std::vector<pair<int, int> > *l;
	int V;
public:
	Graph(int n) {
		V = n;
		l = new vector<pair<int, int> > [n];
	}
	void addEdge(int x, int y, int w) {
		l[x].push_back({y, w});
		l[y].push_back({x, w});

	}
	int prim_mst() {
		priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > q ;
		//another array
		//visited array that denotes whether a node has been included in mst or not
		bool *vis = new bool[V] {0}; //initialized with all zeros
		int ans = 0;
		//begin
		q.push({0, 0}); //weight,node
		while (!q.empty()) {
			//pick edge with min weight
			auto best = q.top();
			q.pop();

			int to = best.second;
			int weight = best.first;
			if (vis[to]) {
				//discard the edge and continue
				continue;
			}
			//otherwise take the curr edge
			ans += weight;
			vis[to] = 1;
			//add the new edge to the queue
			for (auto x : l[to]) {
				if (vis[x.first] == 0) {
					q.push({x.second, x.first});
				}
			}
		}

		return ans;
	}
};

int32_t main()
{



	int n, m;
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		g.addEdge(x - 1, y - 1, z);
	}
	cout << g.prim_mst() << endl;
	return 0;


}
