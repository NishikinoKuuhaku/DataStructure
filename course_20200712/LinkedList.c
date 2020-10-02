#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
}LinkedList;

typedef struct BidirectionalLinkedList
{
    int data;
    struct BidirectionalLinkedList *prev, *next;
}BiLinkedList;

LinkedList *createLLNode(int data)
{
    LinkedList *node;
    node = (LinkedList *)calloc(1, sizeof(LinkedList));
    node->data = data;
    return node;
}

BiLinkedList *createBLLNode(int data)
{
    BiLinkedList *node;
    node = (BiLinkedList *)calloc(1, sizeof(BiLinkedList));
    node->data = data;
    return node;
}

LinkedList *createLinkedList(int size)
{
    if (size == 0)
    {
        return NULL;
    }
    else
    {
        LinkedList *head = (LinkedList *)calloc(1, sizeof(LinkedList));
        head->data = 1;
        LinkedList *curr = head;
        for (size_t i = 1; i < size; i++)
        {
            LinkedList *newNode = (LinkedList *)calloc(1, sizeof(LinkedList));
            newNode->data = i + 1;
            curr->next = newNode;
            curr = newNode;
        }   
        return head;
    }
}

BiLinkedList *createBiLinkedList(int size)
{
    if (size == 0)
    {
        return NULL;
    }
    else
    {
        BiLinkedList *head = (BiLinkedList *)calloc(1, sizeof(BiLinkedList));
        head->data = 1;
        BiLinkedList *curr = head;
        for (size_t i = 1; i < size; i++)
        {
            BiLinkedList *newNode = (BiLinkedList *)calloc(1, sizeof(BiLinkedList));
            newNode->data = i + 1;
            newNode->prev = curr;
            curr->next = newNode;
            curr = newNode;
        }   
        return head;
    }
}