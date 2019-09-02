#include<bits/stdc++.h>
using namespace std;
vector <int> G[100];
int Time=0, children, dis[100]={NULL}, low[100]={NULL}, par[100];
bool vis[100] , AP[100];

void init(int node)
{
    for(int i=1; i<=node; i++)
        par[i] = i;
}

void Art_point(int u)
{
    Time++;
    dis[u] = Time;
    low[u] = Time;
    vis[u] = true;
    children=0;

    for(int i=0; i<G[u].size(); i++){
        int v = G[u][i];
        if ( v == par[u])
            continue;
        if(vis[v])
            low[u] = min(low[u] , dis[v]);

        if(vis[v] == false){
            par[v] = u;
            Art_point(v);

            if( dis[u] <= low[v] && u!=par[u])
                AP[u] = true;
            children++;
        }

        if( children > 1&& u==par[u])
            AP[u] = true;
    }
}
int main()
{
    int node, edges, x, y;
    cin>>node>>edges;
    for(int i=1; i<=edges; i++){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    init(node);
    Art_point(1);
    for(int i=1; i<=node; i++){
        if(AP[i] == true)
            cout << i << " ";
    }
}
