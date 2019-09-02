#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int lld;

lld dp[22][10001], make, coin[21];

lld call(int i, int amount)
{
     // cout<<i<<" "<<amount<<endl;
      if(i >= 21)
      {
            if(amount == 0) return 1;
            return 0;
      }
      if(amount==0)
            return 1;
      if(amount < 0)
            return 0;
      if(dp[i][amount] != -1)
            return dp[i][amount];
      lld profit1=0,profit2=0;
      if(amount - coin[i] >=0 )
            profit1= call(i, amount - coin[i]);
      profit2= call(i+1 , amount);

      return dp[i][amount] = profit1+profit2;
}


int main()
{
      for(int i=1; i<=21; i++)
      {
            coin[i-1]=i*i*i;
      }
      memset(dp,-1,sizeof(dp));

      while(scanf("%lld",&make)!=EOF)
      {
            cout<<call(0,make)<<endl;
      }
}
