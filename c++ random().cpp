#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
      int n;
      srand(time(0));
      n = rand()%25;
      cout<<n<<endl;
      for(int i=2; i<=sqrt(n); i++)
      {
            if(n%i==0)
            {
                  cout<<n<<" is not prime number"<<endl;
                  return 0;
            }
      }
      cout<<"prime"<<endl;
}


