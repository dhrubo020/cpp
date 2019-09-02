#include<bits/stdc++.h>
using namespace std;

int tree[100000];
int query(int idx)
{
       int sum=0;
       while(idx>0)
       {
             sum+=tree[idx];
             //cout << idx << " " << endl;
             idx -= idx & (-idx);

       }
       return sum;
}
void update(int idx, int x, int n)
{
       while(idx<=n)
       {
             tree[idx]+=x;
             idx += idx & (-idx);
       }
}
int main()
{
        int x,y;
        cin >> x;
    for(int i = 1; i<=x; i++){
        cin >> tree[i];
        update(i,tree[i],x);
    }
    cin >> y;
        int sum=query(y);
        cout << sum ;
}
