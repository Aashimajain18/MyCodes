/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false


Constraints:

s consists only of printable ASCII characters.*/

class Solution {
public:
	bool isPalindrome(string s2) {

		int s = 0;
		int e = s2.length() - 1;

		while (s <= e) {
			if (isalnum(s2[s]) == false) {
				s++;
			}
			else if (isalnum(s2[e]) == false) {
				e--;
			}
			else {
				if (tolower(s2[s]) != tolower(s2[e])) {
					return false;
				}
				s++;
				e--;
			}
		}
		return true;
	}
};