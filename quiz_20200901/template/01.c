#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUEUE_ELEMENT_TYPE int

typedef struct Queue
{
    int rear, size;
    int maxsize;
    QUEUE_ELEMENT_TYPE *data;
}Queue;

Queue createQueue(int maxsize)
{
    Queue q;
    q.maxsize = maxsize;
    q.data = (int *)malloc(sizeof(int) * maxsize);
    q.size = 0;
    q.rear = 0;
    return q;
}

int isEmpty(Queue *q)
{
    return ((q->size == 0) ? 1 : 0);
}

int isFull(Queue *q)
{
    return ((q->size == q->maxsize) ? 1 : 0);
}

void inQueue(Queue *q, QUEUE_ELEMENT_TYPE elem)
{
    if (isFull(q))
    {
        /* code */
        printf("error: queue is full\n");
    }
    else
    {
        /* code */
        q->data[q->rear] = elem;
        q->rear++;
        q->size++;
    }
}

QUEUE_ELEMENT_TYPE outQueue(Queue *q)
{
    if (isEmpty(q))
    {
        /* code */
        printf("error: queue is empty\n");
    }
    else
    {
        /* code */
        int pos = 0;
        pos = (q->size - q->rear) % q->maxsize;
        int temp = q->data[pos];
        q->size--;
        return temp;
    }
}

int main(int argc, char const *argv[])
{
    Queue q = createQueue(3);

    inQueue(&q, 0);
    inQueue(&q, 1);
    inQueue(&q, 2);
    /**
     * maxsize = 3,size = 1,rear = 1,front = 0
     * maxsize = 3,size = 2,rear = 2,front = 0
     * maxsize = 3,size = 3,rear = 3,front = 0
    */
    inQueue(&q, 999); // print error

    printf("%d\n", outQueue(&q));
    printf("%d\n", outQueue(&q));
    printf("%d\n", outQueue(&q));
    /**
     * maxsize = 3,size = 2,rear = 3,front = 1
     * maxsize = 3,size = 1,rear = 3,front = 2
     * maxsize = 3,size = 0,rear = 3,front = 3
    */

    printf("%d\n", outQueue(&q)); // print error

    inQueue(&q, 9);
    inQueue(&q, 8);
    /**
     * maxsize = 3,size = 1,rear = 0,front = 0
     * maxsize = 3,size = 2,rear = 1,front = 0
    */
    printf("%d\n", outQueue(&q));
    printf("%d\n", outQueue(&q));
    /*
    *maxsize = 3,size = 1,rear = 1
    *maxsize = 3,size = 0,rear = 0
    * */
    inQueue(&q, 7);
    inQueue(&q, 6);
    printf("%d\n", outQueue(&q));
    printf("%d\n", outQueue(&q));

    return 0;
}
