#include<bits/stdc++.h>
using namespace std;
//#define lld long long int
typedef long long int lld;
lld tree[400005],A[100005],B[100005],lazy[400005];
void build(lld node, lld start, lld end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        lld mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // lldernal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void updateRange(lld node, lld start, lld end, lld l, lld r, lld val)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    lld mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value
}

lld queryRange(lld node, lld start, lld end, lld l, lld r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    lld mid = (start + end) / 2;
    lld p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    lld p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}

int main()
{
      lld T;
      scanf("%lld",&T);

      while(T--)
      {
            memset(A,0,sizeof A);
              memset(B,0,sizeof B);
                memset(tree,0,sizeof tree);
                  memset(lazy,0,sizeof lazy);

            lld N,M,Q;
            scanf("%lld%lld%lld",&N,&M,&Q);

            for(int i=0; i<N; i++)
            {
                  lld X;
                  scanf("%lld",&X);
                  A[i]=X;
            }
            build(lld 0, lld 0, lld N);
            for(int i=0; i<M; i++)
            {
                  lld X;
                  scanf("%lld",&X);
                  if(i==0)
                  B[i]=X;
                  else
                  B[i]=B[i-1]+X;
            }

            while(Q--)
            {
                  lld X,Y,L,R;
                  scanf("%lld%lld",&X,&Y);
                  scanf("%lld%lld",&L,&R);

                  lld sum=B[Y]-B[X-1];
                  updateRange(lld 0, lld 0, lld N, lld L, lld R, lld sum);
            }

            for(int i=0; i<N; i++)
            {
                lld X = queryRange(lld 0, lld 0, lld N, lld i, lld i);
                printf("%lld\n",X);
            }
      }
}
