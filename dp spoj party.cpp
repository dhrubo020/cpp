#include<bits/stdc++.h>
using namespace std;
int T, W, n ,sum,s, fun[10001], weight[1001], dp[1001][1001];
int call(int i, int w)
{

      if(i > n)
            return 0;
      if( dp[i][w] != -1)
            return dp[i][w];
      int p1=0,p2=0, f1=0, f2=0;
      if( w + weight[i] <= W){
            p1 = fun[i] + call(i+1 , w + weight[i]);
            sum=weight[i];
            cout<<sum<<" ";
      }
      p2 = call(i+1 , w);
      return dp[i][w] = max(p1,p2);
}
int main()
{
      sum=0;
            memset(dp , -1, sizeof(dp));
            cin>>W>>n;
            for(int i=1; i<=n; i++)
                  cin>>weight[i]>>fun[i];

            cout<<sum<<" "<<call(1,0)<<endl;
}
