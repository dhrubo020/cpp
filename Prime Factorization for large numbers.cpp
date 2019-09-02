#include<bits/stdc++.h>
using namespace std;
typedef long long int lld;
// Program to prlld all prime factors


// A function to prlld all prime factors of a given number n
void primeFactors(lld n)
{
    // Prlld the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }

    // n must be odd at this polld.  So we can skip
    // one element (Note i = i +2)
    for (lld i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, prlld i and divide n
        while (n%i == 0)
        {
            printf("%lld ", i);
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        printf ("%lld ", n);
}

/* Driver program to test above function */
int main()
{
    lld n ;
    while(cin>>n){
      primeFactors(n);
      puts("");
    }
    return 0;
}
