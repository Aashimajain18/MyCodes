/*Problem Description

GIven three prime numbers A, B and C and an integer D.

You need to find the first(smallest) D integers which only have A, B, C or a combination of them as their prime factors.



Input Format
First argument is an integer A.

Second argument is an integer B.

Third argument is an integer C.

Fourth argument is an integer D.



Output Format
Return an array of size D denoting the first smallest D integers which only have A, B, C or a combination of them as their prime factors.

NOTE: You need to return the array sorted in ascending order.



Example Input
Input 1:

 A = 2
 B = 3
 C = 5
 D = 5


Example Output
Output 1:

 [2, 3, 4, 5, 6]


Example Explanation
Explanation 1:

 4 = A * A i.e ( 2 * 2 )
 6 = A * B i.e ( 2 * 3 )
*/

vector<int> Solution::solve(int A, int B, int C, int D) {
	vector<int> op;
	op.push_back(1);
	int x, i = 0, j = 0, k = 0;
	while (D--) {
		x = min(op[i] * A, min(op[j] * B, op[k] * C));
		if (x == op[i]*A) {
			i++;
		}
		if (x == op[j]*B) {
			j++;
		}
		if (x == op[k]*C) {
			k++;
		}
		op.push_back(x);

	}
	op.erase(op.begin());
	return op;
}

/*It turns out we can.
We use the fact that there are only 3 possibilities of getting to a new number : Multiply by A or B or C.

For each of A, B and C, we maintain the minimum number in our set which has not been multiplied with the corresponding prime number yet.
So, at a time we will have 3 numbers to compare.*/