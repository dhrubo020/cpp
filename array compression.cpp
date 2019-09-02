#include<bits/stdc++.h>
using namespace std;
int cmprs[100000], arr[1000];
map <int , int> mp;
vector < int > v;

void compress(int n)
{
    int assign=0, c=0;
    for(int i=0; i<n; i++){
        int x= v.at(i);
        if(mp.find(x)==mp.end()){
            mp[x]=assign++;
        }
        x=mp[x];
        cmprs[c++]=x;
    }
}
int finds(int n, int value)
{
    int in=0;
    int x=mp[value];
    for(int i=0; i<n; i++){
        if(cmprs[i]==x)
            arr[in++]=i;
    }
    return in;
}
int main()
{
    int n, a, N;
    while(1){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        v.push_back(a);
    }
    compress(n);
   cin >> N;
   int sz=finds(n,N);
    for(int i=0; i<sz; i++)
        cout << arr[i]+1 << " " ;
    cout << endl;
    }
}
