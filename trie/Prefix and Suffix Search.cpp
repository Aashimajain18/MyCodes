/*
Design a special dictionary which has some words and allows you to search the words in it by a prefix and a suffix.

Implement the WordFilter class:

WordFilter(string[] words) Initializes the object with the words in the dictionary.
f(string prefix, string suffix) Returns the index of the word in the dictionary which has the prefix prefix and the suffix suffix. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.
 

Example 1:

Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]

Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = 'e".
 

Constraints:

1 <= words.length <= 15000
1 <= words[i].length <= 10
1 <= prefix.length, suffix.length <= 10
words[i], prefix and suffix consist of lower-case English letters only.
At most 15000 calls will be made to the function f.
*/


//Method-1
//below method doesn't use trie , it uses hashmaps
// It is an approach of doing this question basically we have vector of strings firstly we are selecting one by one string in for(int i =0 ; i<n;i++) loop , 
// In next step we are making all possible prefixes and suffix of each string in vector nd pushing all combinations into hashMap and key as index . 
// In second function we are just check if the suffix and prefix we stored is present or not if yes then we will return that index

class WordFilter {
   private:
    unordered_map<string, int> hashMap;

   public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string word = words[i];
            int wordSize = word.size();
            for (int j = 1; j <= wordSize; j++) {
                string p = word.substr(0, j);
                for (int k = 0; k < wordSize; k++) {
                    string s = word.substr(k, wordSize);
                    hashMap[p + "|" + s] = i + 1;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string s = prefix + "|" + suffix;
        return hashMap[s] - 1;
    }
};


//Method-2
//Trie
/*
Intuition and Algorithm

Consider the word 'apple'. For each suffix of the word, we could insert that suffix, followed by '#', followed by the word, all into the trie.

For example, we will insert '#apple', 'e#apple', 'le#apple', 'ple#apple', 'pple#apple', 'apple#apple' into the trie. 
Then for a query like prefix = "ap", suffix = "le", we can find it by querying our trie for le#ap.

Complexity Analysis

Time Complexity: O(NK^2 + QK) where N is the number of words, K is the maximum length of a word, and Q is the number of queries.

Space Complexity: O(NK^2), the size of the trie.


*/
template<class T>
class Trie{
    map<T, Trie> tries;
    int weight;
    
    public:
    
    template<class It>
    void addWord(It first, It second, int weight){
        if(first == second)
            return;
        
        tries[*first].weight=weight;    // inserting weight to all prefix
        tries[*first].addWord(next(first), second, weight);
    }
    
    template<class It>
    int search(It first, It second){
        if(first == second)
            return weight;
        if(tries.find(*first) != tries.end()){
            return tries[*first].search(next(first), second);
        }
        
        return -1;
        
    }
};

class WordFilter {
    Trie<char> trie;
public:
    WordFilter(vector<string>& words) {
        for(int i=0; i< words.size(); i++){
            // inserting {apple , e{apple
            string prefix = words[i];
            for(int l=0; l<= prefix.length(); l++){
                string suffix = prefix.substr(prefix.length()-l, l);
                string new_word = suffix + "#" + prefix;
                //cout<<"adding word "<<new_word<<endl;
                trie.addWord(begin(new_word), end(new_word),i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string new_word = suffix + "#" + prefix;
        return trie.search(begin(new_word), end(new_word));
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
