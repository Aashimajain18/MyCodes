/*
Given two linked lists, insert nodes of second list into first list at alternate positions of first list.
For example, if first list is 5->7->17->13->11 and second is 12->10->2->4->6, the first list should become 5->12->7->10->17->2->13->4->11->6 and second list should become empty. The nodes of second list should only be inserted when there are positions available. For example, if the first list is 1->2->3 and second list is 4->5->6->7->8, then first list should become 1->4->2->5->3->6 and second list to 7->8.

Use of extra space is not allowed (Not allowed to create additional nodes), i.e., insertion must be done in-place. Expected time complexity is O(n) where n is number of nodes in first list.


/*
structure of the node of the linked list is
struct Node
{
	int data;
	struct Node *next;
};
*/
// complete this function
void mergeList(struct Node **p, struct Node **q)
{
     // Code here
     struct Node *temp1,*temp2,*list1,*list2;
     list1 = *p;
     list2 = *q;
     while(list1 != NULL && list2 != NULL){
         temp1 = list1->next;
         temp2 = list2->next;
         list1->next = list2;
         list1->next->next = temp1;
         list1 = temp1;
         list2 = temp2;
     }
     *q = list2;
}
