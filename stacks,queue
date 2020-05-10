//
//  main.cpp
//  stacks,queue
//
//  Created by Aashima Jain on 20/04/20.
//  Copyright © 2020 Aashima Jain. All rights reserved.
//


/*
#include <iostream>
#include <vector>
using namespace std;

//Implementation of Stack Data Structure using Vector

template<typename T,typename U>
class Stack{
private:
    vector<T> v;
    vector<U> v2;
public:
    void push(T data){
        v.push_back(data);
    }
    bool empty(){
        return v.size()==0;
    }
    void pop(){
        if(!empty()){
             v.pop_back();
        }
    }
    T top(){
        return v[v.size()-1];
    }
};
//instead of making the above class we can also simple add the header file <stack>

int main() {
    Stack<char,int> s;

    for(int i=65;i<=70;i++){
        s.push(i);
    }
    //Try to print the content of the stack by popping each element
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }


    
return 0;
}
*/



#include <iostream>
#include <stack>
using namespace std;

void transfer(stack<int>& s1,stack<int>& s2,int n ){
    
    for(int i=0;i<n;i++){
        s2.push(s1.top());
        s1.pop();
    }
}
//using 1 stack method
void reverse_stack(stack<int>& s1){
    stack<int> s2;
    int n=s1.size();
    for(int i=0;i<n;i++){
    int x=s1.top();
        s1.pop();
        transfer(s1,s2,n-i-1);
        s1.push(x);
        transfer(s2,s1,n-i-1);

    
    }
}

int main() {
    stack<int> s;
    int size;
    int x;
    cin>>size;

    for(int i=0;i<size;i++){
        cin>>x;
        s.push(x);
    }


    reverse_stack(s);
    //Try to print the content of the stack by popping each element
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }


    
return 0;
}
