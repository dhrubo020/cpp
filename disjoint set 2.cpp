#include<bits/stdc++.h>
using namespace std;
int par[1000], c;
int init(int x)
{
    for(int i=1; i<=x; i++){
        par[i]=i;
    }
}
int Find(int x)
{
    if( par[x]==x)
        return x;
    else
    par[x]=Find(par[x]);
    return par[x];
}
int Union(int a, int b)
{
    int u=Find(a);
    int v= Find(b);
    if(u!=v){
        par[u]=v;
        c--;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int node, edges, a,b;
        cin >> node >> edges;
        init(node);
        c=node;
        for(int i=1; i<=edges; i++){
            cin >> a >> b;
            Union(a,b);
        }
        cout << "Number of Graph " << c << endl;
    }
}
