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

class Graph {
	list<int>*l;
	int V;
public:
	Graph(int V) {
		this->V = V;
		l = new list<int>[V]; //means we have V number of lists
	}

	void addEdge(int x, int y) {
		l[x].push_back(y);
	}
	void topological_sort() {
		//original degree i.e. indegree
		int *indegree = new int[V];
		//initialize 0 as indegree for every node
		for (int i = 0; i < V; i++)
		{
			indegree[i] = 0;
		}
		//update indegree by traversing edges x-->y (in case of a map type of graph here x will be p.first and y is p.second....there can be more than 1 p.second and hence we are iterating over them)
		//for above means indegree[y]++
		for (int i = 0; i < V; i++) {
			for (auto y : l[i]) {
				indegree[y]++;
			}
		}
		//bfs
		queue<int>q;
		//strp 1:find node with indegree 0
		for (int i = 0; i < V; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}

		}
		//start removing elements from the queue
		while (!q.empty()) {
			int node = q.front();
			cout << node << " ";

			q.pop();
			//iterate over nbrs of the node and reduce their indegree by 1
			for (auto nbr : l[node])
			{
				indegree[nbr]--;
				if (indegree[nbr] == 0)
				{
					q.push(nbr);
				}
			}
		}
	}

};

int32_t main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif


	Graph g(6);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(2, 5);
	g.addEdge(4, 5);


	g.topological_sort();
	return 0;


}
