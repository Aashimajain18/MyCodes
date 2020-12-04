/*Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

Note: The flattened list will be printed using the bottom pointer instead of next pointer.

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     |
7     20    22   35
|           |     |
8          50    40
|                 |
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.

Note: | represents the bottom pointer.
Your Task:
You need to complete the function flatten() that takes head of the list as parameter and returns the root of flattened list. The printing is done by the driver code.

Note: Try to solve the problem without using any extra space.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)

Constraints:
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 10^3*/

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;

	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}

};
*/

Node *merge(Node *a, Node *b) {
	if (a == NULL) {
		return b;
	}
	if (b == NULL) {
		return a;
	}

	// Compare the data members of head nodes of both lists
	// and put the smaller one in result
	Node* result;
	if (a->data < b->data)
	{
		result = a;
		result->bottom = merge( a->bottom, b );
	}
	else
	{
		result = b;
		result->bottom = merge( a, b->bottom );
	}

	result->next = NULL;
	return result;
}
/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{
// Base cases
	if (root == NULL || root->next == NULL)
		return root;

	// Merge this list with the list on right side
	return merge( root, flatten(root->next) );
}

