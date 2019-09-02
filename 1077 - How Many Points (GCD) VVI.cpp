#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll GCD(ll A , ll B)
{
      if(B==0)
            return A;
      else
            return GCD(B , A%B);
}

int main()
{
      ll tc , cs=1;
      cin>>tc;
      while(tc--)
      {
            ll x , y , a , b , ans;
            cin>>x>>y>>a>>b;
            ans = GCD(abs(x-a) , abs(y-b))+1;
            printf("Case %lld: %lld\n",cs++,ans);
      }
}
