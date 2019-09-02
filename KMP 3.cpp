#include<bits/stdc++.h>
using namespace std;

string T, P;
//char T[100000] , P[100000];
int C, b[100000],m,n;

void makeprefix()
{
      int i=0,j=-1;
      b[0] = -1;
      while(i<n)
      {
            while( j>=0 && P[i] != P[j])
                  j=b[j];
            i++; j++;
            b[i] = j;
      }
}

void KMP()
{
      int i=0 , j=0;
      while(i<m)
      {
            while( j>=0 && T[i] != P[j])
                  j = b[j];
            i++; j++;
            if( j == n)
            {
                  cout<<"Pattern found at index "<<i-j<<endl;
                  C++;
                  j = b[j];
                  //cout<<i<<" "<<j<<endl;
            }
      }
}
int main()
{
      while(1)
      {
            C=0;
           //gets(T);
            //gets(P);
          // cin>>T>>P;
            getline(cin,T);
            getline(cin,P);
            m = T.length();
            n = P.length();
            makeprefix();
            KMP();
            cout<<C<<endl;
      }
}
