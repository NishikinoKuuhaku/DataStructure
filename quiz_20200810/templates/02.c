#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int val;
	struct ListNode *next;
} LL;

LL *newNode(int data)
{
	LL *p;
	p = (LL *)malloc(sizeof(LL));
	p->val = data;
	p->next = NULL;
	return p;
}

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};

int isLinkedListValid(LL *head)
{
}

int main(int argc, char const *argv[])
{
	int data[] = {51, 1, 2, 3, 4};
	int len = 5;

	LL *head, *p;
	head = newNode(data[0]);
	p = head;
	for (size_t i = 1; i < len; i++)
	{
		p->next = newNode(data[i]);
		p = p->next;
	}

	printf("%d", isLinkedListValid(head)); // print 1

	return 0;
}
