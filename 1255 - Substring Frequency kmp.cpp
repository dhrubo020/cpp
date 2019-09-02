#include<bits/stdc++.h>
using namespace std;
int arr[1000005];

int main()
{
      int t, cs=1;
      cin>>t;
      while(t--)
      {
            string Pat , Txt;
            cin>>Txt>>Pat;

            int p=Pat.length();
            int t=Txt.length();

            int i=1,j=0;
            while(i<p)
            {
                  if(Pat[j] == Pat[i])
                  {
                        arr[i] = j+1;
                        i++;
                        j++;
                  }
                  else
                  {
                        if( j>0)
                              j = arr[j-1];
                        else
                        {
                              j=0;
                              arr[i]=0;
                              i++;
                        }
                  }
            }
           /* for(int i=0; i<p; i++)
                  cout<<arr[i]<<" ";
            puts("");*/

            i=0,j=0;
            int cnt=0;

            while(i<t)
            {
                  if( Pat[j] == Txt[i])
                  {
                        i++; j++;
                        if( j==p){
                              j=arr[j-1];
                              cnt++;
                        }
                  }
                  else
                  {
                        if(j>0)
                              j = arr[j-1];
                        else
                              i++;
                  }
            }
            cout<<"Case "<<cs++<<": "<<cnt<<endl;
            memset(arr , 0 , sizeof(arr));
      }
}
