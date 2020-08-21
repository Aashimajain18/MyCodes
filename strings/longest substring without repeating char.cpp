/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s == "") {
			return 0;
		}
		int a[256];
		int max_len = 1;
		int cur_len = 1;
		for (int i = 0; i < 256; i++) {
			a[i] = -1;
		}

		a[s[0]] = 0;
		for (int i = 1; i < s.size(); i++) {
			int last_occ = a[s[i]];
			//expansion
			if (last_occ == -1 || i - cur_len > last_occ) {
				cur_len++;
				max_len = max(cur_len, max_len);
			}
			else {
				if (cur_len > max_len) {
					max_len = cur_len;
				}
				cur_len = i - last_occ;
			}
			a[s[i]] = i;
		}
		return max_len;
	}
};