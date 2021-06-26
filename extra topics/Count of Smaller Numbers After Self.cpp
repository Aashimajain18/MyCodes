/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i]
is the number of smaller elements to the right of nums[i].

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]


Constraints:

1 <= nums.length <= 10^5
-104 <= nums[i] <= 10^4

*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n, 0); omset<int> s;
		for (int i = n - 1; i >= 0; i--) {
			ans[i] = s.order_of_key(nums[i]);
			s.insert(nums[i]);
		}
		return ans;
	}
};


/*
Description of algo: An ordered set is a policy based structure in the gcc library (in c++). You can learn more about it here:
https://codeforces.com/blog/entry/11080. I modified the structure to allow multiset operations (oset is an ordered set,
omset is an ordered multiset). An ordered set allows you to do the normal bst operations, as well as calculate the number of
elements less than a certain value, which is exactly what we need here. This is a direct implementation of that structure.

*/