#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int data;
    struct _node *next;
} Node;

typedef struct _linkedStack{
    Node *head;
} LinkedStack;
typedef LinkedStack List;

void StackInit(List *plist){
    plist->head = NULL;
}

int SIsempty(List *plist){
    if(plist->head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void SPush(List *plist, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = plist->head;
    plist->head = newNode;
}

int SPop(List *plist){
    if(SIsempty(plist)){
        printf("Stack Memory Error!");
        return -1;
    }

    int rdata = plist->head->data;
    Node *rnode = plist->head;
    plist->head = plist->head->next;
    free(rnode);
    return rdata;
}

int SPeek(List *plist){
    return plist->head->data;
}

int main(){
    List list;
    StackInit(&list);
    SPush(&list, 1);
    SPush(&list, 2);
    SPush(&list, 3);
    SPush(&list, 4);
    SPush(&list, 5);
    while(!SIsempty(&list)){
        printf("%d ", SPop(&list));
    }
}