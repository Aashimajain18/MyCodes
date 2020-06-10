/*
Take as input str, a string. We are concerned with all the possible subsequences of str. E.g.

a. Write a recursive function which returns the count of subsequences for a given string. Print the value returned.

b. Write a recursive function which prints all possible subsequences for a “abcd” has following subsequences “”, “d”, “c”, “cd”, “b”, “bd”, “bc”, “bcd”, “a”, “ad”, “ac”, “acd”, “ab”, “abd”, “abc”, “abcd”.given string (void is the return type for function).
Note: Use cin for input for C++

Input Format
Enter a string

Constraints
None

Output Format
Display the total no. of subsequences and also print all the subsequences in a space separated manner

Sample Input
abcd
Sample Output
 d c cd b bd bc bcd a ad ac acd ab abd abc abcd 
16
Explanation
Print all possible subsequences of the given string.
*/

#include<iostream>
#include<string>
#include<math.h>

using namespace std;

void subseq(char *in,char *out,int i,int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<" ";
        return;
    }
    subseq(in,out,i+1,j);

    
    out[j]=in[i];
    subseq(in,out,i+1,j+1);
    
    
    
}

int main(){
    char in[100];
    cin>>in;
    char out[100];

    subseq(in,out,0,0);
    int x=1;
    while(in[x]!='\0'){
        x++;
    }
    int total=pow(2,x);
    cout<<total;
    }
