/*
Given two strings s1 and s2, return true if s2 contains the permutation of s1.

In other words, one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.

*/

//my solution

class Solution {
public:
    
    bool twoArrEqual(int arr1[], int arr2[]) 
{ 
   
  
    // Linearly compare elements 
    for (int i = 0;i<26;i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
        }
    // If all elements were same. 
    return true;
}
    
    bool checkInclusion(string s1, string s2) {
         if (s1.length() > s2.length()){
            return false;
         }
        int arr[26]={0};
        int brr[26]={0};
        sort(s1.begin(),s1.end());
        int lens1=s1.length();
        //store freq of letters of s1 in an array and s2 in different array but only till length of s1 and then later we will change frequencies while applying a sliding window
        for(int i=0;i<s1.length();i++){
            brr[s1[i]-'a']++;
            arr[s2[i]-'a']++;
        }
        if(twoArrEqual(arr,brr)){
            return true;
        }
        for(int i=lens1;i<s2.length();i++){
            //sliding window
        arr[s2[i]-'a']++;//add new element freq
            arr[s2[i-lens1]-'a']--;//delete old element
            if(twoArrEqual(arr,brr)){
            return true;
        }
    }
        return false;
    }
};
