#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int data;
    struct _node *left;
    struct _node *right;
} Node;

Node *makeBTreeNode(){ //pointer로 반환해야 돼서 함수에 *(askrepter)붙임
    Node *nd = (Node*)malloc(sizeof(Node));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

void setData(Node *nd, int data){
    nd->data = data;
}

int getData(Node *nd){
    return nd->data;
}

Node *GetLeftSubTree(Node *nd){
    return nd->left;
}

Node *GetRightSubTree(Node *nd){
    return nd->right;
}

void makeLeftSubTree(Node *pnd, Node *cnd){
    if(pnd->left != NULL)
        free(pnd->left);
    pnd->left = cnd;
}

void makeRightSubTree(Node *pnd, Node *cnd){
    if(pnd->right != NULL)
        free(pnd->right);
    pnd->right = cnd;
}

int main(){
    Node *nd1 = makeBTreeNode();
    Node *nd2 = makeBTreeNode();
    Node *nd3 = makeBTreeNode();
    Node *nd4 = makeBTreeNode();
    setData(nd1, 1);
    setData(nd2, 2);
    setData(nd3, 3);
    setData(nd4, 4);
    makeLeftSubTree(nd1, nd2);
    makeRightSubTree(nd1, nd3);
    makeLeftSubTree(nd2, nd4);
    printf("%d ", getData(GetLeftSubTree(nd1)));
    printf("%d ", getData(GetLeftSubTree(GetLeftSubTree(nd1))));
}