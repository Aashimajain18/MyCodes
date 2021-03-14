/*
Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed. */



vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode * >s;
    s.push(A);
    
    // queue<int> q;
    vector<int> ans;
    while(!s.empty())
    {
        TreeNode * temp = s.top();
        s.pop();
        ans.push_back(temp->val);
        
        if(temp->right) s.push(temp->right);
        if(temp->left) s.push(temp->left);
        
    }
    return ans;
    
    
}
