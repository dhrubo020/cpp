#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define     pb              push_back
#define     popb            pop_back
#define     ll              long long int
#define     ull             unsigned long long int
#define     max3(a,b,c)     max(a,max(b,c))
#define     max4(a,b,c,d)   max(max3,d)
#define     min3(a,b,c)     min(a,min(b,c))
#define     min4(a,b,c,d)   min(a,min3(b,c,d))
#define     MOD             1000000009
#define     f               first
#define     s               second
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     mp              make_pair
#define     check           printf("check")
#define     sqr(x)          (x)*(x)
#define     all(v)          v.begin(),v.end()
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     pii             pair<int,int>
#define     Pair            pair<ll,ll>
#define     MAX             100000000000014
#define     MIN             -100000000000014


int main()
{
      //freopen("input_c.txt" , " r" , stdin);
      //freopen("output.txt" , "w" , stdout);

      int n;
      cin>>n;
      int C[n+1] , A[n+1] , B[n+1];
      for(int i=0; i<n; i++)
      {
            cin>>A[i];
            C[i]=0;
      }
      for(int i=0; i<n; i++)
      {
            C[A[i]]++;
      }
      for(int i=1; i<n; i++)
      {
            C[i]=C[i]+C[i-1];
      }
      for(int i=n-1; i>=0; i--)
      {
            B[C[A[i]]] = A[i];
            C[A[i]]--;
      }
      for(int i=1; i<=n; i++)
            cout<<B[i]<<" ";
}

