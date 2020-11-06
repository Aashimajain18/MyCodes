/*You are given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.



Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1*/

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		int l = 0, r = nums.size() - 1, m = 0;
		// find out the index of the smallest element.
		while (l < r) {
			m = (l + r) / 2;
			if (nums[m] > nums[r]) {
				l = m + 1;
			} else {
				r = m;
			}
		}

		// since we now know the start, find out if the target is to left or right of start in the array.
		int s = l;
		l = 0; r = nums.size() - 1;
		if (target >= nums[s] && target <= nums[r]) {
			l = s;
		} else {
			r = s;
		}
		// the regular search.
		while (l <= r) {
			m = (l + r) / 2;
			if (nums[m] == target) return m;
			else if (nums[m] > target) r = m - 1;
			else l = m + 1;
		}
		return -1;
	}
};