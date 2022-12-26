#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data;
    struct Node *left;
    struct Node *right;
    struct Node *H;
};
struct Node* MakeNode(char x){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->H == NULL;
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
    if(x<q->data){
        q->left = MakeNode(x);
    }
    else
    {
        q->right = MakeNode(x);
    }
}
void inorderTraversal(struct Node **T){
    if((*T)!=NULL){
        PreorderTraversal((*T)->left);
        printf("%d ",(*T)->data);
        PreorderTraversal((*T)->right);
    }
}
int leftrotation(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *z = y->left;
    y-> left = x;
    x->right = z;
    return y;
}
int rightrotation(struct Node *x)
{
    struct Node *y = x->left;
    struct Node *z = y->right;
    y-> right = x;
    x->left = z;
    return y;
}
int LL(struct Node *x){
    struct Node *y=rightrotation(x);
    return y;
}
int RR(struct Node *x){
    struct Node *y=leftrotation(x);
    return y;
}
int LR(struct Node *x){
    struct Node *y = x->left;
    struct Node *z=leftrotation(y);
    x->left=z;
    struct node *T=rightrotation(x);
    return T;
}
int RL(struct Node *x){
    struct Node *y = x->right;
    struct Node *z=rightrotation(y);
    x->right=z;
    struct node *T=leftrotation(x);
    return T;
}
int balancefactor(struct Node *T){
    int Hl,Hr;
    int H;
    if (T==NULL){
        return 0;
    }
    if (T->left == NULL){
        Hl=0;
    }
    else
    Hl = 1+T->left->H;
    if (T->right == NULL){
        Hr=0;
    }
    else
    Hr = 1+T->right->H;

    return Hl-Hr;


}
struct Node * AVLinsertion(struct Node **T,int x){
    if((*T)==NULL){
        *T=MakeNode(x);

    }
    else{
        if (x< (*T)->data)
        {
            (*T)->left=AVLinsertion((*T)->left,x);
            if (x<(*T)->left->left){
                (*T)=LL(&T);
            }
            else{
                (*T)=LR(&T);
            }

        }else
            (*T)->right=AVLinsertion((*T)->right,x);
            if (balancefactor(T)==-2){
                if()
            }

        
    }
    return (*T);
}


int main(){
    struct Node *root;
    root=NULL;
    root=MakeNode(100);
    BSTInsert(&root,30);
    BSTInsert(&root,40);
    BSTInsert(&root,10);
    BSTInsert(&root,80);
    BSTInsert(&root,100);
    BSTInsert(&root,50);
    BSTInsert(&root,120);
    BSTInsert(&root,20);
    inorderTraversal(&root);
    return 0;
}