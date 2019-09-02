#include<bits/stdc++.h>
using namespace std;
#define SIZE 30005
typedef long long ll;
typedef pair<ll , ll>PAIR;

vector<PAIR>G[30005];
int dis[30005] , dis1[30005];
bool vis[30005];


int bfs(int s)
{
      priority_queue< PAIR , vector<PAIR> , greater<PAIR> > Q;
      int MAX = INT_MIN , Mnode;

      vis[s]=true;
      dis[s]=0;
      Q.push(make_pair(s,0));

      while(!Q.empty())
            {
                  PAIR P = Q.top();
                 int u = P.first;
                  Q.pop();
                  for(int i=0; i<G[u].size(); i++)
                  {
                        ll v = G[u][i].first;
                        ll val = G[u][i].second;

                        if( vis[v] == false)
                        {
                              dis[v] = dis[u] + val;
                              if(dis[v] > MAX){
                                    Mnode = v;
                                    MAX=dis[v];
                              }
                              Q.push({v,dis[v]});
                              vis[v]=true;

                        }

                  }
            }
      return Mnode;
}

void CLEAR()
{
      for(int i=0; i<SIZE; i++)
      {
            dis[i]=0;
            G[i].clear();
            vis[i]=false;
      }
}

int main()
{
      int t, cs=1;
      cin>>t;
      while(t--)
      {
            int n , node, x ,y , w;
            cin>>n;
            node=n;
            n--;
            while(n--)
            {
                  cin>>x>>y>>w;
                  G[x].push_back(make_pair(y,w));
                  G[y].push_back(make_pair(x,w));
            }


            int M = bfs(0);
            for(int i=0; i<node; i++)
            {
                  dis1[i]=dis[i];
                  vis[i] = false;
            }
            cout<<M<<endl;
            M = bfs(M);
            for(int i=0; i<node; i++)
            {
                  dis1[i]=dis[i];
                  vis[i] = false;
            }
            bfs(M);
            printf("Case %d: \n",cs++);
            for(int i=0; i<node; i++){
                  printf("%d\n",max(dis1[i],dis[i]));
            }
            CLEAR();
      }
}
