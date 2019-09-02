#include<bits/stdc++.h>
using namespace std;
int mod(long long int a, long long int b, long long int c)
{
    int ans= 1;
    while(b!=0){
        if(b%2 == 1)
            ans= (ans * a) % c;
        a= (a*a)%c;
        b/=2;
        cout<<ans<<endl;
    }
    return ans;
}
int main()
{
    long long int a,b,c,ans;
    while (scanf("%lld\n%lld\n%lld", &a, &b, &c) != EOF) {
    ans= mod(a,b,c);
    cout << ans << endl;
    }
}
