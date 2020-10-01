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
#include<climits>
using namespace std;

vector<int> bellman_ford(int v, int src, vector<vector<int> > edges) {
	//create a vector
	vector<int> dist(v + 1, INT_MAX); //initializing all values to infinty
	dist[src] = 0;
	//relax all edges v-1 times
	for (int i = 0; i < v; i++) {
		//go to all egdes in the edge list
		for (auto edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];

			if (dist[u] != INT_MAX /*so that it doesn't overflow*/ and dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}
		}
	}
//check negative wt cycle
	//we need to run the above loop one more time
	for (auto edge : edges) {
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];

		if (dist[u] != INT_MAX /*so that it doesn't overflow*/ and dist[u] + wt < dist[v]) {
			cout << "negative wt cycle present";
			exit(0);
		}
	}

	return dist;
}

int32_t main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n, m;//n is for nodes and m is for number of edges
	cin >> n >> m;

//edge list
	vector<vector<int> > edges; //(a,b,3) (c,d,5) ...
	for (int i = 0; i < m; i++)
	{
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back({u, v, wt});//this type of declaration is not available in sublime text so run it in coding blocks ide instead


	}
//bellman algo
	vector<int> distances = bellman_ford(n, 1, edges);
	for (int i = 1; i <= n; i++) {
		cout << "node " << i << " is at distance " << distances[i] << endl;
	}

	return 0;


}
