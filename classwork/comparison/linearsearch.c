#include<stdio.h>
#include<time.h>
int linearsearch(int *a,int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[100000];
    FILE *f;
    f=fopen("ascend.txt","r");
    for(int i=0;i<100000;i++)
    {
        fscanf(f,"%d",&arr[i]);
    }
    fclose(f);
    int key=0;
    clock_t start,end;
    start=clock();
    int index=linearsearch(arr,100000,key);
    end=clock();
    printf("The time taken for searching first element in ascending order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    int key1=100000;
    start=clock();
    index=linearsearch(arr,100000,key1);
    end=clock();
    printf("The time taken for searching last element in ascending order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    int key2=50000;
    start=clock();
    index=linearsearch(arr,100000,key2);
    end=clock();
    printf("The time taken for searching middle element in ascending order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    int key3=4114;
    start=clock();
    index=linearsearch(arr,100000,key3);
    end=clock();
    printf("The time taken for searching random element in ascending order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    f=fopen("descend.txt","r");
    for(int i=0;i<100000;i++)
    {
        fscanf(f,"%d",&arr[i]);
    }
    fclose(f);
    key=0;
    start=clock();
    index=linearsearch(arr,100000,key);
    end=clock();
    printf("The time taken for searching first element in descending order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    key1=100000;
    start=clock();
    index=linearsearch(arr,100000,key1);
    end=clock();
    printf("The time taken for searching last element in descending order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    key2=50000;
    start=clock();
    index=linearsearch(arr,100000,key2);
    end=clock();
    printf("The time taken for searching middle element in descending order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    key3=4114;
    start=clock();
    index=linearsearch(arr,100000,key3);
    end=clock();
    printf("The time taken for searching random element in descending order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    f=fopen("random.txt","r");
    for(int i=0;i<100000;i++)
    {
        fscanf(f,"%d",&arr[i]);
    }
    fclose(f);
    key=0;
    start=clock();
    index=linearsearch(arr,100000,key);
    end=clock();
    printf("The time taken for searching first element in random order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    key1=100000;
    start=clock();
    index=linearsearch(arr,100000,key1);
    end=clock();
    printf("The time taken for searching last element in random order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    key2=50000;
    start=clock();
    index=linearsearch(arr,100000,key2);
    end=clock();
    printf("The time taken for searching middle element in random order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    key3=4114;
    start=clock();
    index=linearsearch(arr,100000,key3);
    end=clock();
    printf("The time taken for searching random element in random order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    f=fopen("orderedrandom.txt","r");
    for(int i=0;i<100000;i++)
    {
        fscanf(f,"%d",&arr[i]);
    }
    fclose(f);
    key=0;
    start=clock();
    index=linearsearch(arr,100000,key);
    end=clock();
    printf("The time taken for searching first element in nearly sorted order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    key1=100000;
    start=clock();
    index=linearsearch(arr,100000,key1);
    end=clock();
    printf("The time taken for searching last element in nearly sorted order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    key2=50000;
    start=clock();
    index=linearsearch(arr,100000,key2);
    end=clock();
    printf("The time taken for searching middle element in nearly sorted order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    key3=4114;
    start=clock();
    index=linearsearch(arr,100000,key3);
    end=clock();
    printf("The time taken for searching random element in nearly sorted order is %f\n",(double)(end-start)/CLOCKS_PER_SEC);
    
}