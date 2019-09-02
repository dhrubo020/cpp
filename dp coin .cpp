#include<bits/stdc++.h>
using namespace std;
int make,N,coin[100],ara[100];
int dp[52][1002][52];
int call(int i,int amount,int j)
{
      if(i>=N) {
      if(amount==make)return 1;
      else return 0;
      }
      if(amount==make)
      return 1;
      if(amount>make)
      return 0;

      if(dp[i][amount][j]!=-1) return dp[i][amount][j];
      int ret1=0,ret2=0;
      if((amount+coin[i]<=make) && (j<ara[i]))
            ret1=call(i,amount+coin[i],j+1);

      ret2=call(i+1,amount,0);
      return dp[i][amount][j]=ret1%100000007+ret2%100000007;

}
int main()
{
int T;
scanf("%d",&T);
for(int t=1; t<=T; t++)
{
scanf("%d%d",&N,&make);

for(int i=0; i<N; i++)
scanf("%d",&coin[i]);

for(int i=0; i<N; i++)
scanf("%d",&ara[i]);

memset(dp,-1,sizeof(dp));
/*while(cin>>make)
{
memset(dp,-1,sizeof(­dp));
cout<<call(0,0)<<end­l;
}
*/
int ans=call(0,0,0);
printf("Case %d: %d\n",t,ans);
}
return 0;
}
