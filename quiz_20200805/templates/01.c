#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}LL;

LL *newNode(int data)
{
	LL *p;
	p = (LL *)malloc(sizeof(LL));
	p->val = data;
	p->next = NULL;
	return p;
}

void printHexValueOfLinkedList(LL *head)
{
	/*Your Code Here*/
}

int main(int argc, char const *argv[])
{
	int data[] = {1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	int len = 15;

	LL *head, *p;
	head = newNode(data[0]);
	p = head;
	for (size_t i = 1; i < len; i++)
	{
		p->next = newNode(data[i]);
		p = p->next;
	}

	printHexValueOfLinkedLis(head);	// print “49c0”

	return 0;
}
