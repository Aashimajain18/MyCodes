/*Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.



Constraints:

intervals[i][0] <= intervals[i][1]*/
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& a) {
		vector<vector<int>> ans;
		// no intervals are given then return empty ans
		if (a.size() == 0)
			return ans;
		// this is important step
		sort(a.begin(), a.end());

		//initialize start and end into s and e
		int s = a[0][0], e = a[0][1];

		//update end only if interval starts before end of current iterval
		for (int i = 1; i < a.size(); i++)
		{
			//choose greedily maximum ending
			if (a[i][0] <= e)
				e = max(a[i][1], e);
			else
			{
				ans.push_back({s, e});

				//update s and e with current interval
				s = a[i][0];
				e = a[i][1];
			}
		}

		//this adds last interval
		ans.push_back({s, e});
		return ans;
	}
};