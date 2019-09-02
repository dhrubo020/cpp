#include<bits/stdc++.h>
using namespace std;

int binary_decimal(int n)
{
      cout<<n<<endl;
    int rem, i=1, binary=0;
    while (n!=0)
    {
        rem=n%2;
        n = n/2;
        binary+=rem*i;
        cout<<binary<<" "<<rem<<" "<<n<<endl;
        i*=10;
    }
    return binary;
}

int main()
{
      int a,b,c,d,e,f,g,h;
      char dot;
     int tc;
     scanf("%d",&tc);
     for(int t=1; t<=tc; t++){
      cin>>a>>dot>>b>>dot>>c>>dot>>d;
      cin>>e>>dot>>f>>dot>>g>>dot>>h;

      if( binary_decimal(a)==e and binary_decimal(b)==f and binary_decimal(c)==g and binary_decimal(d)==h )
            printf("Case %d: Yes\n",t);
      else
            printf("Case %d: No\n",t);
     }
}

