/*
Given two trees check if they are structurally identically. Structurally identical trees are trees that have same structure.
They may or may not have the same data though.

Input Format
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests 
it is NULL

Constraints
1 <= N <= 10^4

Output Format
Display the Boolean result

Sample Input
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output
true
Explanation
The given two trees have the exact same structure and hence we print true.
*/

#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* build(string r){
    if(r == "false"){
        return NULL ;
    }
int d ;
cin >> d ;
node* root = new node(d) ;
string r2 ;
cin >> r2 ;
root->left = build(r2) ;
string r3 ;
cin >> r3 ;
root->right = build(r3) ;
return root ;
}

bool check(node* root1,node* root2){
if(root1 == NULL && root2 == NULL) return true ;
if((root1 != NULL && root2 == NULL ) || (root1 == NULL && root2 != NULL )) return false ;

return (check(root1->left,root2->left) && check(root1->right,root2->right)) ;
}



void print(node *root){
    if(root==NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int main()
{
    node* root1 = NULL ;
    node* root2 = NULL ;
    root1 = build("true") ;
    root2 = build("true") ;
    if(check(root1,root2)){
        cout <<"true" ;
    }
    else {
        cout <<"false" ;
    }
    }
