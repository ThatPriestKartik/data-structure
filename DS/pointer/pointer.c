#include <stdio.h>
void traverse(int *ptr,int n)
{
    for(int i=0;i<=n-1;i++)
        printf("%d\t",*(ptr+i));
}
/*****************************************/
int main(){
    int i;
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    int *ptr;
    ptr=&A[0];
    for(int i=0;i<=9;i++)
        printf("%d\t",A[i]);
        printf("\n");
        for(int i=0;i<=9;i++)
            printf("%d\t",*(ptr+i));
            printf("\n");
                for(int i=0;i<=9;i++)
                    printf("%d\t",*(A+i));
                    printf("\n");
                    printf(".......................................");
                     printf("\n");
            traverse(A,10);
    return 0;

}