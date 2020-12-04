/*Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false*/

class Solution {
public:
	/*
	We use a boolean vector dp[]. dp[i] is set to true if a valid word (word sequence) ends there.
	The optimization is to look from current position i back and only substring and do dictionary look
	up in case the preceding position j with dp[j] == true is found.
	*/
	bool ans_word_break(string s, unordered_set<string>& dict) {
		if (dict.size() == 0) return false;

		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;

		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (dp[j])
				{
					string word = s.substr(j, i - j);
					if (dict.find(word) != dict.end())
					{
						dp[i] = true;
						break; //next i
					}
				}
			}
		}

		return dp[s.size()];
	}
	bool wordBreak(string s, vector<string>& word_dict) {
		unordered_set<string> dict;
		for (int i = 0; i < word_dict.size(); i++) {
			dict.insert(word_dict[i]);
		}

		return ans_word_break(s, dict);

	}
};