/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
int merge_circularlists(struct node **head1, struct node **head2)
{
	int n = 0;
	if (head1 == NULL || head2 == NULL)
		return  -1;
	struct node *t1, *t2, *t3;
	t1 = *head1;
	t2 = *head2;
	t1 = t1->next;
	while (t1 != *head1)
	{
		if (t1->next == *head1)
		{
			t1->next = *head2;
			t1 = t1->next;
		}
		else
			t1 = t1->next;
	}
	t2 = t2->next;
	while (t2 != *head2)
	{
		if (t2->next = *head2)
		{
			t2->next = NULL;
			break;
		}
		else
			t2 = t2->next;
	}
	t3 = *head1;
	while (t3 != NULL)
		n++;
	struct node *temp1, *temp2;
	int i = 0,t=0;
	while (i <= (n - 1))
	{
		t1 = *head1;
		t2 = t1->next;
		while (t2 != NULL)
		{
			if ((t1->data) > (t2->data))
			{
				t = t1->data;
				t1->data = t2->data;
				t2->data = t;
			}
			t1 = t1->next;
			t2 = t2->next;
		}
		i++;
	}
	t3 = *head1;
	t3 = t3->next;
	for (i = 0; i < n - 1; i++)
	{
		if (t3->next == NULL)
		{
			t3->next = *head1;
			break;
		}
	}
	return n;
	/*here my idea is to link two circular lists (by changing the next of last node of list1 as pointer to second list)
	and to sort by applying bubble sort and again return the no of nodes in the merged list */
}
