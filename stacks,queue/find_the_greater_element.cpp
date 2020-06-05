/*
We are given a circular array, print the next greater number for every element. If it is not found print -1 for that number. To find the next greater number for element Ai , start from index i + 1 and go uptil the last index after which we start looking for the greater number from the starting index of the array since array is circular.

Input Format
First line contains the length of the array n. Second line contains the n space separated integers.

Constraints
1 <= n <= 10^6
-10^8 <= Ai <= 10^8 , 0<= i< n

Output Format
Print n space separated integers each representing the next greater element.

Sample Input
3
1 2 3
Sample Output
2 3 -1
Explanation
Next greater element for 1 is 2,
for 2 is 3 but not present for 3 therefore -1


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
using namespace std;
/*
This approach makes use of a stack. This stack stores the indices of the appropriate elements from
 nums array. The top of the stack refers to the index of the Next Greater Element found so far.
 We store the indices instead of the elements since there could be duplicates in the nums array.
 The description of the method will make the above statement clearer.

We start traversing the numsnums array from right towards the left. For an element nums[i]
encountered, we pop all the elements stack[top] from the stack such that nums[stack[top]] ≤ nums[i].
We continue the popping till we encounter a stack[top] satisfying nums[stack[top]]>nums[i].
Now, it is obvious that the current stack[top] only can act as the Next Greater Element for
nums[i](right now, considering only the elements lying to the right of nums[i]).

If no element remains on the top of the stack, it means no larger element than nums[i] exists to
its right. Along with this, we also push the index of the element just encountered(nums[i]), i.e. ii
over the top of the stack, so thatnums[i](or stack[topstack[top) now acts as the Next Greater
Element for the elements lying to its left.

We go through two such passes over the complete nums array. This is done so as to complete a
circular traversal over the nums array. The first pass could make some wrong entries in the
res array since it considers only the elements lying to the right of nums[i], without a circular
traversal. But, these entries are corrected in the second pass.


*/
vector<int> nextGreaterElements(vector<int> &nums)
{
	int n = nums.size();
	vector<int> res(n);

	stack<int> s;

	for (int i = 2 * n - 1; i >= 0; i--)
	{

		while (!s.empty() && nums[s.top()] <= nums[i % n])
		{
			s.pop();
		}

		res[i % n] = (s.empty() ? -1 : nums[s.top()]);
		s.push(i % n);
	}

	return res;
}



int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> A(n);
	for ( int i = 0; i < n; i++) {
		cin >> A[i];
	}
	vector<int> ans = nextGreaterElements(A);
	for ( int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}


