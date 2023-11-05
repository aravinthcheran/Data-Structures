#include<stdio.h>
#include"fisheryates.h"
int main()
{
    FILE *f;
    f=fopen("ascend.txt","w");
    for(int i=1;i<=100000;i++)
    {
        fprintf(f,"%d ",i);
    }
    fclose(f);
    f=fopen("descend.txt","w");
    for(int i=100000;i>=1;i--)
    {
        fprintf(f,"%d ",i);
    }
    fclose(f);
    f=fopen("random.txt","w");
    int rarr[100000];
    for(int i=0;i<100000;i++)
    {
        rarr[i]=i;
    }
    fisheryates(rarr,100000,1,100000);
    for(int i=0;i<100000;i++)
    {
        fprintf(f,"%d ",rarr[i]);
    }
    fclose(f);
    f=fopen("orderedrandom.txt","w");
    int array[100000];
    for(int i=0;i<100000;i++)
    {
        array[i]=i;
    }
    fisheryates(array,100000,100,150);
    fisheryates(array,100000,413,512);
    fisheryates(array,100000,860,960);
    for(int i=0;i<100000;i++)
    {
        fprintf(f,"%d ",array[i]);
    }
    fclose(f);
        
}