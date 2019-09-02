#include<bits/stdc++.h>
using namespace std;
int BIT[1000] , a[1000], n;

void update(int x, int val)
{
      while(x<=n){
            BIT[x] += val;
            x+= x&-x;
      }
}

int query(int x)
{
      int sum = 0;
      while(x>0){
            sum+=BIT[x];
            x -=x&-x;
      }
      return sum;
}
int main()
{
      cin>>n;
      int i;
      for(i=1; i<=n; i++)
      {
            cin>>a[i];
            update(i , a[i]);
      }
      cout<<query(10)<<endl;
      cout<<query(7) - query(2-1)<<endl;
}
