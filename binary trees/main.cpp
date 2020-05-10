#include <iostream>
#include <queue>
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

node* buildTree(){
    //or u can pass node* root above where root=NULL by default like head in linked lists
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
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
void print_inorder(node *root){
    if(root==NULL){
        return;
    }
      print_inorder(root->left);
    cout<<root->data<<" ";
  
print_inorder(root->right);
}
void print_postorder(node *root){
    if(root==NULL){
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
        cout<<root->data<<" ";
}
int height(node* root){
    if(root==NULL){
        return 0;
    }
    //ls=left subtree
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}

void print_k_level(node* root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    print_k_level(root->left, k-1);
    print_k_level(root->right, k-1);

}
 
void print_all_levels(node* root){
    int height_tree=height(root);
    for(int i=1;i<=height_tree;i++){
        print_k_level(root,i);
        cout<<endl;

    }
}

//level order print iterative method
void bfs(node* root){
    queue<node*> qu;
    qu.push(root);
    qu.push(NULL);

    while(!qu.empty()){
        node*f=qu.front();
        if(f==NULL){
            cout<<endl;
            qu.pop();
            if(!qu.empty()){
                    qu.push(NULL);
            }
        }
        else{
            cout<<f->data<<" ";
        
        qu.pop();
        if(f->left){
            qu.push(f->left);
        }
        if(f->right){
            qu.push(f->right);
        }
        }
    }
    return;
}
//complexity of below given code is o(n)
int total_nodes(node* root){
    if(root==NULL){
        return 0;
    }
    int lst=total_nodes(root->left);
    int rst=total_nodes(root->right);

    return 1+lst+rst;
}
//complexity of below given code is o(n)

int sum_of_all_nodes(node* root){
    if(root==NULL){
        return 0;
    }
    int lst=sum_of_all_nodes(root->left);
    int rst=sum_of_all_nodes(root->right);

    return root->data+lst+rst;
}
//complexity of below given code is o(n^2)

int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    int opt1=h1+h2;
    int opt2=diameter(root->left);
    int opt3=diameter(root->right);
    return max((max(opt1,opt2)),opt3);
}
class Pair{
    public:
        int height;
        int diameter;
};
//complexity of below given code is o(n)

Pair fastDiameter(node*root){
    Pair p;
    if(root==NULL){
        p.diameter = p.height = 0;
        return p;
    }
    //Otherwise
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height,right.height) + 1;
    p.diameter = max(left.height+right.height, max(left.diameter,right.diameter));
    return p;
}


int replaceSum(node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    //Recursive Part
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;
    return temp + root->data;
}


class HBPair{
public:
    int height;
    bool balance;
};

HBPair isHeightBalance(node *root){
    HBPair p;
    if(root==NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }
    //Recurisve Case
    HBPair left = isHeightBalance(root->left);
    HBPair right = isHeightBalance(root->right);
    p.height = max(left.height,right.height) + 1;

        if(abs(left.height-right.height)<=1 && left.balance && right.balance){
            p.balance = true;
        }
        else{
            p.balance = false;
        }
        return p;
    }

node* buildtreefrom_array(int *a,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    
    node* root=new node(a[mid]);
    root->left=buildtreefrom_array(a, s, mid-1);
    root->right=buildtreefrom_array(a, mid+1,e);
    return root;
}

node* buildtreefrom_inorder_preorder(int *in,int* pre,int s,int e){
    static int i=0;
    int x=-1;
    if(s>e){
        return NULL;
    }
    node* root=new node(pre[i]);
    for(int j=0;j<e;j++){
        if(pre[i]==in[j]){
            x=j;
            break;
        }
    }
    i++;
    root->left=buildtreefrom_inorder_preorder(in, pre, s, x-1);
    root->right=buildtreefrom_inorder_preorder(in, pre, x+1,e);
    return root;
    
}


//Accepts the old root node & data and returns the new root node
node* insertInBST(node *root,int data){
    //Base Case
    if(root==NULL){
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if(data<=root->data){
        root->left = insertInBST(root->left,data);
    }
    else{
        root->right = insertInBST(root->right,data);
    }
    return root;
}

//for binary search tree
node* build(){
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin>>d;

    node*root = NULL;

    while(d!=-1){
        root = insertInBST(root,d);
        cin>>d;
    }
    return root;
}
bool search_bst(node* root,int key){
    if(root==NULL){
        return false;
    }
    if(key==root->data){
        return true;
    }
    if(key<(root->data)){
        search_bst(root->left, key);
    }
    else{
        search_bst(root->right, key);
        
    }
    return false;

}

//when sorted array is given
node* build_bst(int *arr,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
      node *root=new node(arr[mid]);
      root->left=build_bst(arr,start,mid-1);
      root->right=build_bst(arr,mid+1,end);
    return root;
    
}


node* deleteInBST(node*root,int data){
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left = deleteInBST(root->left,data);
        return root;
    }
    else if(data==root->data){
        //Found the node to delete 3 Cases
        //1. Node with 0 children - Leaf Node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //2. Case Only 1 child
            if(root->left!=NULL && root->right==NULL){
                node* temp = root->left;
                delete root;
                return temp;
            }
            if(root->right!=NULL && root->left==NULL){
                node* temp = root->right;
                delete root;
                return temp;
            }
        //3. Case 2 children
            node *replace = root->right;
            //Find the inorder successor from right subtree
            while(replace->left!=NULL){
                replace = replace->left;
            }
            root->data = replace->data;
            root->right = deleteInBST(root->right,replace->data);
            return root;
    }
    else{
        root->right = deleteInBST(root->right,data);
        return root;
    }
}


bool isBST(node *root,int minV = INT_MIN,int maxV = INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data >= minV && root->data<=maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)){
        return true;
    }
    return false;
}


int main(){
    node* root = buildTree();
    bfs(root);
   /*
    Pair p = fastDiameter(root);
    cout<<p.height<<endl;
    cout<<p.diameter<<endl;
    */
    /*
    if(isHeightBalance(root).balance){
        cout<<"Balanced";
    }
    else{
        cout<<"Not a Balanced Tree"<<endl;
    }
    */
    replaceSum(root);
    bfs(root);
    return 0;
}

//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

