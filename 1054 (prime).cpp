#include <bits/stdc++.h>
 using namespace std;

 const int mod = 1000000007;
 const int maxn = 7000;
 typedef long long LL;
 int isprime[maxn], prime[maxn*10];
 LL sum, k;

 void Isprime ()
 {

    int i, j;
    for (i=2, k=0; i<70000; i++){
        if (!prime[i])
       {
           isprime[k ++] = i;
             for (j=i; j<70000; j+=i)
                 prime[j] = 1;
       }
    }

 }

 LL Pow (LL x, LL y)
 {
     LL num = 1;
     while (y)
     {
         if (y % 2)
             num = (num * x) % mod;
        x = (x * x) % mod;
        y /= 2;
     }
     return num;
 }


 LL solve (LL x, LL y)
 {
     LL num;
     num = (Pow(x, y) - 1);
     num = (num * Pow(x-1, mod-2)) % mod;
     return (num + mod) % mod;
 }


 int main ()
 {
    LL t, n, m, l = 0;
     Isprime ();
     scanf ("%lld", &t);
     while (t --)
     {
         scanf ("%lld %lld", &n, &m);
         LL a, b, i;
         i = 0;
         sum = 1;
         while (i < k)
         {
             if (1 == n)
                break;
            a = b = 0;
            if (n % isprime[i] == 0)
            {
                 a = isprime[i];
                 while (n % isprime[i] == 0)
                     {
                         b ++;
                         n /= isprime[i];
                     }
                 sum = (sum * solve(a, b*m+1) ) % mod;
             }
             i++;

         }
         if (n != 1)
             sum = (sum * solve(n, m+1)) % mod;
             printf ("Case %lld: %lld\n", ++l, sum);
     }
     return 0;
 }
