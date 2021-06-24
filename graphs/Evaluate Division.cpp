/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.

*/

//dfs
class Solution {
public:
    double dfs(string start, string end, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited){
        if(graph.find(start) == graph.end()){
            return -1;
        }
        
        if(graph[start].find(end) != graph[start].end()){
            return graph[start][end];
        }
        
        for(const auto& nei : graph[start]){
            if(find(visited.begin(), visited.end(), nei.first) != visited.end())
                continue;
            visited.insert(nei.first);
            double res;
            if((res = dfs(nei.first, end, graph, visited)) != -1){
                //optimization: runtime 4ms -> 0ms
                return graph[start][end] = graph[start][nei.first] * res;
            }
        }
        
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> quot;
        
        int N = equations.size();
        
        for(int i = 0; i < N; i++){
            const vector<string>& equation = equations[i];
            const string& num = equation[0], den = equation[1];
            const double& value = values[i];
            quot[num][num] = 1.0;
            quot[den][den] = 1.0;
            quot[num][den] = value;
            quot[den][num] = 1.0/value;
        }
        
        vector<double> ans;
        unordered_set<string> visited;
        
        for(const vector<string>& query : queries){
            const string& num = query[0], den = query[1];
            visited = {num};
            ans.push_back(dfs(num, den, quot, visited));
        }
        
        return ans;
    }
};

/*
logic
Binary relationship is represented as a graph usually.
Does the direction of an edge matters? -- Yes. Take a / b = 2 for example, it indicates a --2--> b as well as b --1/2--> a.
Thus, it is a directed weighted graph.
In this graph, how do we evaluate division?
Take a / b = 2, b / c = 3, a / c = ? for example,

a --2--> b --3--> c
We simply find a path using DFS from node a to node c and multiply the weights of edges passed, i.e. 2 * 3 = 6.

Please note that during DFS,

Rejection case should be checked before accepting case.
Accepting case is (graph.get(u).containsKey(v)) rather than (u.equals(v)) for it takes O(1) but (u.equals(v)) takes O(n) for n is the length of the longer one between u and v.

*/
