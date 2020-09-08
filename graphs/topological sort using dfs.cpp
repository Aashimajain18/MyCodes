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
	void addEdge(T x, T y) {
		l[x].push_back(y);
		// l[y].push_back(x);

	}

	void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering) {
//recursive function that will traverse the graph
		// cout << src << " ";
		visited[src] = true;
		//go to all neighnours of the node that are not visited
		for (T nbr : l[src]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited, ordering);
			}
		}
		//just before returning
		ordering.push_front(src);
		return;
	}

	void dfs() {
		map<T, bool>visited;
		list<T> ordering;
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
				dfs_helper(node, visited, ordering);
				cnt++;
			}

		}
		//finally print the list
		for (auto node : ordering) {
			cout << node << endl;
		}
	}

};

int main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif


	graph<string> g;
	g.addEdge("python", "data processing");
	g.addEdge("python", "pyTorch");
	g.addEdge("python", "ML");
	g.addEdge("data processing", "ML");
	g.addEdge("pyTorch", "DL");
	g.addEdge("DL", "face recognition");
	g.addEdge("Data set", "face recognition");


	g.dfs();
	//g.print_adj_list();

	return 0;
}