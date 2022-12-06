#include <stdio.h>
#include <stdlib.h>
int main(){
    int m;
    scanf("%d",&m);
    int *p;
    p=(int*)malloc((4*m));
    for(int i=0;i<m;i++)
    scanf("%d",(p+i));
    for(int i=0;i<m;i++)
    printf("%d ",*(p+i));
    return 0; 
}