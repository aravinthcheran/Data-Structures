#include <stdio.h>
#include <math.h>
double myPow(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x;
    }
    else if (n<0)
    {
        return (1/x)*myPow(x,n+1);
    }
    else
    {
        return (x*myPow(x,n-1));
    }
}
int main()
{
    double x;
    int n;
    printf("Enter the value of x and n: ");
    scanf("%lf %d",&x,&n);
    printf("The value of %lf^%d is %lf",x,n,myPow(x,n));
    return 0;
}