//TwoSum problem of leetcode
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[100],n,t;
    int* result = (int*)malloc(2 * sizeof(int));
    printf("/n Enter n :");
    scanf("%d",&n);
    printf("/n Enter Array : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("/n Enter target : ");
    scanf("%d",&t);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==t)
            {
                result[0]=i;
                result[1]=j;
                printf("Indices are [%d,%d]",result[0],result[1]);
                free(result);
                return 0;
             
            }
        }
    }
    printf("/n No solution exists.");
    free(result);
    return 0;
}
