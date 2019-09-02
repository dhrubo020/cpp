#include<bits/stdc++.h>
using namespace std;

int main()
{
      int tc, cs=0;
      scanf("%d",&tc);
      while(tc--)
      {
            double AB , AC, BC , AD, AE, DE, R , Ta1=-1 , Ta2, Tp=-1;
            scanf("%lf %lf %lf %lf",&AB, &AC, &BC, &R);
            double hi=AB , low=0 , mid , s;
            AB = AB+.0;
            AC = AC+.0;
             BC = BC+.0;
              R = R+.0;
            while((hi - low) >= 0.00000001)
            {
                  mid = (hi+low)/2.0;
                  AD = mid;
                  AE = (AD*AC)/AB;
                  DE = (AD*BC)/AB;
                  s = (AD+AE+DE)/2.0;
                  Ta1 = sqrt(s*(s-AD)*(s-AE)*(s-DE));

                  s = (AB+AC+BC)/2.0;
                  Ta2 = sqrt(s*(s-AB)*(s-AC)*(s-BC));
                  Tp = Ta2 - Ta1;

                  if( (Ta1/Tp) > R)
                        hi = mid;
                  else if((Ta1/Tp) < R)
                        low = mid;
            }
            printf("Case %d: %.8lf\n",++cs , mid);
      }
}
