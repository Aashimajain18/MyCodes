/*Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

class Solution {
public:
	bool isPalindrome(int x) {
		int initial_num = x;
		if (x < 0) {
			return false;
		}
		int num = 0;
		while (x > 0) {
			int val = x % 10;
			if (num > INT_MAX / 10 || (num == INT_MAX / 10 && val > 7)) {//to check overflow refer leetcode atoi problem to understand this step
				return false;
			}
			num = num * 10 + val;
			x = x / 10;
		}
		if (num != initial_num) {
			return false;
		}
		return true;
	}
};