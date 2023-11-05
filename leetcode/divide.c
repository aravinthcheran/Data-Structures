#include <stdio.h>
#include <limits.h>
int divide(int dividend, int divisor)
{
    int sign = 1;
    int quotient=0;
    if (dividend < 0)
    {
        if(divisor<0)
        {
            if(dividend<=INT_MIN)
            {
                return INT_MAX;
            }
            else
            {
                dividend *= -1;
                divisor *= -1;
            }
        }
        else if(divisor>0)
        {
            if(dividend<=INT_MIN)
            {
                return INT_MIN;
            }
            else
            {
                sign *= -1;
                dividend *= -1;
            }
        }
    
    }
    else if(dividend > 0)
    {
        if(divisor<0)
        {
            if(dividend>=INT_MAX)
            {
                return INT_MIN;
            }
            else
            {
                sign *= -1;
                divisor *= -1;
            }
        }
        else if(divisor>0)
        {
            if(dividend>=INT_MAX)
            {
                return INT_MAX;
            }
        }
    }
    else
    {
        return 0;
    }
    while(dividend >= divisor)
    {
        dividend -= divisor;
        quotient++;
    }
    return quotient * sign;
}

int main()
{
    int dividend =7;
    int divisor = -3;
    int quotient = divide(dividend, divisor);
    printf("%d\n", quotient);
    return 0;
}