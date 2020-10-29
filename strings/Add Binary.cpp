/*Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.*/

class Solution {
public:
	string addBinary(string a, string b) {
		// extract the lengths of the strings and get which is shorter
		int alen = a.size();
		int blen = b.size();
		int longer = max(alen, blen);
		int shorter = min(alen, blen);
		string longst = (alen > blen) ? a : b;
		string shortst = (alen > blen) ? b : a;

		// zero pad the shorter string to be same length as longer
		shortst = string(longer - shorter, '0').append(shortst);

		int carry = 0;
		string result = "";
		// do the summation over each bit
		for (int i = longer - 1; i >= 0; i--) {
			int sum = longst[i] - '0' + shortst[i] - '0' + carry;
			if (sum > 1) {
				sum = sum % 2;
				carry = 1; // carry case
			} else {
				carry = 0;
			}
			result.insert(0, to_string(sum));


		}
		if (carry) { // if need one overflow bit
			result.insert(0, "1");
		}

		return result;
	}
};