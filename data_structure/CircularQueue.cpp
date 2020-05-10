#include "CircularQueue.hpp"


void QueueInit(Queue *pq){
    pq->front = 0;
    pq->rear = 0;
}
bool QIsEmpty(Queue *pq){
    if(pq->front == pq->rear){
        return true;
    }
    else return false;
}

int NextPosIdx(int pos){
    if(pos == QUE_LEN-1){
        return 0;
    }
    else{
        return pos + 1;
    }
}

void Enqueue(Queue *pq, Data data){
    //꽉찬 경우(f == r의 다음)인 경우,
    int next_rear = NextPosIdx(pq->rear);
    if(next_rear == pq->front){
        printf("Queue is Already Full.");
        return;
    }
    else{
        pq->queArr[next_rear] = data;
        pq->rear = next_rear;
    }
    return;
}

Data Dequeue(Queue *pq){
    //비어있는 경우
    if(QIsEmpty(pq)){
        printf("Queue is Already Empty.");
        return 0;
    }
    else{
        pq->front = NextPosIdx(pq->front);
        Data RData = pq->queArr[pq->front];
        return RData;
    }
}

Data QPeek(Queue *pq){
    if(QIsEmpty(pq)){
        printf("Queue is Already Empty.");
        return 0;
    }
    else{
        Data PData = pq->queArr[pq->front];
        return PData;
    }
}

int main (){
    Queue q;
    QueueInit(&q);
    
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);
    
    while(!QIsEmpty(&q)){
        printf("%d ", Dequeue(&q));
    }
    printf("\n");
    Queue *q2;
    q2 = (Queue*)malloc(sizeof(Queue));
    Enqueue(q2, 1);
    Enqueue(q2, 3);
    Enqueue(q2, 5);
    Enqueue(q2, 7);
    Enqueue(q2, 9);
    
    while(!QIsEmpty(q2)){
        printf("%d ", Dequeue(q2));
    }
    
    return 0;
}