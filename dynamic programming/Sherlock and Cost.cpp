
// https://www.hackerrank.com/challenges/sherlock-and-cost/problem

// Complete the cost function below.
int cost(vector<int> b) {
	int dp[100005][2];
	int n = b.size();
	int i;
	for (i = 0; i < n - 1; i++)
	{
		dp[i + 1][0] = max(dp[i][0], dp[i][1] + abs(b[i] - 1));
		dp[i + 1][1] = max(dp[i][0] + abs(b[i + 1] - 1), dp[i][1] + abs(b[i] - b[i + 1]));
	}
	return max(dp[n - 1][0], dp[n - 1][1]);

}