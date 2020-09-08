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

	bool cycle_helper(int node, bool *visited, bool *stack) {
		//when u visit a node
		visited[node] = true;
		stack[node] = true;

		for (int nbr : l[node]) {
			//two cases
			if (stack[nbr] == true) { //means it is a case of back edge
				return true;
			}
			else if (visited[nbr] == false) {
				bool cycle_mili = cycle_helper(nbr, visited, stack);
				if (cycle_mili == true) {
					return true;
				}
			}

		}
//when you leave a node
		stack[node] = false;
		return false;
	}

	bool contain_cycle() {
		bool *visited = new bool[V];
		bool *stack = new bool[V];
		for (int i = 0; i < V; i++)
		{
			visited[i] = stack[i] = false;
		}
		return cycle_helper(0, visited, stack);
	}
};

int32_t main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif


	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(3, 4);
	g.addEdge(2, 3);
	g.addEdge(4, 5);
	g.addEdge(1, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 2);//back edge



	if (g.contain_cycle()) {
		cout << "yes cycle is present" << endl;
	}
	else {
		cout << "no cycle is not present" << endl;
	}
	return 0;


}
