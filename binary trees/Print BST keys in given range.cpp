/*
You are given an array of integers. First of all , You have to form a binary search tree from
given integers. Now you have provided two integers k1 and k2. You have to print all nodes of BST
 within the range k1 and k2 (including k1 and k2).

Input Format
First line contains integer t as number of test cases. Each test case contains three lines. First
line contains an integer n which is length of the array and second line contains n space separated
integer. Third line contains the value of k1 and k2.

Constraints
1 < t < 20
1 < n < 50

Output Format
For each test case you have to print preorder traversal of the tree first and then print all nodes
within the range k1 and k2 (inclusive). Refer to the sample testcase for exact output format.

Sample Input
1
5
4 3 2 5 6
3 5
Sample Output
# Preorder : 4 3 2 5 6
# Nodes within range are : 3 4 5
Explanation
The tree looks like

             4
          /      \
       3           5
    /                \
   2                  6
The nodes between the range 3 to 5 are 3,4,5.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include<stack>
#include<list>
#include<unordered_map>
#include<queue>
#include<map>
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

void print_preorder(node *root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";

	print_preorder(root->left);
	print_preorder(root->right);

}


void Print(node *root, int k1, int k2)
{
	/* base case */
	if ( NULL == root )
		return;

	/* Since the desired o/p is sorted, recurse for left subtree first
	    If root->data is greater than k1, then only we can get o/p keys
	    in left subtree */
	if ( k1 < root->data )
		Print(root->left, k1, k2);

	/* if root's data lies in range, then prints root's data */
	if ( k1 <= root->data && k2 >= root->data )
		cout << root->data << " ";
	/* If root->data is smaller than k2, then only we can get o/p keys
	    in right subtree */
	if ( k2 > root->data )
		Print(root->right, k1, k2);
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
node* build(int n) {

	node*root = NULL;

	while (n--) {
		int d;
		cin >> d;

		root = insertInBST(root, d);
	}
	return root;
}


int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, k1, k2;
		cin >> n;
		node* root = build(n);
		cin >> k1 >> k2;
		cout << "# Preorder :" << " ";
		print_preorder(root);
		cout << endl;

		cout << "# Nodes within range are :" << " ";
		Print(root, k1, k2);
		cout << endl;
	}

	return 0;
}


