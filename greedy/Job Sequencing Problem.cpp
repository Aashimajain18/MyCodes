
/*
Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

Input:
The first line of input contains an integer T denoting the number of test cases. In each test case, first line consists of an integer N denoting the number of jobs. Second line will be of the format A1, B1, C1, A2, B2, C2..... AN, BN, CN, where Ai, Bi and Ci denote the ID, deadline and profit from the ith job respectively.

Output:
Output the number of jobs done and the maximum profit seperated by a space in a different line for each test case.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= Deadline <= 100
1 <= Profit <= 500

Example:
Input:
2
4
1 4 20 2 1 10 3 1 40 4 1 30
5
1 2 100 2 1 19 3 2 27 4 1 25 5 1 15

Output:
2 60
2 127

Explanation:
Test Case 1: You can do job 3 followed by the job 1. The overall profit = 40 + 20 = 60
Test Case 2: You can do job 1 followed by the job 3. The overall profit = 100 + 27 = 127

*/

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

/*This is a standard Greedy Algorithm problem. Following is algorithm.

1) Sort all jobs in decreasing order of profit.
2) Iterate on jobs in decreasing order of profit.For each job , do the following :
a)Find a time slot i, such that slot is empty and i < deadline and i is greatest.Put the job in
this slot and mark this slot filled.
b)If no such i exists, then ignore the job.
*/


// A structure to represent a job
struct Job
{
	char id;      // Job Id
	int dead;    // Deadline of job
	int profit;  // Profit if job is over before or on deadline
};

// This function is used for sorting all jobs according to profit
bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

// Returns minimum number of platforms reqquired
void printJobScheduling(Job arr[], int n)
{
	// Sort all jobs according to decreasing order of prfit
	sort(arr, arr + n, comparison);

	int result[n]; // To store result (Sequence of jobs)
	bool slot[n];  // To keep track of free time slots

	// Initialize all slots to be free
	for (int i = 0; i < n; i++)
		slot[i] = false;

	// Iterate through all given jobs
	for (int i = 0; i < n; i++)
	{
		// Find a free slot for this job (Note that we start
		// from the last possible slot)
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
		{
			// Free slot found
			if (slot[j] == false)
			{
				result[j] = i;  // Add this job to result
				slot[j] = true; // Make this slot occupied
				break;
			}
		}
	}

	// Print the result
	for (int i = 0; i < n; i++)
		if (slot[i])
			cout << arr[result[i]].id << " ";
}

// Driver program to test methods
int main()
{
	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
		{'d', 1, 25}, {'e', 3, 15}
	};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobsn";
	printJobScheduling(arr, n);
	return 0;
}


