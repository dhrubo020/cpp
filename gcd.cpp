#include<bits/stdc++.h>
using namespace std;
int c;
int gcd( int a, int b)
{
    if(a<b)
        gcd(b,a);
    if( b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int a,b ;
        scanf("%d %d",&a,&b);
    cout<< gcd(a,b) << endl;
}
