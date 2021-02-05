/*https://www.hackerrank.com/challenges/coin-change/problem*/

long count(int n, vector<long> c) {
	// If n is 0 then there is 1 solution
	// (do not include any coin)
	long int m = c.size();
	long int i, j, x, y;

	// We need n+1 rows as the table
	// is constructed in bottom up
	// manner using the base case 0
	// value case (n = 0)
	long int table[n + 1][m];

	// Fill the enteries for 0
	// value case (n = 0)
	for (i = 0; i < m; i++)
		table[0][i] = 1;

	// Fill rest of the table entries
	// in bottom up manner
	for (i = 1; i < n + 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			// Count of solutions including S[j]
			x = (i - c[j] >= 0) ? table[i - c[j]][j] : 0;

			// Count of solutions excluding S[j]
			y = (j >= 1) ? table[i][j - 1] : 0;

			// total count
			table[i][j] = x + y;
		}
	}
	return table[n][m - 1];
}
long getWays(int n, vector<long> c) {
	return count(n, c);
}