#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, A[100];
    while(cin>>n){

    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }

    for(int j=1; j<n; j++)
    {
        int key=A[j];
        int i=j-1;
        while(i>=0 and A[i]>=key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1]=key;
    }
    for(int i=0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
    }
}
