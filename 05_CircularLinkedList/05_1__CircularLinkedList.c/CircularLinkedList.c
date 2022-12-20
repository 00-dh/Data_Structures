#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

typedef int LData;
typedef struct _node{
    int data;
    struct _node *next;
} Node;

typedef struct _CircularLinkedList{
    Node *tail;
    Node *cur;
    Node *before;
    int numOfData;
} CList;

typedef CList List;

void ListInit(List *plist){
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, LData data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(plist->tail == NULL){
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else{
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }
    plist->numOfData++;
}

int LFirst(List *plist, LData *pdata){
    if(plist->tail == NULL){
        return false;
    }
    plist->cur = plist->tail->next;
    plist->before = plist->tail;

    *pdata = plist->cur->data;
    return true;
}

int LNext(List *plist, LData *pdata){
    if(plist->tail->next == NULL){
        return false;
    }
    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return true;
}

LData LRemove(List *plist){
    Node *rpos = plist->cur;
    int rdata = rpos->data;
    
    if(rpos == plist->tail){
        if(plist->tail->next == plist->tail){
            plist->tail = NULL;
        }
        else{
            plist->tail = plist->before;
        }
    }
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    free(rpos);
    plist->numOfData--;
    return rdata;
}

int LCount(List *plist){
    return plist->numOfData;
}

int main(){
    List list;
    int data;
    ListInit(&list);
    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    if(LFirst(&list, &data)){
        printf("%d ", data);
    }
    for(int i = 0; i< LCount(&list)-1; i++){
        if(LNext(&list, &data)){
            printf("%d ", data);
        }
    }
}