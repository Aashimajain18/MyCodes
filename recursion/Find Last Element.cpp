/*
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. Write a recursive function which returns the last index at which M is found in the array and -1 if M is not found anywhere. Print the value returned.

Input Format
There will be three lines of input:

N - the size of the array
N space separated integers that make up the array
M
Constraints
1 < N < 1000
-10^9 < i,M < 10^9 , where i is any number within the array

Output Format
For each case, print the integer value of the last index that M is found at within the given array.
If it is not found, print '-1' (without the quotes).

Sample Input
7
86 -16 77 65 45 77 28
77
Sample Output
5
Explanation
Last occurence of 77 is found at index = 5.
*/

 #include<iostream>
   #include<vector>
   #include<string>
   #include<algorithm>

   using namespace std;

  int ispresent(int *a,int n,int key,int check){
      if(n==0){
          return -1;
      }
      if(a[n]==key){
          check++;
          if(check==1){
              return n-1;
          }

          
      }
      return ispresent(a,n-1,key,check);
        }
       

   int main(){
       int n,i;
       cin>>n;
       int a[n];
       for(i=1;i<=n;i++){
           cin>>a[i];
       }
       int key;
       cin>>key;
       cout<<ispresent(a,n,key,0)<<endl;
   }
