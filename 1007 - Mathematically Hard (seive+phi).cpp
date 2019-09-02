#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
ll M=5000005;
ll phi[5000005];
ll sroot=3000;

vector<int>prime;
int sieve()
{
      bool arr[3000];
      memset(arr , 1 , sizeof(arr));
      for(int i=2; i<sroot; i++)
      {
            if( arr[i] == 1)
            {
                  for(int j=i*i ; j<sroot ; j=j+i)
                        arr[j] = 0;
            }
      }
      for (int i = 2; i <= sroot; i++) {
		if(arr[i] == 1) {
			prime.push_back(i);
		}
	}
}

void sievePHI(){
	ll i,j;
	for( i=2;i<M;i++){
		if( phi[i]==0){
			phi[i] = i-1;
			for( j = i*2; j<M; j+=i){
				if( phi[j] == 0 )phi[j] = j;
				phi[j] /= i ;
				phi[j] *= (i-1) ;
			}
		}
	}
	for(ll s=2 ; s<=M; s++)
            {
                  phi[s] = phi[s]*phi[s];
                  phi[s] = phi[s]+phi[s-1];
            }
}


int main()
{
      //sieve();
      sievePHI();
      int tc;
      scanf("%d",&tc);
      for(int t=1; t<=tc; t++)
      {
            ll a , b, sum=0;
            scanf("%lld %lld",&a,&b);
            printf("Case %d: %llu\n",t,phi[b]-phi[a-1]);
      }
}
