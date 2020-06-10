/*
Take as input S, a string. Write a function that removes all consecutive duplicates. Print the value returned.

Input Format
String

Constraints
A string of length between 1 to 1000

Output Format
String

Sample Input
aabccba
Sample Output
abcba
Explanation
For the given example, "aabccba", Consecutive Occurrence of a is 2, b is 1, and c is 2.

After removing all of the consecutive occurences, the Final ans will be : - "abcba".
*/

#include<iostream>
#include<string>
using namespace std;

void removeDuplicates(string s,int i){
    int len=s.size();
    if(i==len){
        return;
    }
  
    if(s[i]==s[i-1]){
        i=i+1;

    }
    else{
          cout<<s[i-1];
        i++;
    }
    removeDuplicates(s, i);

}


int main(){
    string s;
    cin>>s;
        removeDuplicates(s,1);
    int l=s.size();
    if(s[l-2]!=s[l-1]){
        cout<<s[l-1];
    }
    else{
        cout<<s[l-2];
    }
}
