#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node , edges, x , y ;
    while(scanf("%d %d", &node, &edges)){
        if(node==0 && edges==0)
            break;

    int indegree[101]={NULL};
    queue <int> Q;
    vector <int> G[101];
    vector <int> V;

        for(int i=1; i<=edges; i++){
            cin >> x >> y;
            G[x].push_back(y);
            indegree[y]++;
        }

        for(int i=1; i<=node; i++){
            if(indegree[i]==0){
                Q.push(i);
                V.push_back(i);
            }
        }
        while(!Q.empty()){
            int u = Q.front();

            Q.pop();
            for(int i=0; i<G[u].size(); i++){
                indegree[G[u][i]]--;
                if(indegree[G[u][i]] == 0){
                    Q.push(G[u][i]);
                    cout << c;
                    V.push_back(G[u][i]);
                }
            }
        }
        for(int i=0; i<V.size(); i++){
            cout << V[i];
            if(i < V.size()-1)
                cout << " ";
        }puts("");
    }
}
