#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mx 100005
int tree[mx*3];
int arr[mx+1];

int sod(int n)
{
      int sum=0;
      while(n>0)
      {
            int rem=n%10;
            n/=10;
            sum+=rem;
      }
      return sum;
}
int  init(int node , int b , int e)
{
      if(b==e)
      {
            tree[node]=arr[b];
            return tree[node];
      }
      int mid = (b+e)/2;
      int left=2*node;
      int right = 2*node+1;
      init(left , b , mid );
      init(right , mid+1 , e);
      tree[node] = max(tree[left] , tree[right]);
      return tree[node];
}

int query(int node , int b , int e , int i , int j)
{
      if(i>e or j<b or b>e)
            return 0;
      if(b>=i and e<=j)
            return tree[node];

      int mid =(b+e)/2 , left=2*node , right=2*node+1;
      int p1=query(left , b , mid , i , j);
      int p2=query(right , mid+1 , e , i , j);
      return max(p1,p2);
}
int main()
{
      int t;
      scanf("%d",&t);
      for(int cs=1; cs<=t; cs++)
      {
            int n , q;
            scanf("%d %d",&n,&q);
            int AA[mx];
            memset(AA, 0 , sizeof(AA));
            for(int i=1; i<=n; i++){
                  int x;
                  scanf("%d",&x);
                  arr[i]=sod(x);
                  if(AA[arr[i]]==0)
                        AA[arr[i]]= i;
            }
            init(1 , 1 , n);
            cout<<"Case #"<<cs<<":\n";
            while(q--)
            {
                  int x , y;
                  scanf("%d %d",&x,&y);
                  int ans=query(1 , 1 , n , x , y) ;
                  printf("%d %d\n", ans, AA[ans]);
            }
      }
}
