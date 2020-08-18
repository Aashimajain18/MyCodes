/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		int index = 0;
		while (index < intervals.size() && intervals[index].end < newInterval.start) {
			res.push_back(intervals[index++]);
		}
		while (index < intervals.size() && intervals[index].start <= newInterval.end) {
			newInterval.start = min(newInterval.start, intervals[index].start);
			newInterval.end = max(newInterval.end, intervals[index].end);
			index++;
		}
		res.push_back(newInterval);
		while (index < intervals.size()) {
			res.push_back(intervals[index++]);
		}
		return res;
	}
};