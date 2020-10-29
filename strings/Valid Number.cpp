/*Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.
*/

class Solution {
public:
	bool isNumber(string s) {
		int i = 0, digits = 0, dots = 0;
		// go over leading spaces
		while (i < s.size() and s[i] == ' ') {
			i++;
		}

		// check for sign
		if (s[i] == '+' or s[i] == '-') {
			i++;
		}
		// count dots and digits
		while (i < s.size() and (isdigit(s[i]) or s[i] == '.')) {
			s[i++] == '.' ? dots++ : digits++;
		}

		// return false if no digits or more than 1 dot
		if (!digits or dots > 1) {
			return false;
		}

		// check for exponential character
		if (s[i] == 'e') {
			i++;
			//check for sign here
			if (s[i] == '+' or s[i] == '-') {
				i++;
			}
			// count only digits this time
			digits = 0;
			while (i < s.size() and isdigit(s[i])) {
				digits++;
				i++;
			}
			if (!digits) {
				return false;
			}
		}
		// go over trailing spaces
		while (i < s.size() and s[i] == ' ') {
			i++;
		}
		return i == s.size();
	}
};
