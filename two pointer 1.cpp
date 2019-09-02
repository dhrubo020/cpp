#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,t,sum,cnt,maxx;
int main()
{
	cin>>n>>t;
	int a[n];
	for(int i=0,j=0;i<n;i++)
	{
		cin >> a[i];
		sum+=a[i];
		cnt++;
		while(sum>t)
		{
			sum-=a[j];
			j++;
			cnt--;
		}
		if(cnt > maxx)
		{
			maxx=cnt;
		}
	}
	cout << maxx;
}
