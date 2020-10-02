#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int val;
    struct LinkedList *next;
} LL;

LL *createNode(int val)
{
    LL *node = (LL *)calloc(1, sizeof(LL));
    node->val = val;
    return node;
}

LL *revLinkedList_s1(LL *head)
{
    LL *next = head;
    LL *curr = head;
    LL *prev = NULL;
    while (next != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

LL *revLinkedList_s2(LL *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    else
    {
        LL *back = revLinkedList_s2(head->next);
        head->next->next = head;
        head->next = NULL;
        return back;
    }
}

LL *revLinkedList_s0(LL *head)
{
    int values[100] = {0};
    int size = 0;
    for (; head != NULL; size++)
    {
        values[size] = head->val;
        head = head->next;
    }

    LL *newhead = createNode(values[size - 1]);
    LL *node = newhead;
    int i;
    for (i = size - 2; i >= 0; i--)
    {
        LL *newnode = createNode(values[i]);
        node->next = newnode;
        node = newnode;
    }
    return newhead;
}

int main(int argc, char const *argv[])
{

    LL *head = createNode(0);
    LL *curr = head;
    for (size_t i = 1; i < 10; i++)
    {
        curr->next = createNode(i);
        curr = curr->next;
    }

    LL *rev;
    // rev = revLinkedList_s0(head);
    // curr = rev;
    // while (curr != NULL)
    // {
    //     printf("%d\n", curr->val);
    //     curr = curr->next;
    // }

    // rev = revLinkedList_s1(head);
    // curr = rev;
    // while (curr != NULL)
    // {
    //     printf("%d\n", curr->val);
    //     curr = curr->next;
    // }

    rev = revLinkedList_s2(head);
    curr = rev;
    while (curr != NULL)
    {
        printf("%d\n", curr->val);
        curr = curr->next;
    }
    return 0;
}
