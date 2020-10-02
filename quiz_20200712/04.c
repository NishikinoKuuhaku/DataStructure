#include<stdlib.h>
#include<stdio.h>

typedef struct LinkedList
{
    /* data */
    char data;
    struct LinkedList *next;
}LinkedList;

LinkedList *createNode(char data)
{
    LinkedList *node;
    node = (LinkedList *)malloc(sizeof(LinkedList));
    node->data = data;
    node->next = NULL;
    return node;
}

LinkedList *createLinkedList(char datas[], int size)
{
    LinkedList *head = createNode(datas[0]);
    LinkedList *prev = head;
    for (size_t i = 1; i < size; i++)
    {
        LinkedList *node = createNode(datas[i]);
        prev->next = node;
        prev = node;
    }
    return head;
}

void delet(BiLinkedList *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}

void insert(BiLinkedList *prev, BiLinkedList *node)
{
    node->prev = prev;
    node->next = prev->next;
    node->prev->next = node;
    node->next->prev = node;
}

int main(int argc, char const *argv[])
{
    return 0;
}