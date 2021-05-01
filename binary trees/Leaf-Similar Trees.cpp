/*
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Example 1:


Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
Example 2:

Input: root1 = [1], root2 = [1]
Output: true
Example 3:

Input: root1 = [1], root2 = [2]
Output: false
Example 4:

Input: root1 = [1,2], root2 = [2,2]
Output: true
Example 5:


Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
 

Constraints:

The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200].
*/

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
    void add_leafs_tovector(TreeNode* root, vector<int> &r){
        if(root->left==NULL && root->right==NULL){
            r.push_back(root->val);
            return;
        }
        else if( root->right==NULL){
                    add_leafs_tovector(root->left,r);
        }
        else if(root->left==NULL){
            add_leafs_tovector(root->right,r);
        }
        else{
        add_leafs_tovector(root->left,r);
        add_leafs_tovector(root->right,r);
        }
        return;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
       vector<int> r1; 
        vector<int> r2; 
        add_leafs_tovector(root1,r1);
        add_leafs_tovector(root2,r2);
        if(r1==r2){
            return true;
        }
        return false;
    }
};
