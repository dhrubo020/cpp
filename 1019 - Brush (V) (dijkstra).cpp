
#include<bits/stdc++.h>
using namespace std;
#define MAX 1500000
typedef long long ll;

ll dis[1005], cost[1005][1005];
typedef pair<ll,ll>PAIR;
vector<PAIR>G[1005];

void init(ll node)
{
      for(ll i=1; i<=node; i++)
            dis[i] = MAX;
}

ll dijkstra(ll s)
{
      priority_queue < PAIR , vector<PAIR> , greater<PAIR> > Q;
      Q.push(make_pair(0,s));
      dis[s] = 0;

      while(!Q.empty())
      {
            PAIR P = Q.top();
      ll node = P.second;
            Q.pop();
            for(ll i=0; i<G[node].size(); i++)
            {
                  ll v = G[node][i].second;
                  if( dis[node] + cost[node][v] < dis[v]){
                        dis[v] = dis[node] + cost[node][v];
                        Q.push(G[node][i]);
                  }
            }
      }
}

int main()
{
      ll t , cs=1;
      scanf("%lld",&t);
      while(t--)
      {
            ll N , M , x, y, w;
            scanf("%lld %lld",&N,&M);
            init(N);
            for(ll i=0; i<1005; i++)
                  for(ll j=0; j<1005; j++)
                        cost[i][j]=0;

            for(ll i=0; i<M; i++)
            {
                  scanf("%lld %lld %lld",&x , &y , &w);
                  G[x].push_back(make_pair(w,y));
                  G[y].push_back(make_pair(w,x));
                  cost[x][y] = w;
                  cost[y][x] = w;
            }
            dijkstra(1);
            if(dis[N]<MAX)
                  printf("Case %lld: %lld\n",cs++,dis[N]);
            else
                  printf("Case %lld: Impossible\n",cs++);
            for(ll i=1; i<=N; i++)
                  G[i].clear();
      }
}
