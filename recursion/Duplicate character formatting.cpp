/*
Take as input str, a string. Write a recursive function which returns a new string in which all duplicate consecutive characters are separated by a ‘ * ’. E.g. for “hello” return “hel*lo”. Print the value returned

Input Format
Enter a String

Constraints
1<= Length of string <= 10^4

Output Format
Display the resulting string (i.e after inserting (*) b/w all the duplicate characters)

Sample Input
hello
Sample Output
hel*lo
Explanation
We insert a "*" between the two consecutive 'l' .
*/

 #include<iostream>
   #include<vector>
   #include<string>
   #include<algorithm>

   using namespace std;

void strTOnum(string n,int i){
    
    int len=n.size();
    if(i==len){
        return ;
    }
    cout<<n[i-1];

        if(n[i-1]==n[i]){
        cout<<"*";
    }
    
    strTOnum(n,i+1);

}

int main(){
       string n;
       cin>>n;
       strTOnum(n,1);
    int len=n.size();

    for(int i=0;i<len;i++){
        if(i=(len-1)){
            cout<<n[i];
        }
    }
    
   }
