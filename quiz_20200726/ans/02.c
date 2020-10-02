#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int val;
    struct LinkedList *next;
}LL;

LL *createnode(int data)
{
    LL *node = (LL *)malloc(sizeof(LL));
    node->val = data;
    node->next = NULL;
    return node;
}

LL *createLinkList(int data[],int size)
{
    LL *head = createnode(data[0]);
    LL *prev = head;
    for (size_t i = 1; i < size; i++)
    {
        /* code */
        LL *node = createnode(data[i]);
        prev->next = node;
        prev = node;
    }
    return head;
}

LL *revLinkedList(LL *head)
{
    LL *newhead = NULL;
    LL *node;
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

int main(int argc, char const *argv[])
{
    int datas[5] = {1, 2, 3, 4, 5};
    LL *head = createLinkList(datas,5);
    LL *node = revLinkedList(head);
    while (node != NULL)
    {
        /* code */
        printf("%d ", node->val);
        node = node->next;
    }

    return 0;
}
