#include<bits/stdc++.h>
using namespace std;

int arr[1005] , N , k;

bool  valid(int mid)
{
      int sum = 0 ,  part=0;
      for(int i=0; i<=N; i++)
      {
            sum = sum+arr[i];
            if( sum > mid)
            {
                  part++;
                  sum = arr[i];
            }
      }
      return part<=k;
}
int main()
{
      int t , cs=1;
      scanf("%d",&t);
      while(t--)
      {
            memset(arr , 0 , sizeof(arr));
            int hi=0, low=0, ans, mid;

            scanf("%d %d",&N,&k);
            scanf("%d",&arr[0]);

            hi=arr[0];
            low = max(low , arr[0]);

            for(int i=1; i<=N; i++){
                  scanf("%d",&arr[i]);
                  hi = hi + arr[i];
                  low = max(low , arr[i]);
            }
            ans=hi;
            while(low<=hi)
            {
                  mid = (hi+low)/2;

                  if(valid(mid))
                  {
                        ans = mid;
                        hi = mid-1;
                  }
                  else
                        low = mid+1;
            }

            printf("Case %d: %d\n",cs++,ans);
            int j;
            for (int i = k, j = 0; i >=0; i--)
              {
                  int sum = 0;
                  for (; N-j >= i; j++)
                  {
                      if (sum+arr[j] > low) break;
                      sum += arr[j];
                  }
                  printf ("%d\n",sum);
              }
      }
}
