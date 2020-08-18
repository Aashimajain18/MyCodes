/*
You are given a running data stream of n integers. You read all integers from that running data stream and find effective median of elements read so far in efficient way. All numbers are unique in the datastream. Print only the integer part of the median.

Input Format
First line contains integer t as number of test cases. Each test case contains following input. First line contains integer n which represents the length of the data stream and next line contains n space separated integers.

Constraints
1 < t < 100
1< n < 10000

Output Format
Print the effective median of running data stream..

Sample Input
1
6
5 15 1 3 2 8
Sample Output
5 10 5 4 3 4
Explanation
Iteration 1 :
Array = {5}
Median = 5

Iteration 2 :
Array = {5,15}
Median = (5+15)/2 = 10

Iteration 3 :
Array = {1,5,15}
Median = 5

Iteration 4 :
Array = {1,3,5,15}
Median = (3+5)/2 = 4

Iteration 5 :
Array = {1,2,3,5,15}
Median = 3

Iteration 6 :
Array = {1,2,3,5,8,15}
Median = (3+5)/2 = 4
*/
//input format below is different because of video solution
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue> //priority queue
#include<map>
using namespace std;


int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	priority_queue<int> leftheap;
	priority_queue<int, vector<int> , greater<int> > rightheap;

	int d;
	cin >> d;
	leftheap.push(d);
	float med = d;
	cout << med << " ";

	cin >> d;


	while (d != -1) {
		if (leftheap.size() > rightheap.size()) {
			if (d < med) {
				rightheap.push(leftheap.top());
				leftheap.pop();
				leftheap.push(d);
			}
			else {
				rightheap.push(d);
			}
			med = (leftheap.top() + rightheap.top()) / 2.0;
		}
		else if (leftheap.size() == rightheap.size()) {
			if (d < med) {
				leftheap.push(d);
				med = leftheap.top();
			}
			else {
				rightheap.push(d);
				med = rightheap.top();
			}
		}
		else {
			if (d > med) {
				leftheap.push(rightheap.top());
				rightheap.pop();
				rightheap.push(d);
			}
			else {
				leftheap.push(d);
			}
			med = (leftheap.top() + rightheap.top()) / 2.0;

		}




		cout << med << " ";
		cin >> d;

	}

	return 0;


}



