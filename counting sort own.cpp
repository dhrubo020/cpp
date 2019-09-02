#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
      //freopen("input_c.txt" , " r" , stdin);
      //freopen("output.txt" , "w" , stdout);

      int n;
      cin>>n;
      int A[n+1];
      int mx=0;
      int Cnt[n+1], Sum[n+1] , T[n+1];
      Sum[0]=0;

      for(int i=0; i<n; i++){
            cin>>A[i];
            mx = max(mx , A[i]);
            Cnt[i]=0;
      }

      for(int i=0; i<n; i++)
            Cnt[A[i]]++;

      for(int i=1; i<=n; i++)
            Sum[i] = Sum[i-1]+Cnt[i];

      for(int i=n-1; i>=0; i--)
      {
            int idx1 = A[i];
            int idx2 = Sum[idx1];
            Sum[idx1]--;
            T[idx2] = A[i];
      }

      for(int i=1; i<=n; i++)
            cout<<T[i]<<" ";
}

