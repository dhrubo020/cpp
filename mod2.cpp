#include<bits/stdc++.h>
using namespace std;
int mod(long long int a, long long int b, long long int c)
{
    long long int i,ans= 1;
    for( i=1; i<=b; i++){
        ans*=a;
        ans%=c;
    }
    return ans;
}
int main()
{
    long long int a,b,c,ans;
    while(1){
    cin >> a>>b>>c;
    ans= mod(a,b,c);
    cout << ans << endl;
    }
}
