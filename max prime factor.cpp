#include<bits/stdc++.h>
using namespace std;
#include <math.h>
#include <stdio.h>

// A function to find largest prime factor
long long maxPrimeFactors(long long n)
{
    long long maxPrime = -1;
    while (n % 2 == 0) {
        maxPrime = 2;
        n >>= 1; // equivalent to n /= 2
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n = n / i;
        }
    }

    if (n > 2)
        maxPrime = n;

    return maxPrime;
}

// Driver program to test above function
int main()
{
    long long n = 15;
    printf("%lld\n", maxPrimeFactors(n));

    n = 25698751364526;
    cin>>n;
    printf("%lld", maxPrimeFactors(n));

    return 0;
}

