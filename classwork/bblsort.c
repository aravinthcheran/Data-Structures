#include<stdio.h>
#include"swap.h"
void bblsort(int *arr,int n)
{
    int numberofpasses;
    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j-1])
            {
                swap(&arr[j],&arr[j+1]);
                numberofpasses++;
            }
        }
    }
    printf("No of passes:%d\n",numberofpasses);
}
int main()
{
    printf("Enter the no of elements:");
    int n,arr[n];
    scanf("%d",&n);
    printf("Enter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    bblsort(arr,n); 
    printf("Sorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}