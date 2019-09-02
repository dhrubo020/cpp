#include<bits/stdc++.h>
using namespace std;
vector <int> point;
int C;
vector <int> G[100];
void ART_POINT(int node)
{
    queue <int> Q;
    bool vis[100];
    vis[node] = true;
    for(int i=0; i<G[node].size(); i++){
        int u = G[node][i];
        cout << u << endl;
        Q.push(u);
        if(vis[u] == false ){
            vis[u]= true;

            while(!Q.empty()){
                    int x = Q.front();
                    Q.pop();
                for(int i=0; i<G[x].size(); i++){
                        int v= G[u][i];
                        cout << v << endl;
                    if(vis[v] == false){
                        Q.push(v);
                        vis[v] = true;
                    }
                }
            }
            C++;
        }
    }
    cout << C;
    if( C>1){
        point.push_back(node);
    }
}

int main()
{
    int node , edges, x, y;
    cin >> node >> edges;
    for(int i=1; i<=edges; i++){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1; i<=node; i++){
    if(G[i].size() >1)
    ART_POINT(i);
    }
    for(int i=0; i<point.size(); i++)
        cout << point[i] <<endl;
}
