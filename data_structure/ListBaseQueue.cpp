#include "ListBaseQueue.hpp"
#include <stdlib.h>

void QueueInit(Queue *pq){
    pq->front = NULL;
    pq->rear = NULL;
}

bool QIsEmpty(Queue *pq){
    if(pq->front == NULL){
        return true;
    }
    else{
        return false;
    }
}

void Enqueue(Queue *pq, Data data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(QIsEmpty(pq)){ //첫번째 노드를 추가하는 경우 -> rear, front 포인터에 newNode 할당
        pq->front = newNode;
    }
    else{ //두번째 이상의 노드를 추가하는 경우 -> rear 포인터에만 newNode 할당
        pq->rear->next = newNode;
    }
    pq->rear = newNode;
    return;
}

Data Dequeue(Queue *pq){
    if(QIsEmpty(pq)){
        printf("Queue Is Already Empty.");
        return 0;
    }
    else{ // front를 에 할당된 노드 메모리를 힙에서 지워주고, front 포인터를 다음 노드로 바꿔주기
        Node *RNode = pq->front;
        Data RData = RNode->data;
        pq->front = pq->front->next;
        free(RNode);
        return RData;
    }
}

Data QPeek(Queue *pq){
    if(QIsEmpty(pq)){
        printf("Queue Is Already Empty.");
        return 0;
    }
    else{
        return pq->front->data;
    }
}