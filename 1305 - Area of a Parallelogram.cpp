#include<bits/stdc++.h>
using namespace std;

int main()
{
      int t , cs=1;
      cin>>t;
      while(t--)
      {
            long long int ax,ay,bx,by,cx,cy,dx,dy,AB,area;
            cin>>ax>>ay>>bx>>by>>cx>>cy;
            //dx=ax+cx-by;  dy=ay+cy-by;
            dx = ax+cx-bx;
            dy = ay+cy-by;
            area = 0.5*(((ax*by)+(bx*cy)+(cx*dy)+(dx*ay)) - ((ay*bx)+(by*cx)+(cy*dx)+(dy*ax)));

            printf("Case %d: %lld %lld %lld\n",cs++,dx,dy,abs(area));
      }
}
