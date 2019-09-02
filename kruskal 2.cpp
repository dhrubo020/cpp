#include<bits/stdc++.h>
using namespace std;
int par[1000];
typedef pair< int , pair< int , int> > P;
vector <P> G ;

void init(int node)
{
    for(int i=1; i<=node; i++)
        par[i] = i;
}

int Find(int v)
{
    if(par[v] == v)
        return v;
    else{
        par[v] = Find(par[v]);
        return par[v];
    }
}

void MST(vector <P> G, int node)
{
    int COUNT=0, min_value=0;
    sort(G.begin() , G.end());

    for(int i=0; i<G.size(); i++)
      {
            cout<<G[i].second.first<<" "<<G[i].second.second<<endl;

          int M = Find(G[i].second.first);
          int N = Find(G[i].second.second);
          cout<<N<<" "<<M<<endl;

          if(M!=N){
              par[N] = M;
              cout<<"par["<<N<<"] = "<<M<<endl;
              COUNT++;
              min_value += G[i].first;
              if(COUNT== node-1)
                  break;
          }
    }
    cout << min_value << endl;
}

int main()
{
    int node, edges, x,y,w;
    cin >> node >> edges;
    for(int i=1; i<=edges; i++){
        cin >> x >> y >> w;
        G.push_back(make_pair(w, make_pair(x,y)));
    }
    init(node);
    MST(G,node);
    return 0;
}
