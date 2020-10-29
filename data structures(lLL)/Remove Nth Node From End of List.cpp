/*Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?



Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]


Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz*/

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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//METHOD 1:- (ONE PASS)
		if (head->next == NULL && n == 1) {
			return NULL;
		}
		ListNode* temp = head;
		int cnt = 0;
		while (temp != NULL) {
			temp = temp->next;
			cnt++;
		}
		if (n == cnt) {
			head = head->next;
			return head;
		}

		ListNode* temp1 = head;
		ListNode* temp2 = head;
		while (n--) {
			temp2 = temp2->next;
		}
		while (temp2->next != NULL) {
			temp2 = temp2->next;
			temp1 = temp1->next;
		}
		ListNode*prev = temp1;
		ListNode*curr = temp1->next;
		temp1 = temp1->next;
		prev->next = curr->next;
		delete(temp1);
		return head;


		//METHOD 2:-(TWO PASS)

		// if(head->next==NULL && n==1){
		//     return NULL;
		// }

		// ListNode* temp=head;
		// int cnt=0;
		// while(temp!=NULL){
		//     temp=temp->next;
		//     cnt++;
		// }
		// if(n==cnt){
		//     head=head->next;
		//     return head;
		// }
		// int m=cnt-n-1;
		// ListNode* temp1=head;
		// while(m--){
		//          temp1=temp1->next;
		// }
		// ListNode*prev= temp1;
		// ListNode*curr= temp1->next;
		// temp1=temp1->next;
		// prev->next=curr->next;
		// delete(temp1);
		// return head;
	}
};