#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node*left;
    node*right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree() {
    //preorder traversal
    //or u can pass node* root above where root=NULL by default like head in linked lists
    int d;
    cin >> d;

    if (d == -1) {
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}


void print(node *root) {
    if (root == NULL) {
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}


void print_inorder(node *root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    cout << root->data << " ";

    print_inorder(root->right);
}


void print_postorder(node *root) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);

    cout << root->data << " ";
}

//time complexity o(n)
int height(node* root) {
    if (root == NULL) {
        return 0;
    }
    //ls=left subtree
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}

void print_k_level(node* root, int k) {
    if (root == NULL) {
        return;
    }
    if (k == 1) {
        cout << root->data << " ";
        return;
    }
    print_k_level(root->left, k - 1);
    print_k_level(root->right, k - 1);

}

void print_all_levels(node* root) {
    int height_tree = height(root);
    for (int i = 1; i <= height_tree; i++) {
        print_k_level(root, i);
        cout << endl;

    }
}

//level order print in a single line

void bfs(node *root) {
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* f = q.front();
        cout << f->data << ",";
        q.pop();

        if (f->left) {
            q.push(f->left);
        }
        if (f->right) {
            q.push(f->right);
        }
    }
    return;
}
//level order print in a multiple lines
//level order print iterative method
void bfs1(node* root) {
    queue<node*> qu;
    qu.push(root);
    qu.push(NULL);

    while (!qu.empty()) {
        node*f = qu.front();
        if (f == NULL) {
            cout << endl;
            qu.pop();
            if (!qu.empty()) {
                qu.push(NULL);
            }
        }
        else {
            cout << f->data << " ";

            qu.pop();
            if (f->left) {
                qu.push(f->left);
            }
            if (f->right) {
                qu.push(f->right);
            }
        }
    }
    return;
}

//total number of nodes
//time complexity o(n)
int count_nodes(node* root) {
    if (root == NULL) {
        return 0;
    }
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}


//total sum of nodes
//time complexity o(n)
int count_nodes(node* root) {
    if (root == NULL) {
        return 0;
    }
    return count_nodes(root->left) + count_nodes(root->right) + root->data;
}

//time complexity o(n^2)
int diameter(node* root) {
    if (root == NULL) {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int opt1 = h1 + h2;
    int opt2 = diameter(root->left);
    int opt3 = diameter(root->right);

    return max(opt1, max(opt2, opt3));
}

//optimized diameter method
class Pair {
public:
    int diameter;
    int height;
};

Pair fastDiameter(node* root) {
    Pair p;
    if (root == NULL) {
        p.height = p.diameter = 0;
        return p;
    }
//otherwise
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left->diameter, right->diameter));
    return p;
}

int replaceSum(node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->data;
    }
    //Recursive Part
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;
    return temp + root->data;

}

class HBpair {
public:
    int height;
    bool balance;
}

HBpair isHeightBalance(node* root) {
    HBPair p;
    if (root == NULL) {
        p.height = 0;
        p.balance = true;
        return p;
    }
    //Recurisve Case
    HBpair left = isHeightBalance(root->left);
    HBpair right = isHeightBalance(root->right);
    p.height = max(left.height, right.height) + 1;

    if (abs(left.height - right.height) <= 1 && left.balance && right.balance) {
        p.balance = true;
    }
    else {
        p.balance = false;
    }
    return p;
}


node* build_height_balanced_treefrom_array(int *a, int s, int e) {
    if (s > e) {
        return NULL;
    }

    int mid = (s + e) / 2;

    node* root = new node(a[mid]);
    root->left = build_height_balanced_treefrom_array(a, s, mid - 1);
    root->right =build_height_balanced_treefrom_array(a, mid + 1, e);
    return root;
}

node* buildtreefrom_inorder_preorder(int *in, int* pre, int s, int e) {
    static int i = 0;
    int x = -1;
    if (s > e) {
        return NULL;
    }
    node* root = new node(pre[i]);
    for (int j = 0; j < e; j++) {
        if (pre[i] == in[j]) {
            x = j;
            break;
        }
    }
    i++;
    root->left = buildtreefrom_inorder_preorder(in, pre, s, x - 1);
    root->right = buildtreefrom_inorder_preorder(in, pre, x + 1, e);
    return root;

}

void left_view(node *root) {
    queue<node*> Q;
    Q.push(NULL);
    Q.push(root);
    while (!Q.empty()) {
        node* cur = Q.front();
        Q.pop();
        if (cur == NULL) {
            if (!Q.empty()) {
                cout << Q.front()->val << '\n';
                Q.push(NULL);
            }
        }
        else {
            if (cur->left != NULL) {
                Q.push(cur->left);
            }
            if (cur->right != NULL) {
                Q.push(cur->right);
            }
        }
    }
}


void mirror_tree(node *root) {
    if (root == NULL) return;
    swap(root->left, root->right);
    mirror_tree(root->left);
    mirror_tree(root->right);
}


//Accepts the old root node & data and returns the new root node
node* insertInBST(node *root, int data) {
    //Base Case
    if (root == NULL) {
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if (data <= root->data) {
        root->left = insertInBST(root->left, data);
    }
    else {
        root->right = insertInBST(root->right, data);
    }
    return root;
}

//inorder of a bst is always a sorted array

//for binary search tree
node* build() {
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin >> d;

    node*root = NULL;

    while (d != -1) {
        root = insertInBST(root, d);
        cin >> d;
    }
    return root;
}


//time complexity if o(H) which can lie between o(log N)<=O(H)<=O(N)
//"H" IS THE HEIGHT OF THE TREE
bool search_bst(node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (key == root->data) {
        return true;
    }
    if (key < (root->data)) {
        search_bst(root->left, key);
    }
    else {
        search_bst(root->right, key);

    }
    return false;

}


//when sorted array is given
node* build_bst(int *arr, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    node *root = new node(arr[mid]);
    root->left = build_bst(arr, start, mid - 1);
    root->right = build_bst(arr, mid + 1, end);
    return root;

}


node* deleteInBST(node*root, int data) {
    if (root == NULL) {
        return NULL;
    }
    else if (data < root->data) {
        root->left = deleteInBST(root->left, data);
        return root;
    }
    else if (data == root->data) {
        //Found the node to delete 3 Cases
        //1. Node with 0 children - Leaf Node
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        //2. Case Only 1 child
        if (root->left != NULL && root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        if (root->right != NULL && root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        //3. Case 2 children
        node *replace = root->right;
        //Find the inorder successor from right subtree
        while (replace->left != NULL) {
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteInBST(root->right, replace->data);
        return root;
    }
    else {
        root->right = deleteInBST(root->right, data);
        return root;
    }
}

//TOP DOWN APPROACH
bool isBST(node *root, int minV = INT_MIN, int maxV = INT_MAX) {
    if (root == NULL) {
        return true;
    }
    if (root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV)) {
        return true;
    }
    return false;

}



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

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
