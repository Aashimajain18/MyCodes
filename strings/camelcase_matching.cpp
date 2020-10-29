/*
A query word matches a given pattern if we can insert lowercase letters to the pattern word
so that it equals the query. (We may insert each character at any position, and may insert 0 characters.)

Given a list of queries, and a pattern, return an answer list of booleans, where answer[i]
is true if and only if queries[i] matches the pattern.



Example 1:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation:
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
Example 2:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation:
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
Example 3:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation:
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".


Note:

1 <= queries.length <= 100
1 <= queries[i].length <= 100
1 <= pattern.length <= 100
All strings consists only of lower and upper case English letters.

*/


//M-1
//DONE BY ME
class Solution {
public:
	bool present(string word, string pattern) {
		int idx = 0;
		int cnt = 0;
		int letter_present = 0;
		for (int i = 0; i < pattern.size(); i++) {
			for (int j = idx; j < word.size(); j++) {
				if (pattern[i] == word[j]) {
					cnt++;
					idx = j + 1;
					letter_present++;
					break;
				}
			}
			if (letter_present == 0) { //not present
				return false;
			}
			else {
				letter_present = 0;
			}
		}
		if (cnt = pattern.size()) {
			return true;
		}
		return false;
	}

	bool higher_uc_letters(string word, int cnt) {
		int w_cnt = 0;
		for (int i = 0; i < word.size(); i++) {
			if (word[i] >= 'A' and word[i] <= 'Z') {
				w_cnt++;
			}
		}
		if (w_cnt == cnt) {
			return true;
		}
		return false;
	}

	vector<bool> camelMatch(vector<string>& queries, string pattern) {
		vector<bool> ans;
		int cnt = 0;
		for (int i = 0; i < pattern.size(); i++) {
			if (pattern[i] >= 'A' and pattern[i] <= 'Z') {
				cnt++;
			}
		}
		for (int i = 0; i < queries.size(); i++) {
			if (present(queries[i], pattern) and higher_uc_letters(queries[i], cnt)) {
				ans.push_back(true);
			}
			else {
				ans.push_back(false);
			}
		}
		return ans;
	}
};

//M-2
class Solution {
public:
	vector<bool> camelMatch(vector<string>& queries, string pattern) {
		vector<bool> ans;
		for (auto& query : queries) {
			ans.push_back(camelMatch(query, pattern));
		}
		return ans;
	}

	bool camelMatch(const string& query, string pattern) {
		const int M = query.size(), N = pattern.size();
		int j = 0;
		for (int i = 0; i < M; i++) {
			if (j < N && query[i] == pattern[j]) {
				j++;
			} else if (isupper(query[i])) {
				return false; // query中的大写字母必须马上匹配
			}
		}
		return j == N;
	}
};