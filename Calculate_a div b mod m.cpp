#include<bits/stdc++.h>
using namespace std;
long long int d, x, y;

long long int powerMod(long long int A , long long int B, long long int M)
{
      if(B == 0)
            return 1;
      else if( B%2 == 0)
            return powerMod((A*A)%M , B/2 , M)%M;
      else
            return A*(powerMod((A*A)%M , B/2 , M))%M;

}

void extendedEuclid(long long int A, long long int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        long long int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
 long long int modInverse(long long int c, long long int M)
{
      extendedEuclid(c,M);
      return (x%M+M)%M;
}

int main()
{
      long  long int A,B,C,M,ans1,ans2;
      cin>>A>>B>>C>>M;
      ans1 = powerMod(A,B,M);
       ans2 = modInverse(C, M);
      cout<<(ans1%M * ans2%M)%M<<endl;
}
