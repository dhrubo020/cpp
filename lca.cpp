#include<bits/stdc++.h>
using namespace std;
struct node
{
    int Value;
    int Left=-1;
    int Right=-1;
}Tree[1000];
int LCA(int Node,int N,int A,int B)
{
    if(Node>N)
        return 0;
    else if(Tree[Node].Value==A||Tree[Node].Value==B)
        {
        return Tree[Node].Value;
        }
    int L=2*Node;
    int R=2*Node+1;
    Tree[Node].Left=LCA(L,N,A,B);
    Tree[Node].Right=LCA(R,N,A,B);

    if(Tree[Node].Left==A&&Tree[Node].Right==B||Tree[Node].Left==B&&Tree[Node].Right==A)
        {
        return Tree[Node].Value;
        }
    else if(Tree[Node].Left==A||Tree[Node].Left==B)
        {
        return Tree[Node].Left;
        }
    else if(Tree[Node].Right==A||Tree[Node].Right==B)
        {
        return Tree[Node].Right;
        }
    else if(Tree[Node].Right==0&&Tree[Node].Left==0)
        {
        return 0;
        }

    }
int main()
{
    int T;
    cin>>T;
    while(T--)
        {
        int N;
        cin>>N;
        for(int I=1;I<=N;I++)
            {
            cin>>Tree[I].Value;
            }
        int A,B;
        cin>>A>>B;
        LCA(1,N,A,B);

        if(Tree[1].Left==A&&Tree[1].Right==B||Tree[1].Left==B&&Tree[1].Right==A)
            {
            cout<<Tree[1].Value<<endl;
            }
        else if(Tree[1].Left)
            {
            cout<<Tree[1].Left<<endl;
            }
        else
            {
            cout<<Tree[1].Right<<endl;
            }
    }
    return 0;
}
