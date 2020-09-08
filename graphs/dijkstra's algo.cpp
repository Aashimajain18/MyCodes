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
#include<set>
using namespace std;

template<typename T>
class graph {
	unordered_map < T, list<pair<T, int> > > m;
public:
	void addEdge(T u, T v, int dist, bool bidir = true) {
		m[u].push_back(make_pair(v, dist));
		if (bidir)
		{
			m[v].push_back(make_pair(u, dist));
		}
	}

	void print_adj_list() {
		//iterate over all key value pair in the map
		for (auto j : m) {
			cout << j.first << "->"; //prints the key(that is the city)
			//iterate over the list of cities
			for (auto l : j.second) { //j.second refers to the list adjacent to the key
				cout << "(" << l.first << "," << l.second << ")" << " "; //l.first refers to destination city and l.second refers to the distance or cost
			}
			cout << endl;
		}
	}

	void dijkstra_algo(T src) {
		unordered_map<T, int> dist;
		//set all distamces to infinity
		for (auto j : m) {
			dist[j.first] = INT_MAX;
		}
		//make e a set to find out a node with min distance
		set<pair<int, T> >s; //by default set sorts according to the first paramenter hence int is taken before
		dist[src] = 0;
		s.insert(make_pair(0, src));
		while (!s.empty()) {
			//find the pair at front
			auto p = *(s.begin());
			T node = p.second;
			int nodeDist = p.first;
			s.erase(s.begin());//like pop function
			//iterate over nbrs/children of cuurent node
			for (auto childPair : m[node]) {

				if (nodeDist + childPair.second < dist[childPair.first]) {

					// to update in set we will remove the old pair and then add the new pair to simulate updation
					T dest = childPair.first;
					auto f = s.find(make_pair(dist[dest], dest));
					if (f != s.end()) {
						s.erase(f);
					}
					//insert the new pair
					dist[dest] = nodeDist + childPair.second;
					s.insert(make_pair(dist[dest], dest));
				}
			}
		}
		//print dist to all other nodes from src
		for (auto d : dist) {
			cout << d.first << " is located at a distance of  " << d.second;
			cout << endl;

		}

	}

};

int32_t main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	// graph<int>g;
	// g.addEdge(1, 2, 1);
	// g.addEdge(1, 3, 4);
	// g.addEdge(2, 3, 1);
	// g.addEdge(3, 4, 2);
	// g.addEdge(1, 4, 7);
	// g.dijkstra_algo(1);

	graph<string>india;
	india.addEdge("amritsar", "delhi", 1);
	india.addEdge("amritsar", "jaipur", 4);
	india.addEdge("jaipur", "delhi", 2);
	india.addEdge("jaipur", "mumbai", 8);
	india.addEdge("bhopal", "agra", 2);
	india.addEdge("mumbai", "bhopal", 3);
	india.addEdge("agra", "delhi", 1);
	// india.print_adj_list();
	india.dijkstra_algo("amritsar");

	return 0;


}
