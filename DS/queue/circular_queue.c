#include<stdio.h>
#include<stdlib.h>
#define queuesize 10
#define TRUE 1
#define FALSE 0
struct Queue {
    int item[queuesize];
    int front;
    int rear;
};

struct Queue q;

void initialize(struct Queue *q){
    q->front =0;
    q->rear=-1;
}
void enque(struct Queue *q,char x){
    if ((q.rear+1)%size){
        printf("queue Overflow");
        exit(1);
    }
    else{
        q->rear=q->rear+1;
        q->item[q->rear]=x;
    }

}
int IsEmpty(struct Queue *q){
    if (q->rear- q->front +1==0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
char deque(struct Queue *q){
    if(IsEmpty(q)){
        printf("queue Underflow");
        exit(1);
    }
    else{
        char x=q->item[q->front];
        q->front=q->front+1;
        return x;
    }
}

int main(){
    struct Queue myq;
    initialize(&myq);
    enque(&myq, 'a');
    enque(&myq, 'b');
    enque(&myq, 'c');
    enque(&myq, 'd');

    char y= deque(&myq);
    printf("deleted elem is %c\n", y);
    return 0;
}