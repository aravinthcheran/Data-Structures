#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int specialNumber(int n);
int countSpecialNumbers(int n)
{
    int count=0;
    char str[n];
    for(int i=0;i<n;i++)
    {
        if(specialNumber(i))
        {
            count++;
        }
    }
        return count;           
}
int specialNumber(int n)
{
    bool arr[10]={0};//to check if the digit is repeated
    while(n)
    {
        int rem=n%10;
        if(arr[rem])
        {
            return 0;
        }
        arr[rem]=1;
        n/=10;
    }
    return 1;
}
