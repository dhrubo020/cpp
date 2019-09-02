#include<bits/stdc++.h>
using namespace std;

int main()
{
      int cnt=0 , sum=11;
      string s;
      cin>>s;
      if(s.length()==1)
      {
            cout<<0;
            return 0;
      }
      else
      {
            while( sum>=10)
            {
                  sum=0;
                  for(int i=0; i<s.length(); i++)
                  {
                        sum+=(s[i] - '0');
                  }
                  s = to_string(sum); //Compilation  error but its working
                  cnt++;
            }
      }
      cout<<cnt;
}
