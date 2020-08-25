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

#define MAX_CHAR 26
//time complexity-o(N*K)

// Generates a key from given string. The key
// contains all unique characters of given string in
// sorted order consisting of only distinct elements.
string getKey(string &str)
{
	bool visited[MAX_CHAR] = { false };

	// store all unique characters of current
	// word in key
	for (int j = 0; j < str.length(); j++)
		visited[str[j] - 'a'] = true ;
	string key = "";
	for (int j = 0; j < MAX_CHAR; j++)
		if (visited[j])
			key = key + (char)('a' + j);
	return key;
}

// Print all words together with same character sets.
void wordsWithSameCharSet(string words[], int n)
{
	// Stores indexes of all words that have same
	// set of unique characters.
	unordered_map <string, vector <int> > Hash;
	for (int i = 0; i < n; ++i)
	{
		string key = getKey(words[i]);
		Hash[key].push_back(i);
	}
	// print all words that have the same unique character set
	for (auto it = Hash.begin(); it != Hash.end(); it++)
	{
		for (auto v = (*it).second.begin(); v != (*it).second.end(); v++)
			cout << words[*v] << ", ";
		cout << endl;
	}
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	string arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	wordsWithSameCharSet(arr, n);

	return 0;


}



