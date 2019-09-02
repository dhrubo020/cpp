#include<bits/stdc++.h>
using namespace std;
int Arr[1000],Tree[4000],Lazy[4000];

int init(int node, int S, int E)
{
    if(S==E)
    {
        Tree[node]=Arr[S];
        return Arr[S];
    }
    int L=2*node;
    int R=2*node+1;
    int mid=(S+E)/2;

    int x=init(L,S,mid);
    int y=init(R,mid+1,E);

    Tree[node]=x+y;
}

int update(int node, int S, int E, int i, int j, int val)
{
    if(Lazy[node]!=0)
    {
        Tree[node]+=Lazy[node]*(E-S+1);
        if(S!=E)
        {
            Lazy[node*2]+=Lazy[node];
            Lazy[2*node+1]+=Lazy[node];
        }
        Lazy[node]=0;
    }

    if(S>j || E<i)
        return 0;
    if(S>=i && E<=j)
    {
        Tree[node]+=(E-S+1)*val;
        if(S!=E)
        {
            Lazy[node*2]+=val;
            Lazy[2*node+1]+=val;
        }
        return 0;
    }

    int L=2*node;
    int R=2*node+1;
    int mid=(S+E)/2;

    update(L,S,mid,i,j,val);
    update(R,mid+1,E,i,j,val);

    Tree[node]=Tree[L]+Tree[R];
}

int query(int node, int S, int E, int i, int j)
{
    if(S>E || S>j || E<i)
        return 0;

    if(Lazy[node]!=0)
    {
        Tree[node]+=Lazy[node]*(E-S+1);
        if(S!=E)
        {
            Lazy[node*2]+=Lazy[node];
            Lazy[2*node+1]+=Lazy[node];
        }
        Lazy[node]=0;
    }

    if(S>=i && E<=j)
        return Tree[node];


    int L=2*node;
    int R=2*node+1;
    int mid=(S+E)/2;

    int q1=query(L,S,mid,i,j);
    int q2=query(R,mid+1,E,i,j);

    Tree[node]=q1+q2;
   return q1+q2;
}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
        scanf("%d",&Arr[i]);

    init(1,1,n);
/*
    int value;
    scanf("%d",&value);
    update(1,1,n,3,6,value);
    cout<<query(1,1,n,1,n)<<endl;
    */
        int q;
        cin>>q;

        while(q--){
                int a,b,x,l;
                cin>>l;
        if(l==1){
        cin>>a>>b>>x;
        update(1,1,n,a,b,x);
        }
        else{
                cin>>a>>b;
            cout<<query(1,1,n,a,b)<<endl;
        }
        }

}
