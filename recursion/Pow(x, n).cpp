/*Implement pow(x, n), which calculates x raised to the power n (i.e. xn).



Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25


Constraints:

-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
-10^4 <= xn <= 10^4
*/
//Below solution divides the problem into subproblems of size y/2 and call the subproblems recursively.
class Solution {
public:
	// time complexity= O(logN) because power is getting divided by 2 everytime
	double myPow(double x, int y) {
		double temp;
		if ( y == 0) {
			return 1;
		}
		if (y > 0) {

			temp = myPow(x, y / 2);
			if (y % 2 == 0) {
				return temp * temp;
			}
			else {
				return x * temp * temp;
			}
		}
		//negative power
		else {
			bool edgecase = false;
			if (y == INT_MIN) {
				edgecase = true;
				y = INT_MAX;
			}
			else {
				y = -y;//change sign
			}
			temp = (1 / myPow(x, y / 2));
			if (y % 2 == 0) {
				if (edgecase) {
					return (1 / x) * (temp * temp);
				}
				return temp * temp;
			}
			else {
				if (edgecase) {
					return (1 / x) * (1 / x) * (temp * temp);
				}
				return (1 / x) * (temp * temp);
			}
		}
	}
};