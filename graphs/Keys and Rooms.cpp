/*
There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 

Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.

Initially, all the rooms start locked (except for room 0). 

You can walk back and forth between rooms freely.

Return true if and only if you can enter every room.

Example 1:

Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.
Example 2:

Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.
Note:

1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
The number of keys in all rooms combined is at most 3000.
*/

//MY SOLUTION
//dfs
class Solution {
public:

    void visit(vector<vector<int>>& rooms,int i,vector<bool> &visited){
        
        visited[i]=true;
        int keys=rooms[i].size();
        
        if(keys==0){
            return;
        }
        int key;
        for(key=0;key<rooms[i].size();key++){
            if(visited[rooms[i][key]]==false){
                //room not visited yet
                visit(rooms,rooms[i][key],visited);
            }
        }
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        visit(rooms,0,visited);
        for(int i=0;i<n;i++){
             if(visited[i]==false){
              return false;   
             }
        }
    return true;
    }
};



//bfs
bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> dfs; dfs.push(0);
        unordered_set<int> seen = {0};
        while (!dfs.empty()) {
            int i = dfs.top(); dfs.pop();
            for (int j : rooms[i])
                if (seen.count(j) == 0) {
                    dfs.push(j);
                    seen.insert(j);
                    if (rooms.size() == seen.size()) return true;
                }
        }
        return rooms.size() == seen.size();
    }
