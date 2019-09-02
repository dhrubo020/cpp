#include<bits/stdc++.h>
using namespace std;
int bfs(int s);
vector <int> v;
vector <int> adj[100];
int level[100];
int main()
{
    int vr,ed,x,y;
    int dis[100];
    cin >> vr >> ed;
    for(int i=0; i<ed; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ask;
    cin >> ask;
    bfs(ask);
    for(int i=1; i<=vr; i++){
        for(int j=0; j<adj[i].size(); j++){
            if(i<adj[i][j])
            cout << ask << "--"<< adj[i][j] << " = " << level[adj[i][j]] << endl;
        }
    }
}
int bfs(int s)
{
    queue <int> q;
    bool vis[100];
    q.push(s);
    level[s]=0;
    vis[s]=true;
    while(!q.empty()){
        int p=q.front();
        q.pop();

        for(int i=0; i<adj[p].size(); i++){
            if(vis[adj[p][i]] == false){
                level[adj[p][i]] = level[p] + 1;
                q.push(adj[p][i]);
                vis[adj[p][i]]=true;
            }
        }
    }
}
