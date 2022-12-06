#include <stdio.h>
#include <stdlib.h>
int main(){
    int *p;
    p=(int*)malloc(40);
    for(int i=0;i<=9;i++)
    scanf("%d",(p+i));
    for(int i=0;i<=9;i++)
    printf("%d ",*(p+i));
    printf("..............");
    printf("\n");
    printf("%d",sizeof(int));
    printf("\n");
    printf("%d",sizeof(float));
    printf("\n");
    printf("%d",sizeof(long));
    printf("\n");
    printf("%d",sizeof(long long));
    printf("\n");
    return 0; 
}