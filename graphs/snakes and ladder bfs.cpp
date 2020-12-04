#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
#include<map>
using namespace std;
#define om map<int, vector<int> >
#define um unordered_map<int, vector<int> >

template<typename T>
//Graph ADJACENCY LIST
class Graph {

    map<T, list<T> > l;

public:

//for bidirectional edges
    void addEdge(int x, int y) {
        l[x].push_back(y);
        //l[y].push_back(x);

    }

    void bfs(T src, T dest) {
        map<T, int>dist;
        map < T, T> parent;
        queue<T> q;

        //all other nodes will have INT_MAX
        for (auto node_pair : l) {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        parent[src] = src;



        while (!q.empty()) {
            T node = q.front();
            q.pop();
            //cout << node << " ";
            for (auto nbr : l[node]) {
                if (dist[nbr] == INT_MAX) {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                    parent[nbr] = node;

                }
            }
        }
        //print the distance to dest node
        //dest to src
        T temp = dest;
        while (parent[temp] != temp) { //or while(temp!=src)
            cout << temp << "<-";
            temp = parent[temp];
        }
        cout << src << endl;
    }
};

int32_t main()
{


    Graph<int>g;
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;


    for (int i = 0; i < 36; i++) {
        for (int dice = 1; dice <= 6; dice++) {
            int j = i + dice;
            j += board[j];

            if (j <= 36) {
                g.addEdge(i, j);
            }
        }
    }

    g.bfs(0, 36);
    return 0;
}
