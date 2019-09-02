#include<bits/stdc++.h>
using namespace std;

long N2(long num)
{
    long pow_2 = 2, counter = 0;
    while(pow_2 <= num)
    {
        counter += num / pow_2;
        pow_2 *= 2;
    }
    return counter;
}

long N5(long num)
{
    long pow_5 = 5, counter = 0;
    while(pow_5 <= num)
    {
        counter += num / pow_5;
        pow_5 *= 5;
    }
    return counter;
}

int Pw(int n , int a)
{
      int cnt=0;
      while(n%a==0)
      {
            cnt++;
            n/=a;
      }
      return cnt;
}
int main()
{
      int tc;
      scanf("%d",&tc);
      int cs=1;
      while(tc--)
      {
            int n , r , p , q , i , j, k, l, a, b , xq , yq;
            scanf("%d %d %d %d", &n , &r, &p, &q);

            i = N2(n);     j = N5(n);
            k = N2(r);     l = N5(r);
            a = N2(n-r) ;    b = N5(n-r);
      int n2 = i-k-a ;              int n5=j-l-b;

            xq = Pw(p , 2)*q;       yq=Pw(p , 5)*q;

            int ans = min(n2+xq , n5+yq);

            printf("Case %d: %d\n",cs++,ans);
      }
}
