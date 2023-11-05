#include<stdio.h>
#include"insertionsort.h"
#include<time.h>
int main()
{
    FILE *f;
    f=fopen("ascend.txt","r");
    int arr[100000];
    for(int i=0;i<100000;i++)
    {
        fscanf(f,"%d",&arr[i]);
    }
    fclose(f);
    clock_t start,end;
    start=clock();
    insertionsort(arr,100000);
    end=clock();
    printf("The time taken for iterating 100000 elements in ascending order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    f=fopen("descend.txt","r");
    for(int i=0;i<100000;i++)
    {
        fscanf(f,"%d",&arr[i]);
    }
    fclose(f);
    start=clock();
    insertionsort(arr,100000);
    end=clock();
    printf("The time taken for arranging 100000 elements from descending order to ascending order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    f=fopen("random.txt","r");
    for(int i=0;i<100000;i++)
    {
        fscanf(f,"%d",&arr[i]);
    }
    fclose(f);
    start=clock();
    insertionsort(arr,100000);
    end=clock();
    printf("The time taken for arranging 100000 elements in random order to ascending order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    f=fopen("orderedrandom.txt","r");
    for(int i=0;i<100000;i++)
    {
        fscanf(f,"%d",&arr[i]);
    }
    fclose(f);
    start=clock();
    insertionsort(arr,100000);
    end=clock();
    printf("The time taken for arranging 100000 elements from nearly sorted to ascending order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
}