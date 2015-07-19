#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};

/* Function to get count of the nodes in linked list */
int getCount(struct node* head);

/*
* Function to get the intersection point of two linked lists head1 and head2 where head1 had d more nodes
* than head2
*/
int _getIntersectionNode(int d, struct node* head1, struct node* head2)
{
	int i;
	struct node* current1 = head1;
	struct node* current2 = head2;
	
	for(i = 0; i < d; i++)
	{
		if(current1 == NULL)
		{return -1;}
		current1 = current1->next;
	}

	while(current1 != NULL && current2 != NULL)
	{
		if(current1 == current2)
			return current->data;
		current1 = current1->next;
		current2 = current2->next;
	}
	return -1;
	
}

/*
* Takes head pointer of the linked list and returns the count of nodes in the list
*/
int getCount(struct node* head)
{
	struct node* current = head;
	int count = 0;

	while(current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

/*
* main to test the above code!!!, work on test later on
*/
int main()
{
	struct node* newNode;
	struct node* head1 = (struct node*) malloc(sizeof(struct node));
	head1->data = 10;

	struct node* head2 = (struct node*) malloc(sizeof(struct node));
	head2->data = 3;
	
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = 6;
	head2->next = newNode;

	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = 15;
	head2->next->next->next = newNode;

	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = 30;
	head2->next->next->next->next = newNode;

		
}
