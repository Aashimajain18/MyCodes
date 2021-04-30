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


#define INF 10000 //bcoz adding something to INT_MAX can give an error so for a large value instead of INT_MAX we'll use INF

//Time complexity
//O(V^3)
//and Space complexity is O(V^2)

vector<vector<int> >floyd_warshall(vector<vector<int> >graph) {
	vector<vector<int> >dist(graph);
	int V = graph.size();
//Phases, in Kth phase we included vertices(1,2,...k) as intermediate vertices
	for (int k = 0; k < V; k++)
	{
		//iterate over entire 2D matrix
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				//if vertix k is included, can we minimize the distance?
				//that is what is the path from i to j if we pass through k
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	return dist;

}

int32_t main() {

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	//4 vertices
	//4x4 matrix
	vector<vector<int> > graph = {
		{0, INF, -2, INF},
		{4, 0, 3, INF},
		{INF, INF, 0, 2},
		{INF, -1, INF, 0}
	};

	auto result = floyd_warshall(graph);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result.size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;

	}
	cout << endl;
	return 0;
}


