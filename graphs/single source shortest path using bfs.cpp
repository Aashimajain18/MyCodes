
#include<iostream>
#include<vector>
#include<cstring>
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
class graph {
	//adj list
	unordered_map<T, list<T> > l;
public:
	graph() {
	}

	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);

	}


	void bfs(T src) {
		map<T, int> dist;
		queue<T> q;
		q.push(src);

		//all other nodes will have INT_MAX
		for (auto node_pair : l) {
			T node = node_pair.first;
			dist[node] = INT_MAX;
		}
		q.push(src);
		dist[src] = 0;


		while (!q.empty()) {
			T node = q.front();
			q.pop();
			//cout << node << " ";
			for (auto nbr : l[node]) {
				if (dist[nbr] == INT_MAX) {
					q.push(nbr);
					dist[nbr] = dist[node] + 1;


				}
			}
		}
		//print the distance to every node
		for (auto node_pair : l) {
			T node = node_pair.first;
			int d = dist[node];
			cout << "node " << node << " distance from source is " << d << endl;
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

	graph <int>g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(3, 0);
	g.addEdge(4, 5);
	g.bfs(0);

	return 0;
}
