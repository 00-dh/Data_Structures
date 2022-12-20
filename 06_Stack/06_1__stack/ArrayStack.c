#include<stdio.h>
#define LIST_LEN 100

typedef int Data;
typedef struct _arrayStack{
    Data stackArr[LIST_LEN];
    int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack *pstack){
    pstack->topIndex = -1;
}

int IsEmpty(Stack *pstack){
    if(pstack->topIndex == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void SPush(Stack *pstack, Data data){
    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

int SPop(Stack *pstack){
    if(IsEmpty(pstack)){
        printf("Stack Memory Error!");
        return -1;
    }
    int rIdx = pstack->topIndex;
    pstack->topIndex -= 1;
    return pstack->stackArr[rIdx];
}

int SPeek(Stack *pstack){
    if(IsEmpty(pstack)){
        printf("Stack Memory Error!");
        return -1;
    }
    return pstack->stackArr[pstack->topIndex];
}

int main(){
    Stack stack;
    StackInit(&stack);
    SPush(&stack, 1);
    SPush(&stack, 2);
    SPush(&stack, 3);
    SPush(&stack, 4);
    SPush(&stack, 5);
    while(!IsEmpty(&stack)){
        printf("%d ", SPop(&stack));
    }
}