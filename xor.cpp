#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll a , b , x;
    cin>>a>>b;
    x = a-b;
    vector<int>v;
    while(a>0)
    {
          int rem = a%2;
          a/=2;
          v.push_back(rem);
    }
    int cnt=0;
    for(int i=0; i<v.size(); i++)
      if(v[i]==1)
            cnt++;
    cnt=abs(cnt-x);
    ll ans=3;
    for(int i=1; i<=cnt; i++)
    {
          if(i%2==0)
            ans=ans+3;
          else
            ans=ans+1;
    }
    cout<<ans<<endl;

}
