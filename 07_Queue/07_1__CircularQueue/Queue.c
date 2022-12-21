#include<stdio.h>
#define LIST_LEN 100

typedef struct _circularQueue{
    int front;
    int rear;
    int arr[LIST_LEN];
} CircularQueue;

typedef CircularQueue queue;

void QueueInit(queue *pq){
    pq->front = 0;
    pq->rear = 0;
}

int IsEmpty(queue *pq){
    if(pq->front == pq->rear){
        return 1;
    }
    else{
        return 0;
    }
}

int NextPosIdx(int pos){
    if(pos == LIST_LEN-1){
        return 0;
    }
    else{
        return pos += 1;
    }
}

void Enqueue(queue *pq, int data){
    if(NextPosIdx(pq->rear) == pq->front){
        //error
    }
    pq->rear = NextPosIdx(pq->rear);
    pq->arr[pq->rear] = data;
}

int Dequeue(queue *pq){
    if(IsEmpty(pq)){
        return -1;
    }
    pq->front = NextPosIdx(pq->front);
    return pq->arr[pq->front];
}

int QPeek(queue *pq){
    if(IsEmpty(pq)){
        return -1;
    }
    return pq->arr[NextPosIdx(pq->front)];
}

int main(){
    queue q;
    QueueInit(&q);
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);
    while(!IsEmpty(&q)){
        printf("%d ",Dequeue(&q));
    }
}