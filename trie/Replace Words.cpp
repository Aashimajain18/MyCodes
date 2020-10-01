
/*
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.



Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
Example 3:

Input: dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
Output: "a a a a a a a a bbb baba a"
Example 4:

Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 5:

Input: dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is accepted"
Output: "it is ab that this solution is ac"


Constraints:

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 10^6
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Each two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.
*/
//M-1
class TrieNode {
public:
	vector<TrieNode*> children;
	bool is_word;
	TrieNode() {
		children = vector<TrieNode*> (26, NULL);
		is_word = false;
	}
};
class Trie {
public:
	TrieNode* root;
	Trie() {
		root = new TrieNode();
	}
	void add(string word) {
		TrieNode* t = root;
		for (auto ch : word) {
			if (t->children[ch - 'a'] == NULL) {
				t->children[ch - 'a'] = new TrieNode();
			}
			t = t->children[ch - 'a'];
		}
		t->is_word = true;
		return;
	}

	string findPrefix(string word) {
		string res = "", curr = "";
		TrieNode* t = root;
		for (auto ch : word) {

			if (t->children[ch - 'a'] == NULL || t->is_word) {
				if (t->is_word) res = curr;
				return (res == "") ? word : res;
			}
			t = t->children[ch - 'a'];
			curr += ch;
		}
		return (res == "") ? word : res;
	}
};
class Solution {
public:
	vector<string> split(string s) {
		vector<string> words;
		string tmp = "";
		for (auto ch : s) {
			if (ch == ' ') {
				words.push_back(tmp);
				tmp = "";
			}
			else {
				tmp += ch;
			}
		}
		if (tmp != "") {
			words.push_back(tmp);
		}
		return words;
	}
	string replaceWords(vector<string>& dict, string sentence) {
		Trie* trie = new Trie();
		for (auto word : dict) {
			trie->add(word);
		}
		string res = "";
		vector<string> words = split(sentence);
		for (auto word : words) {
			if (res == "") res = trie->findPrefix(word);
			else res = res + " " + trie->findPrefix(word);
		}
		return res;
	}
};

//M-2
/*Intuition

For each word in the sentence, we'll look at successive prefixes and see if we saw them before.

Algorithm

Store all the roots in a Set structure. Then for each word, look at successive prefixes of that word. If you find a prefix that is a root, replace the word with that prefix. Otherwise, the prefix will just be the word itself, and we should add that to the final sentence answer.


*/


