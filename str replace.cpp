#include<iostream>
using namespace std;
string s;
int a;
main()
{
      cin>>s;
      a=s.find("WUB");
      while (a!=-1)
      {
            s.replace(a,3," ");
            a=s.find("WUB");
      }
      cout<<s;
}
