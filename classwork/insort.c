#include<stdio.h>
#include"insertionsort.h"
int main()
{
    printf("Enter the number of elements: ");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    insertionsort(&arr,n);
    printf("The sorted array is: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}