#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>PAIR;
vector<PAIR> G[30005];
int NodeMax[1000];
int NodeTotal[1000]={0};
int color[1000] , par_cost[1000] , par[1000] ;
int cost[1000][1000] , v;

void init()
{
      for(int i=0; i<=1000; i++)
      {
            NodeMax[i]=0; NodeTotal[i]=0; color[i]=0; par_cost[i]=0; par[i]=i;
      }

}
void DFS(int u , int val )
{
      color[u] = 1;
     cout<<"S= "<<u<<endl;
      for(int i=0; i<G[u].size(); i++)
      {
            v = G[u][i].second;

            if( color[v] == 0){
                  par[v]=u;
                  DFS(v , val);
                  //cost[u][v] = cost[u][v];
            }
      }

            if(u==par[u])
                  return;

      color[u] = 2;
      int p = par[u];
      NodeMax[p] = max(NodeMax[p] , par_cost[u]+cost[u][p]);
      par_cost[p] =  par_cost[p]+par_cost[u]         +cost[u][p];

      NodeTotal[p] = par_cost[p];
      cout<<u<<" " <<p<<" "<<par_cost[p]<<" "<<NodeMax[p]<<" "<<NodeTotal[p]<<endl;
}

int main()
{
      init();
      int node , edge , x,y,w;
      cin>>node>>edge;

      for(int i=1; i<=edge; i++)
      {
            cin>>x>>y>>w;
            G[x].push_back(make_pair(w,y));
              G[y].push_back(make_pair(w,x));
            cost[x][y]=w;
            cost[y][x]=w;
      }
      cout<<"-------------------"<<endl;
      int source=5;
      DFS(source, 0);
      cout<<"output"<<endl;
      for(int i=1; i<=node; i++)
            cout<<i<<" "<<NodeMax[i]<<" "<<NodeTotal[i]<<endl;
}
