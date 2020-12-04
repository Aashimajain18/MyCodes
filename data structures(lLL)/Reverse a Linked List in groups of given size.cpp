/*Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5
Example 2:

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4
Your Task:
The task is to complete the function reverse() which should reverse the linked list in group of size k and return the head of the modified linked list.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse (struct node *head, int k);

struct node
{
	int data;
	struct node* next;

	node(int x) {
		data = x;
		next = NULL;
	}

};

/* Function to print linked list */
void printList(struct node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		struct node* head = NULL;
		struct node* temp = NULL;
		int n;
		cin >> n;

		for (int i = 0 ; i < n ; i++)
		{
			int value;
			cin >> value;
			if (i == 0)
			{
				head = new node(value);
				temp = head;
			}
			else
			{
				temp->next = new node(value);
				temp = temp->next;
			}
		}

		int k;
		cin >> k;

		head = reverse(head, k);
		printList(head);
	}

	return (0);
}

// } Driver Code Ends


/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

struct node *reverse (struct node *head, int k)
{
	struct node* current = head;
	struct node* next = NULL;
	struct node* prev = NULL;
	int count = 0;

	/*reverse first k nodes of the linked list */
	while (current != NULL && count < k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	/* next is now a pointer to (k+1)th node
	Recursively call for the list starting from current.
	And make rest of the list as next of first node */
	if (next != NULL)
		head->next = reverse(next, k);

	/* prev is new head of the input list */
	return prev;
}
