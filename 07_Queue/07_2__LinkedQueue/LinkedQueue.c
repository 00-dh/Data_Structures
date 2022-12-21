#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int data;
    struct _node *next;
} Node;

typedef struct _linkedQueue{
    Node *front;
    Node *rear;
} LinkedQueue;

typedef LinkedQueue LQueue;

void QueueInit(LQueue *pq){
    pq->front = NULL;
    pq->rear = NULL;
}

int IsEmpty(LQueue *pq){
    if(pq->front == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void Enqueue(LQueue *pq, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    if(pq->front == NULL){
        pq->front = newNode;
        pq->rear = newNode;
    }
    else{
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

int Dequeue(LQueue *pq){
    if(IsEmpty(pq)){
        return -1; //error
    }
    Node *rnode;
    int rdata;
    rnode = pq->front;
    rdata = pq->front->data;
    pq->front = pq->front->next;
    free(rnode);
    return rdata;
}

int main(){
    LQueue lq;
    QueueInit(&lq);
    Enqueue(&lq, 1);
    Enqueue(&lq, 2);
    Enqueue(&lq, 3);
    Enqueue(&lq, 4);
    Enqueue(&lq, 5);
    while(!IsEmpty(&lq)){
        printf("%d ", Dequeue(&lq));
    }
}