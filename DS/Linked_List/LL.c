#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
/*******************/
struct node *start;
/**************************/
struct node *getnode(){
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
/*****************/
int insertbegin(int x){
    struct node*p;
    p=getnode();
    p->info=x;
    p->next=start;
    start=p;
}
/***********/
int traverse()
{
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n");
}
/****************/
int insertend(int x)
{
    struct node *q,*p;
    q=start;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    p=getnode();
    p->info=x;
    p->next=NULL;
    q->next=p;

}
/*****************/
int count(){
    int flag=0;
    struct node *p;
    p=start;
    while(p!=NULL){
        flag++;
        p=p->next;
    }
    printf("no. of nodes: %d \n",flag);
}
/*************************************/
int countevenodd()
{
    int flag1=0,flag2=0;
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        if(p->info%2==0)
        {
            flag1++;
        }
        else
        {
            flag2++;
        }
        p=p->next;
    }
    printf("no. of even : %d \n",flag1);
    printf("no. of odd : %d \n",flag2);
}
    
/*************************************/
int main(){
    start=NULL;
     insertbegin(10);
     insertbegin(11);
     insertbegin(12);
     insertbegin(13);
     insertbegin(14);
     insertbegin(15);
     insertbegin(16);
     insertbegin(17);
     insertbegin(18);
     traverse();
     insertend(0);
     insertend(3);
     insertend(4);
     insertend(5);
     traverse();
     count();
     countevenodd();
}