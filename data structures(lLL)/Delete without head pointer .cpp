/*You are given a pointer/ reference to the node which is to be deleted from the linked list of
N nodes. The task is to delete the node. Pointer/ reference to head node is not given.
Note: No head reference is given to you.

Example 1:

Input:
N = 2
value[] = {1,2}
node = 1
Output: 2
Explanation: After deleting 1 from the
linked list, we have remaining nodes
as 2.
Example 2:

Input:
N = 4
value[] = {10,20,4,30}
node = 20
Output: 10 4 30
Explanation: After deleting 20 from
the linked list, we have remaining
nodes as 10, 4 and 30.
Your Task:
You only need to complete the function deleteNode that takes reference to the node that needs to
be deleted. The printing is done automatically by the driver code.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 <= N <= 103

*/

void deleteNodeWithoutHead(struct Node* pos)
{
	if (pos == NULL) // If linked list is empty
		return;
	else {

		if (pos->next == NULL) {
			printf("This is last node, require head, can't be freed\n");
			return;
		}

		struct Node* temp = pos->next;

		// Copy data of the next node to current node
		pos->data = pos->next->data;

		// Perform conventional deletion
		pos->next = pos->next->next;

		free(temp);
	}
}

/*
It would be a simple deletion problem from the singly linked list if the head pointer was given
because for deletion you must know the previous node and you can easily reach there by traversing
from the head pointer. Conventional deletion is impossible without knowledge of the previous node
of a node which needs to be deleted.

The trick here is we can copy the data of the next node to the data field of the current node to
e deleted. Then we can move one step forward. Now our next has become the current node and
current has become the previous node. Now we can easily delete the current node by conventional
deletion methods.
*/