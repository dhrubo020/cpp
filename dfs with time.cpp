#include<bits/stdc++.h>
using namespace std;

vector <int> G[100];
int discovery[100]={NULL} , finish[100]={NULL} , color[100]={NULL};
int times=0;

void DFS(int source)
{
    int u=source;
    times++;
    discovery[u] = times;
    color[u] = 1;
    for(int i=0; i<G[u].size(); i++){
        int v = G[u][i];
        //cout<<v<<endl;
        if( color[v] == 0)
            DFS(v);
    }
    color[u] = 2;
    times++;
    finish[u] = times;
}

int main()
{
    int node, edges, x, y;
    cin >> node >> edges;
    for(int i=1; i<=edges; i++){
        cin >> x >> y;
        G[x].push_back(y);
    }
    for(int i=1; i<=node; i++){
        if(color[i]==0)
            DFS(i);
    }

    for( int i=1; i<=node; i++)
        cout << i << " DT " << "  " << discovery[i] << "  " << "FT" << "  " << finish[i] <<endl;
}
