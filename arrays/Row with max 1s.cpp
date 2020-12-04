/*Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input:
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).

Example 2:

Input:
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based
indexing).

Your Task:
You don't need to read input or print anything. Your task is to complete the function rowWithMax1s() which takes the array of booleans arr[][], n and m as input parameters and returns the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.


Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N, M ≤ 10^3
0 ≤ Arr[i][j] ≤ 1

 */

//User function template for C++
class Solution {
public:
	//M-1:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {

		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				if (arr[i][j] == 1) {
					return i;
				}
			}

		}
		return -1;
	}

// 	M-2:
	//Step1: Get the index of first (or leftmost) 1 in the first row.

// Step2: Do following for every row after the first row
// …IF the element on left of previous leftmost 1 is 0, ignore this row.
// …ELSE Move left until a 0 is found. Update the leftmost index to this index and max_row_index to be the current row.

// The time complexity is O(m+n) because we can possibly go as far left as we came ahead in the first step.

};