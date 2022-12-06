#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 1
struct node{
    int info;
    struct node *next;
};


struct node* getnode(){
    struct node*p;
    p= (struct node*)malloc(sizeof(struct node));
    return p;
}


void traverse(struct node *start){
    struct node*p;
    p=start;
    while(p!=NULL){
        printf("%d ", p->info);
        p=p->next;
    }
}


void insertbeggining(struct node**start,int x){
    struct node*p;
    p=getnode();
    p->info=x;
    p->next=*start;
    *start=p;
}


void insertend(struct node**start,int x){
    struct node*p,*q;
    q=*start;
    if(q==NULL){
        insertbeggining(start,x);
    }

    else{
        while(q->next!=NULL){
        q=q->next;
    }
    p=getnode();
    p->info=x;
    p->next=NULL;
    q->next=p;
    }
    
}


void insertafter(struct node **q, int x){
    struct node *p,*r;
    p=getnode();
    p->info=x;
    r=(*q)->next;  
    p->next=r;    
    (*q)->next=p;
}


void orderedinsertion(struct node** start, int x){
    struct node *p, *q;
    p=(*start);
    q=NULL;
    while(p!=NULL && x>=p->info){
        q=p;
        p=p->next;
    }
    if (q==NULL){
        insertbeggining(start,x);
    }
    else{
        insertafter(&q,x);
    }
}


void mergeLL(struct node**start1, struct node**start2){
    struct node*p,*q;
    struct node *start3;
    p=*start1;
    q=*start2;
    start3=NULL;
    while(p!=NULL && q!=NULL){
        if((p->info)<(q->info)){
            insertend(&start3, p->info);
            p=p->next;
        }
        else{
            insertend(&start3, q->info);
            q=q->next;
        }

    }
    while(p!=NULL){
        insertend(&start3, p->info);
        p=p->next;
    }
    while(q!=NULL){
        insertend(&start3, q->info);
        q=q->next;
    }
    traverse(start3);
}


void unionLL(struct node**start1, struct node**start2){
    struct node*p,*q;
    struct node *start3;
    p=*start1;
    q=*start2;
    start3=NULL;
    while(p!=NULL && q!=NULL){
        if((p->info)<(q->info)){
            insertend(&start3, p->info);
            p=p->next;
        }

        else if((p->info)>(q->info)){
            insertend(&start3, q->info);
            q=q->next;
        }
        else{
            insertend(&start3, q->info);
            p=p->next;
            q=q->next;
        }

    }
    while(p!=NULL){
        insertend(&start3, p->info);
        p=p->next;
    }
    while(q!=NULL){
        insertend(&start3, q->info);
        q=q->next;
    }
    traverse(start3);
}


void intersectLL(struct node**start1, struct node**start2){
    struct node*p,*q;
    struct node *start3;
    p=*start1;
    q=*start2;
    start3=NULL;
    while(p!=NULL && q!=NULL){
        if((p->info)<(q->info)){
            p=p->next;
        }

        else if((p->info)>(q->info)){
            q=q->next;
        }
        else{
            insertend(&start3, q->info);
            p=p->next;
            q=q->next;
        }

    }
    traverse(start3);
}


int main(){
    struct node *start1,*start2;
    start1 = NULL;
    start2 = NULL;
    
    struct node*p,*q;

    int a[5]={10,5,2,15,17};
    int b[7]={12,5,3,6,2,8,11};
    
    for(int i=0; i<=4; i++){
        orderedinsertion(&start1, a[i]);
    }
    for(int i=0; i<=6; i++){
        orderedinsertion(&start2, b[i]);
    }
    printf("\nL1: ");
    traverse(start1);
    printf("\nL2: ");
    traverse(start2);
    printf("\nMerged: ");
    mergeLL(&start1, &start2);
    printf("\nUnion: ");
    unionLL(&start1, &start2);
    printf("\nIntersection: ");
    intersectLL(&start1, &start2);
}