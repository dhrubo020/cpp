#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define LL  long long
#define REP(i,n) for(int i=0;i<n;i++)


int main()
{
    string mnth[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    string m1,m2;
    LL T,d1,d2,y1,y2;
    char ch;

    map <string, int> mp;

    REP(i,12)  mp[mnth[i]] = i;

    cin>>T;

    FOR(i,1,T)
    {
        cin>>m1>>d1>>ch>>y1;
        cin>>m2>>d2>>ch>>y2;

        if(mp[m1] > 1)
            y1++;
        /// if first month greater than february, then we don't need that yr, can subtract that

        if(mp[m2] == 0 or (mp[m2]==1 and d2<29))
            y2--;
        ///if last mnth less than feb 29, then we don't need that yr, subtract also
      cout<<y1<<" "<<y2<<endl;
        LL ans = y2/4 - (y1-1)/4;
cout<<ans<<endl;
        ans -= y2/100 - (y1-1)/100;
cout<<ans<<endl;
        ans += y2/400 - (y1-1)/400;
cout<<ans<<endl;
        printf("Case %d: %lld\n", i, ans);
    }
    return 0;
}
