/*
Consider an undirected graph consisting of 'n' nodes where each node is labeled from 1 to n and
the edge between any two nodes is always of length 6 . We define node 's' to be the starting
position for a BFS.

Given 'q' queries in the form of a graph and some starting node, 's' , perform each query by
calculating the shortest distance from starting node 's' to all the other nodes in the graph.
Then print a single line of n-1 space-separated integers listing node s's shortest distance to
each of the n-1 other nodes (ordered sequentially by node number); if 's' is disconnected from a
node, print -1 as the distance to that node.

Input Format
The first line contains an integer,q , denoting the number of queries. The subsequent lines
describe each query in the following format:

Each line contains N and M, the number of nodes and edges respectively.

The next m lines contains u and v means that there is edge between u and v .

The last line contains 's', the starting node.

Constraints
1 <= q <= 10 2 <= n <= 1000 1 <= m <= (n*(n-1))/2 1 <= u,s,v <= n

Output Format
You have to print n-1 integer denoting the shortest distance from s to all other nodes excluding s
itself.

Sample Input
2
4 2
1 2
1 3
1
3 1
2 3
2
Sample Output
6 6 -1
-1 6
*/

#include<iostream>
//#include <bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include<utility>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
#include<map>
#include<set>
using namespace std;

class graph {
	//adj list
	unordered_map<int, list<int> > l;
public:


	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);

	}

	void bfs(int src, int n) {
		map<int, int> dist;
		queue<int> q;
		q.push(src);
		for (int i = 1; i <= n; i++) {
			dist[i] = INT_MAX;
		}
		q.push(src);
		dist[src] = 0;


		while (!q.empty()) {
			int node = q.front();
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

		for (int i = 1; i <= n; i++)
		{
			if (i != src && dist[i] != INT_MAX) {
				cout << dist[i] * 6 << " ";
			}
			else if (i != src && dist[i] == INT_MAX) {
				cout << "-1" << " ";
			}
		}
		cout << endl;

	}


};

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, m, s, u, v;
		cin >> n >> m;
		graph g;

		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			g.addEdge(u, v);

		}
		cin >> s;
		g.bfs(s, n);
	}
	return 0;
}
