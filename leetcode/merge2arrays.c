#include<stdio.h>
#include<stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int flag=0;
    for (int i = 0; i < n; i++)
    {
        nums1[m + i] = nums2[i];
    }
    
    for (int i = m + n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums1[j] > nums1[j + 1])
            {
                int temp = nums1[j];
                nums1[j] = nums1[j + 1];
                nums1[j + 1] = temp;
                flag++;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
    free(nums2);
}

int main()
{
    int nums1[6] = {1, 2, 3, 0, 0, 0};
    int nums2[3] = {2, 5, 6};
    merge(nums1, 6, 3, nums2, 3, 3);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", nums1[i]);
    }
}
