#include<bits/stdc++.h>
using namespace std;
int N,m;
int arr[1005];
bool valid( int mid)
{
      int sum=0 , part=1;
      for(int i=0; i<N; i++)
      {
            sum = sum +arr[i];
            if(sum > mid)
            {
                  part++;
                  sum = arr[i];
            }
      }
      return part<=m;
}

int main()
{
      int t , cs=1;
      cin>>t;
      while(t--)
      {
            memset(arr , 0 , sizeof(arr));
            int hi=0, low=0 , mid , ans;

            cin>>N>>m;
            for(int i=0 ; i<N; i++)
            {
                  cin>>arr[i];
                  hi = hi+arr[i];
                  low = max(low , arr[i]);
            }

            while(hi>=low)
            {
                  mid = (hi+low)/2;

                  if( valid(mid))
                  {
                        ans = mid;
                        hi = mid-1;
                  }
                  else
                        low = mid+1;
            }
            printf("Case %d: %d\n",cs++,ans);
      }
}
