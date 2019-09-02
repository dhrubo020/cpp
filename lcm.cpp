
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int c=0;
int gcd(int a, int b)
{
if (b==0)
return a;
return gcd(b, a%b);
}

ll findlcm(int arr[], int n)
{
      ll ans = arr[0];

      for (int i=1; i<n; i++)
      ans = ( ((arr[i]*ans)) /
      (gcd(arr[i], ans)) );

      return ans;
}

int main()
{
      vector<ll>v;
      int x,n,k,i=0;
      cin>>n>>k;
      while(n--)
      {
            cin>>x;
            v.push_back(x);
            if(v[i] % k == 0){
                  pos[j++]=i;
                  mod[j++] = v[i];
            }
            i++;
      }
      int n = sizeof(arr)/sizeof(arr[0]);
      ll lcm= findlcm(arr, n));
      while( lcm % k != 0)
      {
            v.erase(mod[j])
      }
      return 0;
}

