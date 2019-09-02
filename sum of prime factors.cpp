#include<bits/stdc++.h>
using namespace std;
long sum;

void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);
        sum=sum+2;
        n = n/2;
    }
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
          //cout<<"n "<<n<<endl;
        while (n%i == 0)            // While i divides n, print i and divide n
        {
            printf("%d ", i);
            sum=sum+i;
            n = n/i;
        }
    }
    // This condition is to handle the case when n is a prime number greater than 2
    if (n > 2){
        printf ("%d ", n);
        sum=sum+n;
    }
}

int main()
{
    long long int n ;
    while(cin>>n){
            sum=0;
      primeFactors(n);
      puts("");
      cout<<sum<<endl;

    }

    return 0;
}

