/*
Replace all occurrences of pi with 3.14

Input Format
Integer N, no of lines with one string per line

Constraints
0 < N < 1000
0 <= len(str) < 1000

Output Format
Output result one per line

Sample Input
3
xpix
xabpixx3.15x
xpipippixx
Sample Output
x3.14x
xab3.14xx3.15x
x3.143.14p3.14xx
Explanation
All occurrences of pi have been replaced with "3.14".
*/

#include<iostream>
#include<string>
using namespace std;

void replacepi(string s,int i){
    int len=s.size();
    if(i==len){
        return;
    }
  
    if(s[i]=='p'){
        if(s[i+1]=='i'){
            cout<<"3.14";
            i=i+2;
        }
        else{
            cout<<"p";
            i++;
        }
    }
    else{
        cout<<s[i];
        i++;

    }
    replacepi(s, i);

}


int main(){
    int t;
    cin>>t;
    while(t--){
    string s;
    cin>>s;
        replacepi(s,0);
        cout<<endl;
        }
}
