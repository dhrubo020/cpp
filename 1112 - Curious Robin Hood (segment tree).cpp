#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;

lld arr[100050];
lld tree[3*100050];

void init( int node , int b , int e)
{
      if( b == e){
            tree[node] = arr[b];
            return;
      }

      int left = node*2;
      int right = node*2 + 1;
      int mid = (b+e)/2;
      init(left , b , mid);
      init(right , mid+1 , e);
      tree[node] = tree[left] + tree[right];
}

int query(int node , int b , int e , int i , int j)
{
      if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];

      int left = node*2;
      int right=node*2 + 1;
      int mid = (b+e)/2;

      int p1 = query(left , b , mid , i , j);
      int p2 = query(right , mid+1 , e , i , j);
      return p1+p2;
}

void update(int node , int b , int e , int i , int newvalue)
{
      if ( b > i || e < i)
        return;
    if (b == e) {
        tree[node] = newvalue;
        return;
    }

      int left=node*2;
      int right=node*2 + 1;
      int mid = (b+e)/2;

      update(left , b , mid , i , newvalue);
      update(right , mid+1, e , i , newvalue);

      tree[node] = tree[left]+tree[right];
}

int main()
{
      ios_base::sync_with_stdio(false);
      int t;
      scanf("%d",&t);
      for(int cs=1; cs<=t; cs++)
      {

            int N , Qu;
            scanf("%d %d",&N,&Qu);
            for(int i=0; i<N; i++){
                  scanf("%d",&arr[i]);
            }

            printf("Case :%d\n",cs);
            init(1,0,N-1);
            for(int i=1; i<=Qu; i++)
            {
                  int v;
                  scanf("%d",&v);
                  switch(v)
                  {
                  case 1:
                        int sack;
                        scanf("%d",&sack);
                        printf("%d\n",arr[sack]);
                        arr[sack]=0;
                        update(1,0,N-1,sack,0);
                        break;
                  case 2:
                        int idx , nwvlu;
                        scanf("%d %d",&idx,&nwvlu);
                        arr[idx] = arr[idx]+nwvlu;
                        update(1,0,N-1,idx,arr[idx]);
                        break;
                  case 3:
                        int h , j;
                        scanf("%d %d",&h,&j);
                        printf("%d\n",query(1,0,N-1,h,j));
                        break;
                  }
            }
      }
      return 0;
}
