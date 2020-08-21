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
		map<T, bool> visited;
		queue<T> q;
		q.push(src);
		visited[src] = true;

		while (!q.empty()) {
			T node = q.front();
			q.pop();
			cout << node << " ";
			for (auto nbr : l[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;


				}
			}
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
	g.addEdge(4, 5);
	g.bfs(0);

	return 0;
}