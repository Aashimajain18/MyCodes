/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Constraints:

1 <= N <= 2000
0 <= dislikes.length <= 10000
dislikes[i].length == 2
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].

*/


class Solution {
public:
    bool dfs_helper(vector<int> graph[], int node, vector<int> &visited, int parent, int colour) {
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
	
    vector<int> visited(N+1,0);//0 for not visited, 1 for colour 1 and visited and 2 for colour 2 and visited
	// for (int i = 1; i <= N; i++) {
	// 	visited[i] = 0;
	// }
	int colour = 1;//init
for(int i=1;i<=N;i++){
            if(visited[i]==0){
                visited[i]=1;

	if(dfs_helper(graph, i, visited, -1, colour)==false){
        return false;
    }
    }
}

	return true;
}

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int size=dislikes.size();
        // vector<int> visited(N,0);//0 for not visited, 1 for colour 1 and visited and 2 for colour 2 and visited
        vector<int> graph[N+1];
        for(int i=0;i<size;i++){
            int x=dislikes[i][0];
            int y=dislikes[i][1];
            graph[x].push_back(y);
		graph[y].push_back(x);
        }
        if (dfs(graph, N)) {
		//cout << "yes it's bipartite";
            return true;
	}
	
		//cout << "no it's not bipartite";
        return false;
	

    }
};
