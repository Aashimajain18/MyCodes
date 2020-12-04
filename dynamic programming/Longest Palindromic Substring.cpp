/*
Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/


//hint:-use matrix
//USE DP
//solution link:-
//https://leetcode.com/problems/longest-palindromic-substring/discuss/147548/Direct-c%2B%2B-DP
//Menthod-1:-(TC-O(N^2))
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() == 0) return "";
		int i = 0, j = 0;
		int n = s.size();
		//initialize P[n][n], we only need half of P, and initialize it like: (e.g. : s="abbc")
		bool P[n][n] = {false};
		for (int x = 0; x < n; x++) {
			P[x][x] = true;
			if (x == n - 1) break;
			P[x][x + 1] = (s[x] == s[x + 1]);
		}
		//dp
		for (int i = n - 3; i >= 0; --i) {
			for (int j = i + 2; j < n; ++j) {
				P[i][j] = (P[i + 1][j - 1] && s[i] == s[j]);
			}
		}
		//get maxstr result
		int max = 0;
		string maxstr = "";
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (P[i][j] == true and j - i + 1 > max) {
					max = j - i + 1;
					maxstr = s.substr(i, j - i + 1);
				}
			}
		}
		return maxstr;
	}
};

//Menthod-2:-(TC-O(N^3))
class Solution {
public:
	bool check_palindrome(string str) {
		int end = str.size() - 1;
		for (int i = 0; i < (str.length() / 2); i++) {
			if (str[i] != str[end - i]) {
				return false;
			}
		}
		return true;
	}


	string longestPalindrome(string s) {
		int maximum = 0;
		int curr = 0;
		int ii = 0, jj = 0;
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < s.length(); j++) {
				string str = s.substr(i, j - i + 1);
				if (check_palindrome(str)) {
					curr = j - i + 1;
					if (curr > maximum) {
						maximum = curr;
						ii = i;
						jj = j;
					}
				}
			}
		}
		return s.substr(ii, jj - ii + 1);
	}
};

