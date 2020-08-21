#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<deque>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
#include<map>
using namespace std;



//GRAPH ADJACENCY LIST implementaion for generic tree
class graph {
	//adj list
	unordered_map<string, list<pair<string, int> > >l;
public:
	graph() {
	}

	void add_edge(string x, string y, bool bidirec, int weight) {
		l[x].push_back(make_pair(y, weight));
		if (bidirec) {
			l[y].push_back(make_pair(x, weight));

		}

	}
	void print_adj_list() {
		for (auto p : l) {
			string keyCity = p.first;
			//list<pair<string,int>>nbrs=p.second       or
			auto nbrs = p.second; //list of neighbours

			cout << keyCity << "->";
			for (auto nbr : nbrs) {
				//to read more about the above for loop-refer-> https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
				cout << nbr.first << " " << nbr.second << ",";
			}
			cout << endl;


		}

	}

};


int main()
{
	/*
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	*/

	graph g;
	g.add_edge("a", "b", true, 20);
	g.add_edge("b", "d", true, 40);

	g.add_edge("a", "c", true, 10);

	g.add_edge("c", "d", true, 40);

	g.add_edge("a", "d", false, 50);


	g.print_adj_list();

	return 0;
}