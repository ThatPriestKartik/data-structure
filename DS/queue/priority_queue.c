#include<stdio.h>
#include"Queue.h"


void arrinsertion(int *a,int n,int i,int x){
    for(int j=n-1; j>=i; j--){
        a[j+1]=a[j];
    }
    a[i]=x;
    n+=1;
}
void PQinsertion( int *a, int n, int x)
{
    int i=0;
    while(i<n && x>=a[i]){
        i++;
    }
    arrinsertion(int *a,n,i,x);
}

int PQdeletion(int *a,int n){
    int x = a[n-1];
    n-=1;
    printf("%d ",x);
}

int main(){
struct Queue q;
initialise(&q);
int n;
scanf("%d",&n);
int a[n];
PQinsertion(a,1,7);
PQinsertion(a,2,6);

PQinsertion(a,1,3);

PQinsertion(a,1,1);

PQinsertion(a,1,1);
PQinsertion(a,1,2);
PQinsertion(a,1,1);

PQinsertion(a,1,7);
PQinsertion(a,1,6);
PQinsertion(a,1,3);
PQinsertion(a,1,5);

PQdeletion(a,1);
PQdeletion(a,2);
PQdeletion(a,3);


return 0;
}