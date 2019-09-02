#include<bits/stdc++.h>
using namespace std;
#define M 1000
vector<int>G[1000];
int c, node, edges, x, y, color[M]={0}, dis[M]={0}, fin[M]={0}, par[M]={0},t;

int DFSvis(int u)
{
    t++;
    color[u] = 1;
    dis[u] = t;
    for(int i=0; i<G[u].size(); i++)
    {
                int v=G[u][i];
                cout<<"U " <<u<<"  V "<<v<<endl;
                cout<<"pU " <<par[u]<<"  pV "<<par[v]<<endl;
                if( color[v] == 1 and par[u] != v){
                        cout<<u << " "<<v<<endl;
                        c++;
                }
                if( color[v] == 0)
                {
                        par[v] = u;
                        DFSvis(v);
                }
    }
    color[u] = 3;
    cout<<"black "<<u<<endl;
    fin[u]= t;
}
int main()
{
        t=0, c=0;
    cin>>node>>edges;

    for(int i=1; i<=edges; i++)
    {
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1; i<=node; i++)
    {
        if( color[i] == 0){
                        cout<<"node "<<i<<endl;
             DFSvis(i) ;
        }
    }
    cout<<c<<endl;
}
