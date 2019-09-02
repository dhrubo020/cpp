#include<bits/stdc++.h>
#define M 1001
#define MOD 100000007
using namespace std;
typedef long long int lld;

lld dp[M][51];
int coin[51];
int countCoin[51];
int target, n;

lld rec(int amount, int index)
{
   if(index==n)
   {
       if(amount==0) return 1;
       return 0;
   }
   if(amount==0)
   {
       return 1;
   }


   if(amount<0)
   {
       return 0;
   }

   if(dp[amount][index] != -1)
   {
       return dp[amount][index];
   }

   lld result = 0;
   for(int i=0; i<=countCoin[index]; i++)
   {
       result = (result + rec(amount - coin[index]*i, index+1)) % MOD;
   }

   dp[amount][index] = result;
   return result;

}

int main()
{
      int t;

      cin>>t;
      for(int c=1; c<=t; c++)
      {
            memset(dp,-1,sizeof(dp));
      cin>>n>>target;
      for(int i=0; i<n; i++)
            cin>>coin[i];
      for(int i=0; i<n; i++)
            cin>>countCoin[i];
      cout<<"Case "<<c<<": "<<rec(target,0)<<endl;
      }
}
