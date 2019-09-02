#include<bits/stdc++.h>
using namespace std;

typedef pair <int , int> P;
vector <P> G;
int cost[100][100] , dis[100] ;

void init(int node)
{
    for(int i=1; i<=node; i++)
        dis[i] = 199999999;
}
bool bellman(int Snode, int node)
{
    dis[Snode] = 0;
    for(int i=1; i<node; i++){
        for(int j=0; j<G.size(); j++){
            int u = G[j].first;
            int v = G[j].second;
            if( dis[u] + cost[u][v] < dis[v])
                dis[v] = dis[u] + cost[u][v];
        }
    }
    for(int j=0; j<G.size(); j++){
            int u = G[j].first;
            int v = G[j].second;
            cout<<u<<" "<<v<<endl;
            if( dis[u] + cost[u][v] < dis[v]){
                return false;
        }
    }
    return true;
}
int main()
{
    int node, edges, x, y, w;
    cin >> node >> edges;
    for(int i=1; i<=edges; i++){
        cin >> x >> y >> w;
        G.push_back(make_pair(x,y));
        cost[x][y] = w;
    }
    init(node);
    int Snode;
    cin >> Snode;
    bool ask = bellman(Snode , node);
    if(ask){
            for(int i=1; i<=node; i++){
        cout << Snode << " to " << i << " = " << dis[i] << endl;
            }
    }
    else
        cout << "Negative cycle found" << endl;
}
