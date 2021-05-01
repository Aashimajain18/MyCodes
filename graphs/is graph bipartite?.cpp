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

bool dfs_helper(vector<int> graph[], int node, int *visited, int parent, int colour) {
	visited[node] = colour;

	for (auto nbr : graph[node]) {
		if (visited[nbr] == 0) {
			bool sub_prob = dfs_helper(graph, nbr, visited, node, 3 - colour);
			if (sub_prob == false) {
				return false;
			}
		}
		//else it's already visited
		else if (nbr != parent && visited[nbr] == colour) {
			//not bipartite
			return false;
		}
	}

	return true;
}



bool dfs(vector<int> graph[], int N) {
	int visited[N] ; // 0 means not visited, 1 means it's visited and colour is 1 and 2 means it's visited and colour is 2
	for (int i = 0; i < N; i++) {
		visited[i] = 0;
	}
	int colour = 1;
	int ans = dfs_helper(graph, 0, visited, -1, colour);

//print colours
	for (int i = 0; i < N; i++)
	{
		cout << i << "- colour " << visited[i] << endl;
	}

	return ans;
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int N, M;
	cin >> N >> M;
	vector<int> graph[N];
//n nodes and m edges
	while (M--) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);

	}

	//we can use BFS or DFS
	//we will colour alternate nodes at each step that means if current node has colour 0 then it's nbr should have colour 1
	if (dfs(graph, N)) {
		cout << "yes it's bipartite";
	}
	else {
		cout << "no it's not bipartite";
	}

	return 0;
}



