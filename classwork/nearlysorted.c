#include<stdio.h>
#include"fisheryates.h"
int main()
{
    int array[100000];
    for(int i=0;i<100000;i++)
    {
        array[i]=i;
    }
    fisheryates(array,100000,100,150);
    fisheryates(array,100000,413,512);
    fisheryates(array,100000,860,960);
    printf("The array is:\n");
    for(int i=0;i<1000;i++)
    {
        printf("%d\n",array[i]);
    }
}
