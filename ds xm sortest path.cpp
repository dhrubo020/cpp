#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main()
{
      int node=8, edge=10;
      int x,y;
      vector<int>G[100];

      for(int i=1; i<=edge; i++)
      {
            cin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
      }
      int path[10] , par[10];
      queue<int>Q;
      bool vis[10];
      int level[10];

      Q.push(0);
      level[0]=0;
      par[0]=0;
      vis[0]=true;
      while(!Q.empty())
      {
            int u=Q.front();
            Q.pop();
            for(int i=0; i<G[u].size(); i++)
            {
                  int v = G[u][i];
                  if(vis[v] == false)
                  {
                        par[v] = u;
                        level[v] = level[u]+1;
                        vis[v] =true;
                        Q.push(v);
                  }
            }
      }

      int start=0 , end=6;
      cout<<level[end]<<endl;

      int i=1;
      path[0] = par[end];
      while(true)
      {
            path[i] = par[ path[i-1]];
            if(par[i]==i)
                  break;
            i++;
      }
      cout<<start<<" ";
      for(int j=i; j>=0; j--){
            if(path[j]!=0)
            cout<<path[j]<<" ";
      }
      cout<<end;
}

