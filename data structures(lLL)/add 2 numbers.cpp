/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/
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

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ans = NULL;
		int carry = 0;

		while (l1 != NULL || l2 != NULL) {
			int sum = 0;
			if (l2 == NULL) {
				sum = l1->val + carry;
				l1 = l1->next;
				int fsum = sum % 10;
				insertAttail(ans, fsum);
				if (sum >= 10) {
					carry = sum / 10;

				}
				else {
					carry = 0;
				}
			}
			else if (l1 == NULL) {
				sum = l2->val + carry;
				l2 = l2->next;
				int fsum = sum % 10;
				insertAttail(ans, fsum);
				if (sum >= 10) {
					carry = sum / 10;

				}
				else {
					carry = 0;
				}
			}
			else {
				sum = ((l1->val) + (l2->val) + carry);
				l1 = l1->next;
				l2 = l2->next;

				int fsum = sum % 10;
				insertAttail(ans, fsum);
				if (sum >= 10) {
					carry = sum / 10;

				}
				else {
					carry = 0;
				}
			}


		}
		if (carry != 0) {
			insertAttail(ans, carry);
		}
		return ans;
	}
};
