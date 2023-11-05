#include<stdio.h>
int binsearch(int number,int arr[],int size)
{
    int low=arr[0],high=arr[size-1];
    while(low<=high)
    {
        int mid=low+high/2;
        if(number<mid)
        {
            high=mid-1;
        }
        else if(number>mid)
        {
            low=mid+1;
        }
        else if(number==mid)
        {
            return mid;
            break;
        }
        else
        {
            return -1;
        }
    }
}