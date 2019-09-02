#include<bits/stdc++.h>
using namespace std;

int main()
{
      vector<pair<string , int> > v;
      string s="abcdefghij";
      int len = s.length();
      for(int i=0; i<len; i++)
      {
            cout<<s.substr(i)<<" "<<i<<endl;
            v.push_back(make_pair(s.substr(i) , i));
      }
      sort(v.begin() , v.end());

      for(int i=0; i<len; i++)
            cout<<v[i].second<<" "<<v[i].first<<endl;
}
