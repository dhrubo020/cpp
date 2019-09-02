#include<bits/stdc++.h>
using namespace std;
#define MX 1000005
typedef long long int lld;
lld m=1000003, d, x ,y,c;
lld fact[MX];

void extendedEuclid(lld A, lld B)
{
      if(B==0)
      {
            d=A;
            x=1;
            y=0;
      }
      else
      {
            extendedEuclid(B , A%B);
            lld temp = x;
            x = y;
            y = temp - (A/B)*y;
      }
}

lld mod_inverse(lld B, lld M)
{
      extendedEuclid(B,M);
      return (x%M+M)%M;
}

int main()
{
      lld n, r;
      int tst;

      fact[0] = fact[1] = 1;
	for(int i = 2; i <= 1000000; i++)
	fact[i] = (fact[i-1] * i) % m;

      scanf("%d", &tst);
	for(int t=1; t<=tst; t++)
      {
		scanf("%d %d", &n, &r);

		lld up = fact[n];
		lld down = ((fact[r]%m * fact[n-r]%m))%m;

            lld ans1= mod_inverse(down , m);

            lld ans2 = (up%m * ans1%m)%m;
            printf("Case %d: %lld\n",t,ans2);
	}
}
