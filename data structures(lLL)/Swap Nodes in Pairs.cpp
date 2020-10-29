/*
gfg
*/
#include <bits/stdc++.h>
using namespace std;
//gfg
struct Node
{
	int data;
	struct Node* next;

	Node(int x) {
		data = x;
		next = NULL;
	}
};

Node* pairWiseSwap(Node* head);

void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << "\n";
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int data;
		cin >> data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n - 1; ++i)
		{
			cin >> data;
			tail->next = new Node(data);
			tail = tail->next;
		}

		head = pairWiseSwap(head);
		printList(head);
	}
	return 0;
}
// } Driver Code Ends


/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as
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
//method-1
/* Recursive function to pairwise swap elements
   of a linked list */
void pairWiseSwap1(struct Node* head)
{
	Node* temp = head;

	/* Traverse further only if
	there are at-least two nodes left */
	while (temp != NULL && temp->next != NULL) {
		/* Swap data of node with
		   its next node's data */
		swap(temp->data,
		     temp->next->data);

		/* Move temp by 2 for the next pair */
		temp = temp->next->next;
	}
}

//method-2
void pairWiseSwap2(struct Node *head)
{
	// The task is to complete this method
	struct Node *p = head;
	struct Node *q = head->next;
	int temp;
	while (p && q)
	{
		temp = p->data;
		p->data = q->data;
		q->data = temp;
		if (!q->next || !q->next->next)
			break;
		else {
			p = p->next->next;
			q = q->next->next;
		}
	}
}
//method-3
//method with swaping of actual nodes and not the data
struct Node* swapPairs(struct Node* head) {
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;

	struct Node* next_node = head->next;
	head->next = swapPairs(next_node->next);
	next_node->next = head;

	return next_node;
}

Node* pairWiseSwap(struct Node* head) {
	// The task is to complete this method
	pairWiseSwap1(head);
	return head;
}