/*
https://leetcode.com/problems/binary-tree-maximum-path-sum/
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

	int findMaxUtil(TreeNode* root, int &res) {
//Base Case
		if (root == NULL)
			return 0;

		// l and r store maximum path sum going through left and
		// right child of root respectively
		int l = findMaxUtil(root->left, res);
		int r = findMaxUtil(root->right, res);

		// Max path for parent call of root. This path must
		// include at-most one child of root
		int max_single = max(max(l, r) + root->val, root->val);

		// Max Top represents the sum when the Node under
		// consideration is the root of the maxsum path and no
		// ancestors of root are there in max sum path
		int max_top = max(max_single, l + r + root->val);

		res = max(res, max_top); // Store the Maximum Result.

		return max_single;

	}


	int maxPathSum(TreeNode* root) {

// Initialize result
		int res = INT_MIN;

		// Compute and return result
		findMaxUtil(root, res);
		return res;
	}
};