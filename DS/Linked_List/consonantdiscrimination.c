#include<stdio.h>
#include<stdlib.h>
struct node
{
    char info;
    struct node *next;  
};
/*******************/
struct node *start1;

/**************************/
struct node *getnode(){
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
/*****************/
int insertbegin1(char x){
    struct node*p;
    p=getnode();
    p->info=x;
    p->next=start1;
    start1=p;
}
/***********************/
 int DelAft(struct node **p)
 {
 int x;
 struct node *q;
 q=(*p)->next;
 (*p)->next=q->next;
 x=q->info;
 free(q);
 return x;
 }

/***********/
int insertend(struct node **start,int x)
{
    struct node *q,*p;
    q=(*start);
    if(q==NULL)
    {
        insertbegin1(x);
    }
    else
    {
        while((q->next)!= NULL)
        {
            q=q->next;
        }
        p=getnode();
        p->info=x;
        p->next=NULL;
        q->next=p;
    }
    
}
/***********************************/
int traverse1()
{
    struct node *p;
    p=start1;
    while(p!=NULL)
    {
        printf("%c ",p->info);
        p=p->next;
    }
    printf("\n");
}
void insaft(struct node **q, int x){
    struct node *p,*r;
    p=getnode();
    p->info=x;
    r=(*q)->next; //p->next=q->next;
    p->next=r; //q->next=p;
    (*q)->next=p;
}

int DelBeg(struct node **start1)
 {
 struct node *p;
 int x;
 p=(*start1);
 (*start1)=(*start1)->next;
 x=p->info;
 free(p);
 return x;
 }
/****************************************/
int convow(struct node **start1){
    struct node *p,*q,*r;
    p=NULL;
    r=NULL;
    q=*start1;
    while(q!=NULL)
    {
        if(q->info=='a'||q->info=='e'||q->info=='i'||q->info=='o'||q->info=='u'){
            q=q->next;
            if(p==NULL){
                if(r!=NULL){
                    char x=DelAft(&r);
                    insertbegin1(x);
                    p = *start1;

                }
                else
                {
                    char x = DelBeg(start1);
                    insertbegin1(x);
                    p = *start1;
                    r = p;


                }

            }
            else{
                char x = DelAft(&r);
                insaft(&p,x);
                p=p->next;
                r=p;
            }
        }
        else{
            r = q;
            q = q->next;
        }

    }
    traverse1(&start1);
    
}

/*************************************/
/*************************************/

int main(){
   struct node *start;
    start=NULL;

    char *arr;
    arr =  malloc(1024*sizeof(char));
    gets(arr);
    int i=0;
    while(arr[i]!='\0'){
        insertend(&start,arr[i]);
        i++;
    } 
    convow(&start);
}