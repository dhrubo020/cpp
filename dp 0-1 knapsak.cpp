#include<bits/stdc++.h>
using namespace std;
int w=0, dp[100][100], weight[100], cost[100];
int n ,cap, test;

void init()
{
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++)
            dp[i][j]=-1;
    }
}
int Profit(int i, int w)
{
      cout<<i<<" "<<w<<endl;
    if( i == n+1)
        return 0;
    if(dp[i][w] != -1)
        return dp[i][w];
    int profit1=0, profit2=0;
    if(w + weight[i] <=cap){
        profit1 = cost[i] + Profit(i+1 ,  w + weight[i]);
    }
        profit2 = Profit(i+1 , w);

    dp[i][w] = max(profit1 , profit2);
    return dp[i][w];
}

int main()
{
        cin >> cap >> n;
        init();
        for(int i=1; i<=n; i++){
            cin >> cost[i]>> weight[i] ;
        }
        cout << Profit(1,0)<< endl;
}
