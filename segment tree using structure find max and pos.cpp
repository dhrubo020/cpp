/*****************Bismillahir Rahmanir Rahim***********************/

#include<bits/stdc++.h>
using namespace std;

/************************Start Of Template*************************/

/******** Mahin Shefat - GhOstMan *************/


#define     pb              push_back
#define     popb            pop_back
#define     ll              long long int
#define     ull             unsigned long long int
#define     max3(a,b,c)     max(a,max(b,c))
#define     max4(a,b,c,d)   max(max3(a,b,c),d)
#define     min3(a,b,c)     min(a,min(b,c))
#define     min4(a,b,c,d)   min(a,min3(b,c,d))
#define     MOD             1000000009
#define     f               first
#define     s               second
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     mp              make_pair
#define     check           printf("check")
#define     sqr(x)          (x)*(x)
#define     all(v)          v.begin(),v.end()
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     pii             pair<int,int>
#define     Pair            pair<ll,ll>
#define     MAX             100000000000014
#define     MIN             -100000000000014
#define     Fread           freopen("input.txt","r",stdin);
#define     Fwrite          freopen("output.txt","w",stdout);


/************************End Of Template*************************/
struct nod
{
    int v , idx;
};
typedef struct nod Node;
Node tree[4 * 100005];
int arr[100005];
int sod(int n){
	int sum = 0;
	while(n > 0){
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}
void go(int node , int low , int high){
	if(low == high){
		tree[node].v = arr[low];
		tree[node].idx = low;
		return;
	}
	int mid = (low + high) / 2;
	go(2 * node , low , mid);
	go(2 * node + 1 , mid + 1, high);
	if(tree[2 * node].v < tree[2 *node +1].v){
		tree[node].v = tree[2 * node + 1].v;
		tree[node].idx = tree[2 * node + 1].idx;
	}
	else if(tree[2 * node].v >= tree[2 *node +1].v){
		tree[node].v = tree[2 * node].v;
		tree[node].idx = tree[2 * node].idx;
	}
}
Node ask(int node , int low , int high ,int st , int en){
	//cout << node << " " << st << " " << en <<" " <<low <<" "<< high <<endl;
	if(low > en || high < st){
		Node p ;
		p.v = -1 ; p.idx = 10000000;
		return p;
	}
	if(low >= st && high <= en){
		return tree[node];
	}
	int mid = (low + high) / 2;
	Node a = ask(2 * node , low , mid ,st , en );
	Node b = ask(2 * node + 1 , mid + 1, high , st , en );
	Node ans;
	if(a.v < b.v){
		ans.v = b.v;
		ans.idx = b.idx;
	}
	else if(a.v >= b.v){
		ans.v = a.v;
		ans.idx = a.idx;
	}
	return ans;
}
int main()
{
	int t , tc = 1;
	cin >> t;
	while(t--){
		int n , q;
		cin >> n >> q;
		for(int  i =1 ; i <= n; i++){
			cin >> arr[i];
			arr[i] = sod(arr[i]);
		}
		go(1, 1 , n);
		printf("Case #%d:\n", tc++);
		while(q--){
			int l , r;
			cin >> l >> r;
			Node ans = ask(1 , 1 , n , l , r);
			printf("%d %d\n", ans.v , ans.idx);
		}
	}
	return 0;
}
