#ifndef CircularQueue_hpp
#define CircularQueue_hpp

#include <stdio.h>
#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue
{
    int front;
    int rear;
    Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue *pq);
bool QIsEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);

#endif /* CircularQueue_hpp */