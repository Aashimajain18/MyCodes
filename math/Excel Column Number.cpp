/*
Problem Description

Given a column title A as appears in an Excel sheet, return its corresponding column number.



Problem Constraints
1 <= |A| <= 100



Input Format
First and only argument is string A.



Output Format
Return an integer


Example input
input 1:

 "A"
intput 2:

 "AB"


Example output
Output 1:

 1
Output 2:

 28


Example Explanation
Explanation 1:

 1 -> "A"
Explanation 2:

A  -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28


*/

int Solution::titleToNumber(string A) {
	int answer = 0;
	for (int i = A.size() - 1; i >= 0; i--)
		answer += pow(26, A.size() - 1 - i) * (A[i] - 'A' + 1);
	return answer;
}

/*
hint: Simple math.

This is just like base 26 number conversion.

number = 26^0 * (S[n - 1] - ‘A’ + 1) + 26^1 * (S[n - 2] - ‘A’ + 1) + ….
*/

