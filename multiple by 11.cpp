#include<bits/stdc++.h>
using namespace std;

int main()
{
      string str;
      while(cin>>str)
      {
            int l=str.length();
            if(l==1 and str[0] == '0')
                  return 0;
            int rem=0, n=0 ;

            for(int i=0; i<l; i++)
            {
                  rem = (n*10) + (str[i]-48);
                  n = rem%11;
            }

            if(n==0)
                  cout<<"Y"<<endl;
            else
                  cout<<"N"<<endl;
      }
}
