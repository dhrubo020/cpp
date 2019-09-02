#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int n , t;
vector <string> v;
string k;

bool cmp(string x , string y)
{
      return x+y > y+x;
}


int main()
{
      cin>>n;
      for(int i=0; i<n; i++)
      {
            cin>>k;
            v.push_back(k);
      }
      sort(v.begin() , v.end() , cmp);

      if(v[0]=="0"){
            cout<<"0";
      }
      else{
            for(int i=0; i<n; i++)
            {
                  cout<<v[i];
            }
      }
}

