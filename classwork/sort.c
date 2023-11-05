#include<stdio.h>
#include"bubblesort.h"
int main()
{
    printf("Enter the number of elements in the array:");
    int n,arr[n];
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    bubblesort(arr,n);
}