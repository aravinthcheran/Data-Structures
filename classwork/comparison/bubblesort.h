#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(int *a,int n)
{
    int flag=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
}
