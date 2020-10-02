#include "LinkedList.c"


LinkedList *findByIndex(int index, LinkedList *head)
{
    LinkedList *node = head;
    int idx = 0;
    while (node != NULL)
    {
        if (idx == index)
        {
            printf("find %d", node->data);
            return node;
        }
        node = node->next;
        idx++;
    }
    printf("index out of range");
    return NULL;
}

LinkedList *findByValue(int value, LinkedList *head)
{
    LinkedList *node = head;
    int idx = 0;
    while (node != NULL)
    {
        if (value == node->data)
        {
            printf("find at %d", idx);
            return node;
        }
        node = node->next;
        idx++;
    }
    printf("value not in linked list");
    return NULL;
}


void insert(LinkedList *prev, LinkedList *newnode)
{
    newnode->next = prev->next;
    prev->next = newnode;
}

LinkedList *insertHead(LinkedList *head, LinkedList *newnode)
{
    newnode->next = head;
    return newnode;
}


LinkedList *insertByIndex(LinkedList* head, LinkedList *node, int idx)
{
    if (idx == 0)
    {
        return insertHead(head, node);
    }
    else
    {
        LinkedList *prev = findByIndex(idx-1, head);
        if (prev != NULL)
        {
            insert(prev, node);
            return head;
        }
        printf("invalid index");
        return head;
    }
}

void delet(LinkedList *prev)
{
    LinkedList *curr = prev->next;
    prev->next = prev->next->next;
    free(curr);
}

LinkedList *deletHead(LinkedList *head)
{
    LinkedList *newhead = head->next;
    free(head);
    return newhead;
}


LinkedList *deletByIndex(LinkedList* head, int idx)
{
    if (idx == 0)
    {
        return deletHead(head);
    }
    else
    {
        LinkedList *prev = findByIndex(idx-1, head);
        if (prev != NULL)
        {
            delet(prev);
            return head;
        }
        printf("invalid index");
        return head;
    }
}


LinkedList *createCircularLinkedList(int data[], int size)
{
    LinkedList *head = createLLNode(data[0]);

    // method 1
    // head->next = head;

    LinkedList *curr = head;
    for (size_t i = 1; i < size; i++)
    {
        LinkedList *node = createLLNode(data[i]);
        insert(curr, node);
        curr = node;
    }

    // method 2
    curr->next = head;

    return head;
}




int main(int argc, char const *argv[])
{
    LinkedList *ll_head = createLinkedList(5);

    // LinkedList *node;
    // int idx;
    // printf("node %d is %d\n",idx, node->data);

    // printf("node %d is %d\n", 1, ll_head->data);
    // printf("node %d is %d\n", 2, ll_head->next->data);
    // printf("node %d is %d\n", 3, ll_head->next->next->data);
    // printf("node %d is %d\n", 4, ll_head->next->next->next->data);

    // 上一个是      某某节点->data
    // 下一个就是    [某某节点->next]->data
    // 再下一个是    [[某某节点->next]->next]->data

    // 遍历
    // LinkedList *node = ll_head;
    // int idx = 0;
    // while (node != NULL)
    // {
    //     printf("node %d is %d\n",idx, node->data);
    //     node = node->next;
    //     idx++;
    // }
    // for (; node != NULL; node=node->next, idx++)
    // {
    //     printf("node %d is %d\n",idx, node->data);
    // }

    // findByIndex(1000, ll_head);
    findByValue(100, ll_head);




    return 0;
}