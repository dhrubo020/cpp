#include<bits/stdc++.h>
using namespace std;
 int dp[100], N;

void init( int n)
{
    for( int i=1; i<=N; i++)
        dp[i] = -1;
}
 int fibo( int n)
{
    if(n==0)
        return 0;
    if(n == 1)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    else{
        dp[n] = fibo(n-1) + fibo(n-2);
        return dp[n];
    }
}
int main()
{

    while(1){
    cin >> N;
    init(N);
    cout << fibo(N) << endl;
    }
}
