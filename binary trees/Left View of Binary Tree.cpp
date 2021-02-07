/*Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3


Your Task:
You just have to complete the function leftView() that prints the left view.
The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).



Constraints:
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

*/

//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1/?company[]=Visa&company[]=Twitter&problemType=functional&page=1&sortBy=submissions&query=company[]Visacompany[]TwitterproblemTypefunctionalpage1sortBysubmissions#

void leftViewPrint(Node*root, int level, int &maxlevel, vector<int>&ans)
{
	if (root == NULL) {
		return;
	}

	if (maxlevel < level) {
		ans.push_back(root->data);
		maxlevel = level;
	}
	leftViewPrint(root->left, level + 1, maxlevel, ans);
	leftViewPrint(root->right, level + 1, maxlevel, ans);
	return;
}
// A wrapper over leftViewUtil()
vector<int> leftView(Node *root)
{
	// Your code here
	vector<int> ans;
	int maxlevel = -1;
	leftViewPrint(root, 0, maxlevel, ans);
	return ans;
}
