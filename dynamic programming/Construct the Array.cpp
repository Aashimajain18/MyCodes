// https://www.hackerrank.com/challenges/construct-the-array/problem

//hint
/*
First realize that 1...1 is different from 1...(2-k), but 1...2, 1...3, ..., 1...k are all equvilant. So there are two functions f and g.

Second, 1...(n-2 dots)...x, x==1 has the pattern: 1...(n-3 dots)...y1, where y!=1. There are (k-1) such cases, i.e. 1...(n-3 dots)...y with y loops over 2 to k. So the relation: g(n) = (k-1) * f(n-1)

Third, 1...(n-2 dots)...x, x!=1 has two possible patterns: 1...(n-3 dots)...1x and 1...(n-3 dots)...yx, y!=x or 1. The first pattern gives g(n-1), the second gives (k-2)*f(n-1), since y can loop over 2 to k but not x.

f(n): ways of construct length of n, x!=1
g(n): ways of construct length of n, x==1
then, we have:
f(n) = g(n-1) + (k-2) * f(n-1)
g(n) = (k-1) * f(n-1)
*/

long countArray(int n, int k, int x) {
	vector<long> f(n + 1, 0);
	vector<long> g(n + 1, 0);
	f[2] = 1;
	g[2] = 0;
	for (int i = 3; i <= n; i++) {
		f[i] = g[i - 1] + (k - 2) * f[i - 1];
		g[i] = (k - 1) * f[i - 1];
		f[i] %= long(1e9 + 7);
		g[i] %= long(1e9 + 7);
	}
	return x == 1 ? g[n] : f[n];
}