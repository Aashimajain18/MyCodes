#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include <utility>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
#include<map>
#include<set>
using namespace std;

//using queue
// Iterative function to generate all binary strings
// formed by replacing each wildcard character by 0
// or 1
void print1(string str)
{
	queue<string> q;
	q.push(str);

	while (!q.empty())
	{
		string str = q.front();

		// find position of first occurrence of wildcard
		size_t index = str.find('?');

		// If no matches were found,
		// find returns string::npos
		if (index != string::npos)
		{
			// replace '?' by '0' and push string into queue
			str[index] = '0';
			q.push(str);

			// replace '?' by '1' and push string into queue
			str[index] = '1';
			q.push(str);
		}

		else
			// If no wildcard characters are left,
			// print the string.
			cout << str << endl;

		q.pop();
	}
}


//using recursion
void print(string str, int index)
{
	if (index == str.size())
	{
		cout << str << " ";
		return;
	}

	if (str[index] == '?')
	{
		// replace '?' by '0' and recurse
		str[index] = '0';
		print(str, index + 1);

		// replace '?' by '1' and recurse
		str[index] = '1';
		print(str, index + 1);

		// No need to backtrack as string is passed
		// by value to the function
	}
	else
		print(str, index + 1);
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		print(s, 0);

	}
	return 0;


}
