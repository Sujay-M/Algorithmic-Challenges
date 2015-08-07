#include <stdio.h>
#include <stdlib.h>
typedef struct List
{
	int data;
	struct List *next;
}node;
node* getnode()
{
	return (node*)malloc(sizeof(node));
}
node* insertFirst(node* first,int data)
{
	node* temp = getnode();
	temp->data = data;
	temp->next = first;
	return temp;
}
node* insertLast(node *last,int data)
{
	node *temp = getnode();
	temp->data = data;
	temp->next = NULL;
	last->next = temp;
	return temp;
}
void displayList(node* temp)
{
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp = temp->next;

	}	
	printf("\n");
}
int findLength(node* temp)
{
	int count = 0;
	node* temp2 = temp;
	while(temp!=NULL)
	{
		count++;
		if(temp2->next->next!=NULL)
			temp2 = temp2->next->next;
		temp = temp->next;
		if(temp==temp2 && temp2->next->next!=NULL)
		{
			count = -1;
			break;
		}
	}

	return count;

}
int main()
{
	node *first = NULL,*last = NULL;
	int i;
	first = last = insertFirst(first,0);
	for (i = 1; i < 10; ++i)
		first = insertFirst(first,i);
	displayList(first);
	printf("len = %d",findLength(first));
	last->next = first->next;
	printf("len = %d",findLength(first));



}