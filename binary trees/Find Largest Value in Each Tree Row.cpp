/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

 

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]
Example 3:

Input: root = [1]
Output: [1]
Example 4:

Input: root = [1,null,2]
Output: [1,2]
Example 5:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-2^31 <= Node.val <= 2^31 - 1
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

//level order traversal
//bfs solution
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
              vector<int> ans;
   
        queue<TreeNode*>q;
        if(root!=NULL) q.push(root);
        while(!q.empty()){
            int n=q.size();
                 int maxi=INT_MIN;
            for(int i=1;i<=n;i++){
                TreeNode* node=q.front();
                 q.pop();
                maxi=max(maxi,node->val);
               
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
              
            }
              ans.push_back(maxi);
        }
        return ans;
    }
};



//dfs solution
//my solution
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
 vector<int>ans;
    void dfs(TreeNode*root,int level){
        if(root==NULL) {
            return;
        }
        if(ans.size()==level){
            //push first element of each row so that it can be changed later if required
            ans.push_back(root->val);
        }
        if(ans[level]<root->val) {
            ans[level]=root->val;
        }
        dfs(root->left,level+1);
        dfs(root->right,level+1);
        return;
    }
    
    vector<int> largestValues(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};
