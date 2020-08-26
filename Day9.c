
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long long int gcd(long long int a, long long int bp);
long long int power(long long int a, long long int b, long long int p);
long long int mulinv(long long int a, long long int b);

int main()
{
    long long int k, a, b, x, i, j, ans=0;
    scanf("%lld", &k);
    while(k>0)
    {
        scanf("%lld %lld %lld",&a,&b,&x);
        if(b >= 0)
        {
            i = a;
        }
        else
        {
            i = mulinv(a,x);
            b = -b;
        }
        printf("%lld\n",power(i,b,x)%x);
        k--;
    }
    return 0;
}

long long int power(long long int a, long long int b, long long int p)
{
    a = a%p;
    long long int ans = 1;
    long long int k = (a*a)%p;
    if(b == 0)
    {
        return 1;
    }
    if(a == 0)
    {
        return 0;
    }
    if(b%2==0)
    {
        ans = power(k,(b/2),p);
    }
    else
    {
        ans = (a*power(k,((b-1)/2),p))%p;
    }
    return ans;
}

long long int mulinv(long long int a, long long int b)
{
    long long int b0=b, t, q;
    long long int x0=0, x1=1;
    if(b==1)
    {
        return 1;
    }
    while (a>1)
    {
        q = a/b;
        t=b, b = a%b, a=t;
        t=x0, x0 = x1-q*x0, x1=t;
    }
    if(x1<0)
    {
        x1 += b0;
    }
    return x1;
}

long long int gcd(long long int a, long long int bp)
{
    long long int temp, p1=1, p2=0, p0=0, q[3], b=bp, bt=bp, cn=0;
    q[2]=q[1]=q[0]=0;
    if(a<b)
    {
        temp = b;
        b = a;
        a = temp;
    }
    temp = a%b;
    q[2] = (a/b);
    a = b;
    b = temp;
    while(b != 0)
    {
        temp = a%b;
        q[0] = (a/b);
        a = b;
        b = temp;
        p0 = (p2-(p1*q[2]))%bt;
        p0 = (p0+bt)%bt;
        p2 = p1;
        p1 = p0;
        q[2] = q[1];
        q[1] = q[0];
        cn++;
    }
    p0 = (p2-(p1*q[2]))%bt;
    p0 = (p0+bt)%bt;
    return p0;
}
