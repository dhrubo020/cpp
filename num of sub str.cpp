#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c=0;
    string s, k;
    cin >> s >> k;
    int z=s.find(k);
    while(z!=-1){
        z=s.find(k,z+k.size());
        c++;
    }
    cout <<c<<endl;
}
