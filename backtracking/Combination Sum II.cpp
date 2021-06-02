/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]


Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

//my sol
class Solution {
public:

	void findNumbers(vector<int>& ar, int sum,
	                 set<vector<int> >& res, vector<int>& r,
	                 int i)
	{
		// If  current sum becomes negative
		if (sum < 0)
			return;

		// if we get exact answer
		if (sum == 0) {
			res.insert(r);
			return;
		}

		// Recur for all remaining elements that
		// have value smaller than sum.
		while (i < ar.size() && sum - ar[i] >= 0) {

			// Till every element in the array starting
			// from i which can contribute to the sum
			r.push_back(ar[i]); // add them to list

			// recur for next numbers
			findNumbers(ar, sum - ar[i], res, r, i + 1);
			i++;

			// Remove number from list (backtracking)
			r.pop_back();
		}
	}

// Returns all combinations
// of ar[] that have given
// sum.
	vector<vector<int> > combinationSum2(vector<int>& ar,
	                                     int sum)
	{
		// sort input array
		sort(ar.begin(), ar.end());

		// remove duplicates
		//ar.erase(unique(ar.begin(), ar.end()), ar.end());

		vector<int> r;
		set<vector<int> > res;
		findNumbers(ar, sum, res, r, 0);
		vector<vector<int> > final_res;
		for (auto x : res)
		{
			final_res.push_back(x);
		}
		return final_res;
	}
};






//faster sol
class Solution {
	vector<vector<int>> res;
	void dfs(vector<int>& candidates, int start, int target, vector<int>& cur) {
		if (target <= 0) {
			if (target == 0) res.push_back(cur);
			return;
		}
		if (start >= candidates.size()) return;
		for (int i = start; i < candidates.size(); i++) {
			if (i > start && candidates[i] == candidates[i - 1]) continue;
			cur.push_back(candidates[i]);
			dfs(candidates, i + 1, target - candidates[i], cur);
			cur.pop_back();
		}
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> cur;
		dfs(candidates, 0, target, cur);
		return res;
	}
};