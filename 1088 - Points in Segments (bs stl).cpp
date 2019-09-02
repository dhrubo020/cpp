#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;


int main()
{
      int tc ;
      ll x;
      scanf("%d",&tc);
      int cs=1;
      while(tc--)
      {
            int n , q;
            scanf("%d %d" , &n , &q );
            vector<ll>v;

            for(int i=0 ; i<n; i++)
            {
                  scanf("%llu",&x);
                  v.push_back(x);
            }
            printf("Case %d:\n", cs++);
            while(q--)
            {
                  ll s , e;
                  scanf("%lld %lld",&s , &e);
                  int low = lower_bound(v.begin(), v.end(), s) - v.begin();
                  int hi = upper_bound(v.begin(), v.end(), e) - v.begin();
                  printf("%d\n",hi-low);
            }
      }
}
