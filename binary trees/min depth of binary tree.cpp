/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.
Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000

*/

//my solution
class Solution {
public:
    int ans=INT_MAX;
    void minimumDepth(TreeNode* root,int h) {
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
        if(h!=1){
            ans=min(ans,h);
            }
            return;
        }
        
        
        minimumDepth(root->left,h+1);
        minimumDepth(root->right,h+1);
        return ;
    }
    
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        minimumDepth(root,1);
        return ans;
    }
};


//faster iterative solution
int minDepth(TreeNode* root) {
    if (root == NULL) return 0;
    queue<TreeNode*> Q;
    Q.push(root);
    int i = 0;
    while (!Q.empty()) {
        i++;
        int k = Q.size();
        for (int j=0; j<k; j++) {
            TreeNode* rt = Q.front();
            if (rt->left) Q.push(rt->left);
            if (rt->right) Q.push(rt->right);
            Q.pop();
            if (rt->left==NULL && rt->right==NULL) return i;
        }
    }
    return -1; //For the compiler thing. The code never runs here.
}
