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
    q.data = (QUEUE_ELEMENT_TYPE *)malloc(sizeof(QUEUE_ELEMENT_TYPE) * maxsize);
    q.maxsize = maxsize;
    q.size = 0;
    q.rear = 0;
    return q;
}

int isEmpty(Queue *q)
{
    return (q->size == 0) ? 1 : 0;
}

int isFull(Queue *q)
{
    return (q->size == q->maxsize) ? 1 : 0;
}

void inQueue(Queue *q, QUEUE_ELEMENT_TYPE elem)
{
    if (isFull(q))
    {
        printf("error: queue is full\n");
    }
    else
    {
        q->data[q->rear] = elem;
        q->rear++;
        q->rear %= q->maxsize;
        q->size++;
    }
}

QUEUE_ELEMENT_TYPE outQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("error: queue is empty\n");
        return (QUEUE_ELEMENT_TYPE)0;
    }
    else
    {
        int idx = (q->rear - q->size + q->maxsize) % q->maxsize;
        QUEUE_ELEMENT_TYPE elem = q->data[idx];
        q->size--;
        return elem;
    }
}

int main(int argc, char const *argv[])
{
    Queue q = createQueue(3);

    inQueue(&q, 0);
    inQueue(&q, 1);
    inQueue(&q, 2);

    inQueue(&q, 999); // print error

    printf("%d\n", outQueue(&q));
    printf("%d\n", outQueue(&q));
    printf("%d\n", outQueue(&q));

    printf("%d\n", outQueue(&q)); // print error

    inQueue(&q, 9);
    inQueue(&q, 8);
    printf("%d\n", outQueue(&q));
    printf("%d\n", outQueue(&q));
    inQueue(&q, 7);
    inQueue(&q, 6);
    printf("%d\n", outQueue(&q));
    printf("%d\n", outQueue(&q));

    return 0;
}
