/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 10^4].
0 <= Node.val <= 5 * 10^4
The tree is guaranteed to be complete.

*/

//solution 1:-
class Solution {
public:
    
    /*
    We need to design an algo which runs in less than O(n) time complexity. So, one 
    way is to just travel the edges as this is a complete binary tree (except last level) 
    so we know the number of nodes at any level. So, we must travel on edges only as we can find nodes       between the edges at any level as 2^level. 
    */ 
	
    int countNodes(TreeNode* root) 
    {
        if(root == NULL) return 0;
        
        TreeNode* l = root; 
        TreeNode* r = root;
        
        int leftH = 0, rightH = 0;  //To compare heights
        
        while(l)                    //Traverse left edge till left node exists and count the left height
        {
            l = l->left;
            leftH++;
        }
        
        while(r)                    //Tranverse right edge till right node exists and count the right height
        {
            r = r->right;
            rightH++;
        }
        
        if(leftH == rightH)     //If left and Right height are equal then return the height in O(n)
        {
            return (1 << leftH) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right); //If height and right heights are not equal then go in recursion and look for that subtree which is complete.
    }
};


//solution 2:-
int getLeftHeight(TreeNode* root) {
    int height = 0;
    while(root) { 
        root = root->left;
        height++;
    }
    return height;
}

int countNodes(TreeNode* root) {
    if(!root) return 0;
    
    int left_height = getLeftHeight(root->left);
    int right_height = getLeftHeight(root->right);
    
    if(left_height == right_height) 
        return pow(2, left_height) + countNodes(root->right);
        
    return pow(2, right_height) + countNodes(root->left);
}
