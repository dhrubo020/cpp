#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef  pair<int , pair<int , int>>PAIR;

#define     pb              push_back
#define     popb            pop_back
#define     ll              long long int
#define     ull             unsigned long long int
#define     MOD             1000000009
#define     f               first
#define     s               second
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     mp              make_pair
#define     all(v)          v.begin(),v.end()
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     pii             pair<int,int>
#define     Pairll            pair<ll,ll>
#define     MAX             100000000000014
#define     MIN             -100000000000014

vector< pii> G[101];
int cost[101][101];
int dis[101];

void init(int n)
{
      for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)
            {
                  cost[i][j]=0;
            }
            G[i].clear();
            dis[i]=MAX;
      }
}
void dijkstra()
{
      priority_queue<pii ,vector<pii>, greater<pii> >Q;
      Q.push(mp(1 , 0));
      dis[1]=0;

      while(!Q.empty())
      {
            pii P = Q.top();
            int u = P.f;
            Q.pop();
            for(int i=0; i<G[u].size(); i++)
            {
                  int v = G[u][i].f;
                  if(dis[u] + cost[u][v] < dis[v])
                  {
                        dis[v] = dis[u]+cost[u][v];
                        Q.push(G[u][i]);
                  }
            }
      }
}

int main()
{
      int t , n , e , x , y ,w;
      cin>>t;
      for(int c=1; c<=t; c++){
            cin>>n>>e;
            init(n);
            for(int i=0; i<e; i++)
            {
                  cin>>x>>y>>w;
                  G[x].pb(mp(y,w));
                  G[y].pb(mp(x,w));
                  cost[x][y]=w;
                  cost[y][x]=w;
            }
            dijkstra();
            for(int i=1; i<=n; i++)
            {
                  cout<<1<<" "<<i<<"= "<<dis[i]<<endl;
            }
      }
}

