#include<bits/stdc++.h>
using namespace std;

map <string , int > mp;
map <string ,map<string> > M;
vector <int> G[201];
queue <string> Q;
int indegree[1000];
int main()
{
    int node, edges, v=0;
    char S1[55], S2[55];
    string x,y;
    while( (scanf("%d",&node)) != EOF){
        cin >> x;
        mp[x]=0
    }
    scanf("%d",&edges);
    for(int i=1; i<=edges; i++){
            cin >> x >> y;
        M[x].insert(y);
    }
}
