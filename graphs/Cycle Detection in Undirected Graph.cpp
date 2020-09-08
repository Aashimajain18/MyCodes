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

class Graph {
	list<int>*l;
	int V;
public:

	Graph(int V) {
		this->V = V;
		l = new list<int>[V]; //means we have V number of lists
	}

//for bidirectional edges
	void addEdge(int x, int y, bool directed = true) {
		l[x].push_back(y);
		if (!directed) {
			l[y].push_back(x);
		}
	}

	bool cycle_helper(int node, bool *visited, int parent) {
		//when u visit a node
		visited[node] = true;

		for (int nbr : l[node]) {
			//two cases
			if (visited[nbr] == false) {
				//go and recursively visit the nbr
				bool cycle_mili = cycle_helper(nbr, visited, node);
				if (cycle_mili == true) {
					return true;
				}
			}
			//nbr is visited but that nbr should not be equal to parent which means cycle is present
			else if (nbr != parent) {
				return true;
			}

		}
		return false;//that means cycle is not present
	}

	bool contain_cycle() {
		bool *visited = new bool[V];
		for (int i = 0; i < V; i++)
		{
			visited[i] = false;
		}
		return cycle_helper(0, visited, -1 );
	}
};

int32_t main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif


	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(3, 4);
	g.addEdge(2, 3);
	g.addEdge(4, 0);




	if (g.contain_cycle()) {
		cout << "yes cycle is present" << endl;
	}
	else {
		cout << "no cycle is not present" << endl;
	}
	return 0;


}
