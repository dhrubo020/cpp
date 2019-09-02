#include<bits/stdc++.h>
using namespace std;

double mysqrt(double n)
{
    double mid, B, E=n;
    int C=0;
    while(E - B > 0.0001){
        C++;
        mid = (B+E)/2.0;
        if(mid*mid > n)
            E = mid;
        else
            B = mid;
    }
    cout <<C<<endl;
    return mid;
}

int main()
{
    double n;
    cin >> n;
    cout << mysqrt(n) << endl;
}
