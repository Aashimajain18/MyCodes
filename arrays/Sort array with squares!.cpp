/*
Given a sorted array A containing N integers both positive and negative.

You need to create another array containing the squares of all the elements in A and return it in non-decreasing order.

Try to this in O(N) time.


Problem Constraints
1 <= N <= 105.

-103 <= A[i] <= 103



Input Format
First and only argument is an integer array A.



Output Format
Return a integer array as described in the problem above.



Example Input
Input 1:

 A = [-6, -3, -1, 2, 4, 5]
Input 2:

 A = [-5, -4, -2, 0, 1]


Example Output
Output 1:

 [1, 4, 9, 16, 25, 36]
Output 2:

 [0, 1, 4, 16, 25]


*/

//M-1(DONE BY ME)
// TC=O(NLOG(N))
vector<int> Solution::solve(vector<int> &A) {
	vector<int> ans;
	for (int i = 0; i < A.size(); i++) {
		ans.push_back(A[i]*A[i]);
	}
	sort(ans.begin(), ans.end());
	return ans;
}

//M-2
//TC-O(N)
vector<int> Solution::solve(vector<int> &A) {
	int s = 0, e = A.size() - 1;
	vector<int> res;
	while (s <= e) {
		if (s == e) { res.push_back(A[s]*A[s]); break;}
		if (abs(A[s]) > abs(A[e])) {
			res.push_back(A[s]*A[s]);
			s++;
		}
		else if (abs(A[s]) < abs(A[e])) {
			res.push_back(A[e]*A[e]);
			e--;
		}
		else {
			res.push_back(A[s]*A[s]);
			s++;
			res.push_back(A[e]*A[e]);
			e--;
		}
	}

	reverse(res.begin(), res.end());
	return res;
}





