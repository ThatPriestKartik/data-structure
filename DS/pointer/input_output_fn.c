#include <stdio.h>
#include <stdlib.h>
void input(int m,int *p){
for(int i=0;i<m;i++)
    scanf("%d",(p+i));
}
int output(int m, int *p)
{
     for(int i=0;i<m;i++)
    printf("%d ", *(p+i));
}
int main(){
    int m;
    printf("No. of elements: ");
    scanf("%d",&m);
    int *p;
    p=(int*)malloc(m*sizeof(int));
    input(m,p);
    output(m,p);
   
    return 0; 
}