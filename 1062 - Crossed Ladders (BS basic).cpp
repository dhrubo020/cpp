#include<bits/stdc++.h>
using namespace std;
typedef double dbl;

dbl BS(dbl x , dbl y , dbl c)
{
      dbl hi , low=0.0 , mid, h , h1 ,h2;
      hi=(x>y)?y:x;
      while( hi - low >= 0.00000001)
      {
            mid = (hi+low)/2;
            //cout<<mid<<endl;
            h1 = sqrt((x*x)-(mid*mid));
            h2 = sqrt((y*y)-(mid*mid));
            h = (h1*h2)/(h1+h2);

            if( h <= c)
                  hi = mid;
            else
                  low = mid;
      }
      return mid;
}
int main()
{
      int tc;
      scanf("%d",&tc);
      int cs=1;
      while(tc--)
      {
            dbl x , y , c , ans;
            scanf("%lf %lf %lf",&x,&y,&c);
            ans = BS(x , y , c);
            printf("Case %d: %.8lf\n",cs++ , ans);
      }
}
