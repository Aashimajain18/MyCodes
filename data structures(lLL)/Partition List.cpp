/*Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.



Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]


Constraints:

The number of nodes in the tree is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
	void insertAttail(ListNode*&head, int data) {
		ListNode*n = new ListNode(data);

		if (head == NULL) {
			head = n;
			return;
		}
		ListNode*temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = n;
		return;
	}

	ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode* smalllist = NULL;
		ListNode* biglist = NULL;
		ListNode* temp1 = head;
		while (temp1 != NULL) {
			if (temp1->val >= x) {
				insertAttail(biglist, temp1->val);
			}
			else {
				insertAttail(smalllist, temp1->val);
			}
			temp1 = temp1->next;
		}
		ListNode*temp2 = smalllist;
		if (smalllist == NULL) {
			return biglist;
		}
		while (temp2->next != NULL) {
			temp2 = temp2->next;
		}
		temp2->next = biglist;
		return smalllist;
	}
};