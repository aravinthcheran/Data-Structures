#ifndef SWAP_H
#define SWAP_H
#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

#endif