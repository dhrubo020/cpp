#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
void init(int n, int r)
{
    for(int i=1; i<=n; i++){
        for(int j=1; j<=r; j++){
            dp[i][j] = -1;
        }
    }
}

int nCr(int n, int r)
{
    if(r==1)
        return n;
    if(n==r)
        return 1;
    if(dp[n][r] != -1)
        return dp[n][r];
        else{
    dp[n][r] = nCr(n - 1 , r) + nCr(n - 1 , r - 1);
        cout << dp[n][r] << endl;
    return dp[n][r];
        }
}
int main()
{
    int test , n , r;
    cin >> test;
    while(test--){
        cin >> n >> r;
        init(n,r);
        cout << nCr(n , r) << endl;
    }
}
