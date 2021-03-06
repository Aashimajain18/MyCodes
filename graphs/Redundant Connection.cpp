/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

*/


//my solution
class Solution {
public:
    //vector<pair<int,int>> ans;
    vector<int> ans;
    int find(int i,int parent[]){
        if(parent[i]==-1){
            return i;
        }
        parent[i]=find(parent[i],parent);
        return parent[i];
    }
    
   void unionSet(int x, int y, int parent[], int rank[]) {
		int S1 = find(x, parent);
		int S2 = find(y, parent);
		if (S1 != S2) {
			if (rank[S1] < rank[S2]) {
				parent[S1] = S2;
				rank[S2] += rank[S1];
			}
			else {
				parent[S2] = S1;
				rank[S1] += rank[S2];

			}
		}


		return;

	}
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       // int size=ans.size();
        int n=edges.size();
        int parent[n+1];
        int rank[n+1];
        for(int i=1;i<=n;i++){
            parent[i]=-1;
            rank[i]=1;
        }
        
        //iterate over the edge list
		for (auto edge : edges) {
			int i = edge[0];
			int j = edge[1];
			int S1 = find(i, parent);
			int S2 = find(j, parent);
			if (S1 != S2) {
				unionSet(S1, S2, parent, rank);
			}
			else {
    //s1==s2
       if(i<j){
           //ans.push_back(make_pair{x,y});
           ans.push_back(i);
               ans.push_back(j);
           return ans;
       }
				
			}

		}

		
        return ans;
    }
};
