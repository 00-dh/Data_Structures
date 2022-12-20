#include<stdio.h>
#include<stdlib.h>

typedef int LData;
typedef struct _node{
    int data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _douvlyLinkedList{
    Node *head;
    Node *cur;
    int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List *plist){
    plist->head = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, LData data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
   newNode->next = plist->head;
   if(newNode->next != NULL){
    plist->head->prev = newNode;
   }
    newNode->prev = NULL;
    plist->head = newNode;

    plist->numOfData++;
}

int LFirst(List *plist, LData *pdata){
    if(plist->head == NULL){
        return 0;
    }
    plist->cur = plist->head;
    *pdata = plist->cur->data;
    return 1;
}

int LNext(List *plist, LData *pdata){
    if(plist->cur->next == NULL){
        return 0;
    }
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return 1;
}

int LPrevious(List *plist, LData *pdata){
    if(plist->cur->prev == NULL){
        return 0;
    }
    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    return 1;
}

int main(){
    List list;
    int data;
    ListInit(&list);
    LInsert(&list, 3);
    LInsert(&list, 2);
    LInsert(&list, 1);
    if(LFirst(&list, &data)){
        printf("%d ", data);
    }
    while(LNext(&list, &data)){
        printf("%d ", data);
    }
    while (LPrevious(&list, &data)){
        printf("%d ", data);
    }
    
}