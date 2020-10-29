/*
https://leetcode.com/problems/champagne-tower/
*/

class Solution {
public:
	double champagneTower(int poured, int query_row, int query_glass) {
		//keep track of flow over each glass
		double arr[102][102] = {0};
		arr[0][0] = double(poured);
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				double q = (arr[i][j] - 1) / 2;
				if (q > 0) {
					arr[i + 1][j] += q;
					arr[i + 1][j + 1] += q;
				}
			}
		}
		return min(1.0, arr[query_row][query_glass]);

	}
};
