#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mx 100001
int arr[mx];
int tree[mx * 3];
int lazy[mx*3];

void init(int node , int b , int e)
{
      if(b==e)
      {
            tree[node]=arr[b];
            return;
      }
      int mid = (b+e)/2;
      int left = node*2;
      int right = (node*2)+1;
      init(left , b , mid);
      init(right , mid+1 , e);
      tree[node] = tree[left] + tree[right];
}

int update(int node , int b , int e , int i , int j , int val)
{
      if(lazy[node]!=0)
      {
            tree[node]+=(e-b+1)*lazy[node];
            if(b!=e)
            {
                  lazy[2*node]+=lazy[node];
                  lazy[2*node +1]+=lazy[node];
            }
            lazy[node]=0;
      }
      if(j<b or i>e)
            return 0;
      if(b>=i and e<=j)
      {
            tree[node]+=(e-b+1)*val;
            if(b!=e)
            {
                  lazy[node*2]+=val;
                  lazy[node*2+1]+=val;
            }
            return 0;
      }
      int mid=(b+e)/2;   int left=node*2;   int right = node*2+1;
      update(left , b , mid , i , j , val);
      update(right , mid+1 , e , i , j , val);
      tree[node] = tree[left]+tree[right];
}
int query(int node , int b , int e , int i , int j)
{
      if(j<b or i>e or b>e)
            return 0;
      if(lazy[node]!=0)
      {
            tree[node]+=(e-b+1)*lazy[node];
            if(b!=e)
            {
                  lazy[node*2]+=lazy[node];
                  lazy[node*2+1]+=lazy[node];
            }
            lazy[node]=0;
      }
      if(b>=i and e<=j)
            return tree[node];

      int mid=(b+e)/2; int left=node*2; int right=node*2+1;
      int p1=query(left , b , mid , i , j);
      int p2=query(right , mid+1 , e , i , j);
      return p1+p2;
}

int main()
{
      memset(lazy , 0 , sizeof(lazy));
      memset(tree , 0 , sizeof(tree));
      int n;
      cin>>n;
      for(int i=1; i<=n; i++)
            cin>>arr[i];
      init(1 , 1 , n);

      int q;
      cin>>q;
      while(q--)
      {
            int a , x, y,w;
            cin>>a>>x>>y;
            if(a==0)
            {
                  cin>>w;
                  update(1 , 1 , n , x , y , w);
            }
            else if(a==1)
            {
                  int ans=query(1 , 1  , n , x , y);
                  cout<<ans<<endl;
            }
      }
}

