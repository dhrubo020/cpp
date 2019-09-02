#include<bits/stdc++.h>
using namespace std;

int binaryExponentiation(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=result * x;
        x=x*x;
        n=n/2;
    }
    return result;
}
int modularExponentiation(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}
int modularExponentiation(int x,int n,int M)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}
int GCD(int A, int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}

int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

int modInverse(int A, int M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}
int modInverse(int A,int M)
{
    return modularExponentiation(A,M-2,M);
}
int main( )
{
      extendedEuclid(16, 10);
      cout << "The GCD of 16 and 10 is " << d << endl;
      cout << "Coefficients x and y are "<< x <<  " and  " << y << endl;

      cout<<( 3263442 % 1000000007 *  3263443 % 1000000007 ) %1000000007<<endl;
      return 0;
}

