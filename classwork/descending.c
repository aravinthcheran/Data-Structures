#include<stdio.h>
#include<stdlib.h>
#include"swap.h"
int main()
{
    int n;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int sarr[n];
    for(int i=n-1;i>=0;i--)
    {
        sarr[i]=i;
    }
}