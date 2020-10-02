#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct book
{
    /* data */
    char name[50][20];
    int count;
    struct book *next;
}book;
book *newNode(char name[])
{
    book *node = (book *)malloc(sizeof(book));
    strcpy(node->name,name);
    node->next = NULL;
    return node;
}
book *create(char name[],int size)
{
    book *linkedlist;
    strcpy(linkedlist->name, name);
    newNode(name);
    book *prev = linkedlist;
    for (size_t i = 1; i < size; i++)
    {
        book *node;
        newNode(strcpy(node->name, name));
        prev->next = node;
        prev = node;
    }
    return linkedlist;
}
book *search(char name[],book *head)
{

}
book insert(book *elem,book *head)
{

}
void printf(book *head)
{

}
int main(int argc, char const *argv[])
{
    int size;
    char name[50][20];
    scanf("%d\n", &size);
    for (size_t i = 0; i < size; i++)
    {
        /* code */
        scanf("%s", &name[i]);

    }
    for (size_t i = 0; i < size; i++)
    {
        /* code */
        book *head = create(name[i], size);
    }


    return 0;
}
