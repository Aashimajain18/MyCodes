/*Problem Description

Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:

A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.



Problem Constraints
1 <= N <= 10

0 <= A[i][0] < A[i][1] <= 2 * 109



Input Format
The only argument given is the matrix A.



Output Format
Return the minimum number of conference rooms required so that all meetings can be done.



Example Input
Input 1:

 A = [      [0, 30]
            [5, 10]
            [15, 20]
     ]

Input 2:

 A =  [     [1, 18]
            [18, 23]
            [15, 29]
            [4, 15]
            [2, 11]
            [5, 13]
      ]


Example Output
Output 1:

 2
Output 2:

 4


Example Explanation
Explanation 1:

 Meeting one can be done in conference room 1 form 0 - 30.
 Meeting two can be done in conference room 2 form 5 - 10.
 Meeting one can be done in conference room 2 form 15 - 20 as it is free in this interval.
Explanation 2:

 Meeting one can be done in conference room 1 from 1 - 18.
 Meeting five can be done in conference room 2 from 2 - 11.
 Meeting four can be done in conference room 3 from 4 - 15.
 Meeting six can be done in conference room 4 from 5 - 13.
 Meeting three can be done in conference room 2 from 15 - 29 as it is free in this interval.
 Meeting two can be done in conference room 4 from 18 - 23 as it is free in this interval.


*/

//solution 2
int Solution::solve(vector<vector<int> > &A) {
	int n = A.size();
	vector<int>arr(n, 0);
	vector<int>dep(n, 0);
	for (int i = 0; i < n; i++) {
		arr[i] = A[i][0];
		dep[i] = A[i][1];
	}
	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());
	int rooms = 0;
	int i = 0 , j = 0;
	int ans = INT_MIN;
	while (i < n and j < n) {
		if (arr[i] < dep[j]) {
			rooms++;
			i++;
		}
		else {
			j++;
			rooms--;
		}
		ans = max(ans, rooms);
	}
	return ans;
}

/*Solution 1: Use min heap to store the meeting rooms end time. If new meeting start time is greater or equal than least element, update it.
If not, open a new meeting room. Report the min heap size at the end.
Time Complexity : O(NlogN).

Solution 2: Two sorted array of start time and end time. Two pointers to iterator start array and end array. Iterate the time line, the current time active meeting is num of start minus num of end.
Since need sort, still O(nlogn) solution, but fast than solution 1.*/