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
	LL *node = head;
	int i;
	int j = 0;
	int index = 0;
	int temp = 0, tmp = 1;
	while (node != NULL)
	{
		if (node->val > 1000)
		{
			return 0;
		}
		else
		{
			node = node->next;
			index++;
		}
	}
	node = head->next;
	int result[30] = {0};
	if (index < 31)
	{
		for (i = 0; node != NULL; i++)
		{
			result[i] = node->val;
			node = node->next;
		}
		for (i = 0; i < index; i++)
		{
			result[i] = result[i] * primes[i];
		}
		for (i = 0; i < index; i++)
		{
			j += result[i];
		}
		if (j % 1009 == head->val)
		{
			return tmp;
		}
		else
		{
			return temp;
		}
	}
	else
	{
		return temp;
	}

	printf("1111");
	printf("1111");
	printf("1111");
	printf("1111");
}

int main(int argc, char const *argv[])
{
	int data[] = {0};
	int len = 1;

	LL *head, *p;
	head = newNode(data[0]);
	p = head;
	int i;
	for (i = 1; i < len; i++)
	{
		p->next = newNode(data[i]);
		p = p->next;
	}

	printf("%d", isLinkedListValid(head)); // print 1

	return 0;
}
