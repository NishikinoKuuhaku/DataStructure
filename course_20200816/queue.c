#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 3
int pos = 0;
typedef struct queue
{
    int size;
    int front;
    int elements[MAX_QUEUE_SIZE] = {0};
} Queue;

void in_queue(Queue *q, int elem)
{
    if (q->size >= MAX_QUEUE_SIZE)
    {
        printf("错误！尝试向满的队列中存放元素！");
    }
    else
    {
`       pos = (q->size + q->front) % MAX_QUEUE_SIZE;
        q->elements[pos] = elem;
        q->size++;
    }
}

int out_queue(Queue *q)
{
    if (q->size == 0)
    {
        printf("错误！尝试从空的队列中取出元素！");
    }
    else
    {
        q->size--;
        int tmp = q->elements[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        return tmp;
    }
}

int main()
{
    Queue q;
    q.size = 0;

    in_queue(&q, 1);
    in_queue(&q, 2);
    in_queue(&q, 3);

    printf("%d\n",out_queue(&q));
    printf("%d\n",out_queue(&q));

    in_queue(&q, 1);
    in_queue(&q, 2);

    printf("%d\n",out_queue(&q));
    printf("%d\n",out_queue(&q));
}

/*


(front + MAX) % MAX == front % MAX == front


front: 0 ~ MAX - 1
size: 0 ~ MAX
*/