#include "LinkedList.c"

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

// 注意：插入在头部和尾部都不一样，不能用上述插入在中间的写法

int main(int argc, char const *argv[])
{
    BiLinkedList *bll_head = createBiLinkedList(5);

    BiLinkedList *node1 = bll_head->next;
    BiLinkedList *node3 = bll_head->next->next->next;

    BiLinkedList *newnode = (BiLinkedList *)malloc(sizeof(BiLinkedList));
    newnode->data = 1000;
    newnode->prev = NULL;
    newnode->next = NULL;

    delet(node3);
    insert(node1, newnode);


    return 0;
}