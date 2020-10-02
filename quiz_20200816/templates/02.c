#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
	char data;
	struct Node *next;
}Node;

typedef struct LinkStack
{
	Node *top;
}LinkStack;

Node *revLinkedStack(Node *head)
{
	Node *newhead = NULL;
    Node *node;
    while (head != NULL)
    {
        /* code */
        node = head;
        head = head->next;

        node->next = newhead;
        newhead = node;
    }
    return newhead;
}

LinkStack *createEmptyStack(void)
{
	LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
	if(stack != NULL)
	{
		stack->top = NULL;
	}
	else
	{
		printf("????\n");
	}
	return stack;
}

int isEmptyStack(LinkStack *stack)
{
	return(stack->top == NULL);
}

int *push(LinkStack *stack,char data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	if(node != NULL)
	{
		node->data = data;
		node->next = stack->top;
		stack->top = node;
	}
	else
	{
		printf("????\n");
		return 0;
	}
}

int pop(LinkStack *stack)
{
	if(isEmptyStack(stack))
	{
		printf("???\n");
		return 0;
	}
	else
	{
		Node *node;
		node = stack->top;
		stack->top = stack->top->next;
		free(node);
		return 1;
	}
}

void stringPrint(int n, int flag[], char data[])
{
	/*Your Code Here*/
	LinkStack *stack = createEmptyStack();
	int i,j = 0;
	for(i = 0;i <= n;i++)
	{
		if(flag[i] == 1)
		{
			pop(stack);
		}
		else
		{
			push(stack,data[j]);
			j++;
		}
	}
	Node *node = stack->top;
	node = revLinkedStack(node);
	while (node != NULL)
	{
		/* code */
		printf("%c", node->data);
		node = node->next;
	}
}

int main(int argc, char const *argv[])
{
	int n = 5;
	int flag[] = {0, 0, 0, 1, 0};
	char data[] = {'c', 'a', 'p', 't'};

	stringPrint(n, flag, data);

    return 0;
}