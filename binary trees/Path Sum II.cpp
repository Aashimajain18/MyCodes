/*Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> aResult;
		vector<int> aList;
		pathSum1(aResult, root, sum, aList);
		return aResult;
	}

	void pathSum1(vector<vector<int>> &pResult, TreeNode *root, int sum, vector<int>&pList) {

		if (root == NULL) { return; }

		sum -= root->val;

		pList.push_back(root->val);

		if (root->left == NULL && root->right == NULL && sum == 0) {
			pResult.push_back(pList);
		}
		if (root->left)  {
			pathSum1(pResult, root->left,  sum, pList);
		}
		if (root->right) {
			pathSum1(pResult, root->right, sum, pList);
		}

		pList.pop_back();
	}
};