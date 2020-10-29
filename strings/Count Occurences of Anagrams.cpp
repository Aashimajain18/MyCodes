Count Occurences of Anagrams.cpp
/*
Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
Your Task:
Complete the function search() which takes two strings pat, txt, as input parameters and returns an integer denoting the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256)

Constraints:
1 <= |pat| <= |txt| <= 105
Both string contains lowercase english letters.


*/
int find_occ(string s, string ana) {
	int n = s.length();
	vector<string>v;
	int k = ana.length();
	//cout<<k<<endl;
	for (int i = 0; i < n - k + 1; i++) {
		string s1 = "";
		int x = 0;
		while (x != k) {
			s1 = s1 + s[i + x];
			x++;
		}
		v.push_back(s1);
	}
	sort(ana.begin(), ana.end());
	map<string, int>m;
	for (int i = 0; i < v.size(); i++) {
		string s;
		s = v[i];
		sort(s.begin(), s.end());
		m[s]++;
	}
	int val ;
	bool flag = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->first == ana) {
			val = it->second;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		val = 0;
	return val;
}
int main() {
	//code
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		string ana;
		cin >> ana;
		int ans  = find_occ(s, ana);
		cout << ans << endl;
	}

	return 0;
}