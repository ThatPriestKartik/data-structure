#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;  
};
/*******************/
struct node *start1;
struct node *start2;
/**************************/
struct node *getnode(){
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
/*****************/
int insertbegin1(int x){
    struct node*p;
    p=getnode();
    p->info=x;
    p->next=start1;
    start1=p;
}
/*****************/
int insertbegin2(int x){
    struct node*p;
    p=getnode();
    p->info=x;
    p->next=start2;
    start2=p;
}
/***********/
int traverse1()
{
    struct node *p;
    p=start1;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n");
}
/****************/
int traverse2()
{
    struct node *p;
    p=start2;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n");
}


/*************************************/
int concatenate(struct node *start1, struct node *start2){
    struct node *p;
    p= start1;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next= start2;
    p= start1;
    traverse1();
    
}
/*************************************/

int main(){

    start1=NULL;
    int p;
     insertbegin1(10);
     insertbegin1(11);
     insertbegin1(12);
     insertbegin1(13);
     insertbegin1(14);
     insertbegin1(15);
     insertbegin1(16);
     insertbegin1(17);
     insertbegin1(18);
     traverse1();
     printf("\n****************************************\n\n");
     start2=NULL;
     insertbegin2(1);
     insertbegin2(2);
     insertbegin2(3);
     insertbegin2(4);
     insertbegin2(5);
     traverse2();
     printf("\n****************************************\n");
     concatenate(start1,start2);
     
     
}