int maxArea(int *height,int heightSize)
{
    int maxarea=0,left=0,right=heightSize-1;
    while(left<right)
    {
        int area=(right-left)*((height[left]<height[right])?height[left]:height[right]);
        if(height[left]<height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return maxarea;
}