#define M 2000001
#include<bits/stdc++.h>
using namespace std;
int dp[M][M];
int A[M],B[M];
int m,n;
int MIN(int x, int y, int z)
{
      return min(min(x,y) , z);
}
int editdis()
{
      for(int i=0; i<=m; i++)
      {
            for(int j=0; j<=n; j++)
            {
                  if(i==0)
                        dp[i][j] = j;
                  else if(j == 0)
                        dp[i][j]=i;
                  else if(A[i-1] == B[j-1])
                        dp[i][j] = dp[i-1][j-1];
                  else
                        dp[i][j] = 1+MIN(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
      }
      return dp[m][n];
}

int main()
{
      int T;
      scanf("%d",%T);
      for(int k=1; k<=T; k++)
      {
            int n;
            scanf("%d",&n);
            for(int i=0; i<n; i++)
                  scanf("%d",&A[i]);
            for(int j=0; j<n; j++)
                  scanf("%d",&B[j]);
            editdis(A,B);
      }
}

