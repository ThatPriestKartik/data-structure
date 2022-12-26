#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node* MakeNode(char x){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void PreorderTraversal(struct Node *T){
    if(T!=NULL){
        printf("%d ",T->data);
        PreorderTraversal(T->left);
        PreorderTraversal(T->right);
    }
}



void BSTInsert(struct Node **T,int x){
    struct Node *p,*q;
    q=NULL;
    p=(*T);
    while(p!=NULL){
        q=p;
        if(x < p->data){
             p=p->left;
        }
        else{
            p=p->right;
        }
    }
    if(x < q->data){
        q->left = MakeNode(x);
    }
    else
    {
        q->right = MakeNode(x);
    }
}
void inorderTraversal(struct Node *T){
    if(T!=NULL){
        inorderTraversal(T->left);
        printf("%d    ",T->data);
        inorderTraversal(T->right);
    }
}


int main(){
    struct Node *root;
    root=NULL;
    root=MakeNode(100);
    BSTInsert(&root,10);
    BSTInsert(&root,40);
    BSTInsert(&root,80);
    BSTInsert(&root,50);
    BSTInsert(&root,120);
    BSTInsert(&root,20);
    inorderTraversal(root);
    return 0;
}