#include<bits/stdc++.h>
using namespace std;

#define     pb              push_back
#define     popb            pop_back
#define     lld             long long int
#define     ull             unsigned long long int
#define     max3(a,b,c)     max(a,max(b,c))
#define     max4(a,b,c,d)   max(max3(a,b,c),d)
#define     min3(a,b,c)     min(a,min(b,c))
#define     min4(a,b,c,d)   min(a,min3(b,c,d))
#define     MOD             1000000009
#define     f               first
#define     s               second
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     mp              make_pair
#define     show            printf("---***---")
#define     all(v)          v.begin(),v.end()
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     pii             pair<int,int>
#define     PLL             pair<lld,lld>
#define     MAX             100000000000014
#define     MIN             -100000000000014
#define     gti             greater<int>
#define     gtL             greater<lld>
#define     PI1             acos(-1.0)
#define     pi2             2.0*acos(0.0)
#define     endl            '\n'

int Arr[505][505];
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
map<pair<int,int>,pair<int,int> >Mp;
int dp[505][505],Ar[505][505];

int main()
{
    int N,M;
   scanf("%d%d",&N,&M);


    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            cin>>Ar[i][j];
            Mp[mp(i,j)]=mp(-1,-1);
            dp[i][j]=0;
        }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            int p=i,q=j,mx=Ar[i][j];
            int st=Ar[i][j];

            for(int k=0; k<8; k++)
            {
                int x=i+fx[k];
                int y=j+fy[k];

                if(x>=N || x<0 || y>=M || y<0)
                    continue;
                int now=Ar[x][y];

                if(now<mx)
                {
                    mx=now;
                    p=x;
                    q=y;
                }

            }

                int a=Mp[mp(p,q)].f;
                int b=Mp[mp(p,q)].s;

            //cout<<a<<" "<<b<<" "<<endl;

            if(mx==st)
            {
                dp[i][j]++;
            }

            else if(a==-1 || b==-1)
            {
                Mp[mp(p,q)]=mp(p,q);
                Mp[mp(i,j)]=mp(p,q);
                dp[p][q]++;
            }
            else
            {
                Mp[mp(i,j)]=mp(a,b);
                dp[a][b]++;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
          {
              int a=Mp[mp(i,j)].f;
              int b=Mp[mp(i,j)].s;
              cout<<dp[i][j]<<" ";
             // cout<<a<<" "<<b<<"-";
          }
          cout<<endl;
      }

}
