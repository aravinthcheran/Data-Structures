#include<stdio.h>
#include<math.h>
int isPrime(int n);
int countPrimes(int n)
{
    int count=0;
    for(int i=2;i<n;i++)
    {
        if(isPrime(i))
        {
            count++;
        }
    }
    return count;
}
int isPrime(int n)
{
    if(n<=1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    if(n%2==0)
    {
        return 0;
    }
    for(int i=3;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int main(void)
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("The no of primes within %d is:%d",n,countPrimes(n));
    return 0;
}