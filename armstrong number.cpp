#include<bits/stdc++.h>
using namespace std;

int main()
{
      string s;
      while(cin>>s)
      {
            stringstream in(s);
            int N;
            in >> N;
            int l=s.length();
            double sum=0;
            for(int i=0; i<l; i++)
            {
                  //number = s[i]-48;
                  sum = sum + pow(s[i]-48 , l);
            }
            if(sum == N)
                  cout<<"YES"<<endl;
            else
                  cout<<"NO"<<endl;
      }
}
