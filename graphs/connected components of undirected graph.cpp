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

template<typename T>
//GRAPH ADJACENCY LIST
class graph {

	map<T, list<T> > l;

public:

//for bidirectional edges
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);

	}

	void dfs_helper(T src, map<T, bool> &visited) {
//recursive function that will traverse the graph
		cout << src << " ";
		visited[src] = true;
		for (T nbr : l[src]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited);
			}
		}
		return;
	}

	void dfs() {
		map<T, bool>visited;
		for (auto p : l) {
			T node = p.first;
			visited[node] = false;
		}
		//call the helper function

		//iterate over all the vertices and initiate a dfs call
		int cnt = 0;

		for (auto p : l) {
			T node = p.first;
			if (!visited[node]) {
				cout << "component" << cnt << "-->";
				dfs_helper(node, visited);
				cnt++;
			}

		}
	}

};

int main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif


	graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 3);
	g.addEdge(0, 4);
	g.addEdge(5, 6);
	g.addEdge(7, 6);
	g.addEdge(8, 8);

	g.dfs();
	//g.print_adj_list();

	return 0;
}