#include<bits/stdc++.h>
#include<cctype>
using namespace std;

int main()
{
      string S;
      cin >> S;
    // getline(cin , S);
     // S.erase(remove_if(S.begin() , S.end(), ::isdigit), S.end());
     // cout<<S<<endl;
      stringstream ss(S);
      int x;
      ss >> x;
      cout<<x+10<<endl;
}
