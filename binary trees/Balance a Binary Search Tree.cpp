/*
Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.

 

Example 1:



Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.
 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The tree nodes will have distinct values between 1 and 10^5.

*/

//My solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build_height_balanced_treefrom_array(vector<int>&a, int s, int e) {
    if (s > e) {
        return NULL;
    }

    int mid = (s + e) / 2;

    TreeNode* root = new TreeNode(a[mid]);
    root->left = build_height_balanced_treefrom_array(a, s, mid - 1);
    root->right =build_height_balanced_treefrom_array(a, mid + 1, e);
    return root;
}
    
    
    void add_invector(TreeNode* root,vector<int>&arr) {
        if(root==NULL){
            return;
        }
        add_invector(root->left,arr);
        arr.push_back(root->val);
        add_invector(root->right,arr);
        return;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        add_invector(root,arr);
        // for(int i=0;i<arr.size();i++){
        //     cout<<arr[i];
        // }
        return build_height_balanced_treefrom_array(arr,0,arr.size()-1);
        
    }
};


//logic:- divide array from mid and make it root and then recurse the same for left and right side as well
