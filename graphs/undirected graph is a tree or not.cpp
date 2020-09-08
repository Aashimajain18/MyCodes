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
		l[y].push_back(x);
	}
	//this function basically checks that if there is a cycle present in the graph or not
	bool is_tree() {
		bool *visited = new bool[V];
		int *parent = new int[V];
		queue<int>q;

		for (int i = 0; i < V; i++)
		{
			visited[i] = false;
			parent[i] = i;
		}

		int src = 0;
		q.push(src);
		visited[src] = true;
		//pop out one node from the queue and visit it's nbrs
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int nbr : l[node]) {
				if (visited[nbr] == true and parent[node] != nbr) {
					return false;//this graph is not a tree
				}
				else if (!visited[nbr]) {
					visited[nbr] = true;
					parent[nbr] = node;
					q.push(nbr);

				}
			}
		}

		return true;
	}
};

int32_t main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif


	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 3);
	g.addEdge(2, 3);


	if (g.is_tree()) {
		cout << "graph is a tree" << endl;
	}
	else {
		cout << "graph is not a tree" << endl;
	}
	return 0;

}