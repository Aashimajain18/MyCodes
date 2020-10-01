/*
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?

Input Format:

    First and only argument of input contains an integer array A
Output Format:

    return a single integer.
Constraints:

2 <= N <= 5 000 000
0 <= A[i] <= INT_MAX
For Examples :

Example Input 1:
    A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Example Output 1:
    4
Explanation:
    4 occur exactly once
Example Input 2:
    A = [0, 0, 0, 1]
Example Output 2:
    1

*/


int Solution::singleNumber(const vector<int> &A) {
	vector<long> vec(32, 0);
	long temp = 0;
	for (int i = 0; i < 31; i++) {
		for (auto it : A)
			vec[i] += it & (1 << i);
		if (vec[i] % 3)
			temp += 1 << i;
	}
	return temp;
	/*The left-shift by 1 and right-shift by 1 are equivalent to the product of first
	term and 2 to the power given element(1<<3 = 1*pow(2,3)) and division of first term
	and second term raised to power 2 (1>>3 = 1/pow(2,3)) respectively.*/
}

/*So, in the question, If you think only about the repeating numbers in binary, then you’ll notice, that for every bit position, you’ll have 3x 1s and 3y 0s. That’s because every number occurs thrice. Take an example. For {2, 2, 2, 3, 3, 3}, the binary representations are {10, 10, 10, 11, 11, 11}.

If you take a sum according to bit positions, 3 0s are contributed to the sum by 2 and 3 1s are contributed to the sum by 3 at the 0th position, making the sum of the bits at 0th position “3”. For the 1th position, 3 1s are contributed to the sum by 2, and 3 1s are contributed to the sum by 3 at the 0th position, making the sum of the bits at 1th position “6”. Notice that this sum always remains a multiple of 3, when we are considering numbers which occur thrice.

Now if we also consider the number which occurs once, it adds its own 1s and 0s to some of these above positions. But if you think about it, if there is a position where 1 occurs for this number, then the sum of 1s for that number will become 3x + 1(Since this number comes only once). Similarly, the positions where 0 occurs, makes the number of 0s to be 3y+1.*/