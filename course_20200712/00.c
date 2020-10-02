#include <stdlib.h>
#include <stdio.h>


typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
} LinkedList;


LinkedList *createNode(int data)
{
    LinkedList *node;
    node = (LinkedList *)malloc(sizeof(LinkedList));
    node->data = data;
    node->next = NULL;
    return node;
}

// size >= 1
LinkedList *createLinkedList(int datas[], int size)
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



int main(int argc, char const *argv[])
{
    int datas[5] = {1,2,3,4,5};
    LinkedList *head = createLinkedList(datas, 5);


    printf("1111");
    printf("1111");

    NULL;

    return 0;
}
