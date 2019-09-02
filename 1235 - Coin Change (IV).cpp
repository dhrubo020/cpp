#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>v1,v2;
int n , k;
int coin[20];

void make_v1(ll i , ll val)
{

      v1.push_back(val);
      if(i == n/2)
            return;
      make_v1(i+1 , val);
      make_v1(i+1 , val+coin[i]);
      make_v1(i+1 , val+2*coin[i]);
}
void make_v2(ll i , ll val)
{cout<<i<<" "<<val<<endl;
      v2.push_back(val);
      if(i == n)
            return;
      make_v2(i+1 , val);
      make_v2(i+1 , val+coin[i]);
      make_v2(i+1 , val+2*coin[i]);
}

int main()
{
      ll t , cs=1;
      cin>>t;
      while(t--)
      {
            v1.clear();
            v2.clear();
            memset(coin , 0 , sizeof(coin));

            cin>>n>>k;
            for(int i=0; i<n; i++)
                  cin>>coin[i];

            make_v1(0,0);
            make_v2(n/2,0);

            sort(v2.begin() , v2.end());
            cout<<v1.size()<<" "<<v2.size()<<endl;
            for(int i=0 ; i<v1.size(); i++)
            cout<<v1[i]<<endl;
            for(int i=0 ; i<v2.size(); i++)
                  cout<<" "<<v2[i]<<endl;
            bool tr=false;
            printf("Case %d: ",cs++);
            for(int i=0 ; i<v1.size(); i++)
            {
                  if( binary_search(v2.begin(), v2.end() , k-v1[i]))
                  {
                        printf("Yes\n");
                        tr=true;
                        break;
                  }
            }
            if( tr==false)
                  printf("No\n");
      }
}
