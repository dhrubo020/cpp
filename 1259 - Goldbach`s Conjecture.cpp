#include<bits/stdc++.h>
using namespace std;
bool table[10000000];
int prime[1000000];
void seive()
{
    memset(table,false,sizeof(table));
    table[0]=table[1]=true;
    int i,j;
    for(i=4;i<=10000000;i+=2)
      table[i]=true;
    for(i=3;i*i<=10000000;i+=2)
        if(table[i]==0)
            for(j=i*i;j<=10000000;j+=i)
                table[j]=true;

    prime[0]=2;
    for(i=3,j=0;i<10000000;i+=2){
        if(table[i]==false)
            prime[++j]=i;
    }
}


int main()
{
    seive();
    int n,count,i,Case=0;
    int T;
    cin >> T;
    while(T-- && scanf("%d",&n)==1)
    {
        count=0;
        for(i=0;prime[i]<=n/2;i++)
        {
            if(table[n-prime[i]]==false) {
                        cout<<n<<" "<<prime[i]<<endl;
                  count++;
            }
        }
        printf("Case %d: %d\n",++Case,count);
    }
}
