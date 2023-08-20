#include<stdio.h>
#include"classwork/fisheryates.h"
int main()
{
    int rarr[100000];
    for(int i=0;i<100000;i++)
    {
        rarr[i]=i;
    }
    fisheryates(rarr,100000,1,100000);
    for(int i=0;i<100000;i++)
    {
        printf("%d\n",rarr[i]);
    }
}