/*
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts.
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245.
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different.

Output : 1

*/
#define ll long long
int Solution::colorful(int A) {
	unordered_map<ll, ll> mp;
	string s = to_string(A);
	int n = s.size();
	for (int x = 0; x < n; x++)
	{
		ll p = 1;

		for (int y = x; y < n; y++)
		{
			ll a = s[y] - '0';
			p = p * a;
			if (mp.find(p) != mp.end())
				return 0;

			else
				mp[p]++;
		}
	}

	return 1;
}
