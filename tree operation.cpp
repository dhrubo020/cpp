#include<bits/stdc++.h>
using namespace std;
int  arr[100];
struct T
{
    int value;
    T *L;
    T *R;
};
T *tree, *root;

int init(int node, int b, int e)
{
    int i;
    if(b==e){
    return 0;
    }
    if(root==NULL)
    {
        root = new T();
        root->value = 0;
        root->L=NULL;
        root->R=NULL;
    }
    else{
            tree=root;
    tree->L = new T();
    tree->R = new T();
    int l=2*node;
    int r=2*node + 1;
    int mid = (b+e)/2;
    tree->L=init(l, b, mid);
    tree->R=init(r, mid + 1, e);
    tree[node]=0;
}
int lca(int root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    if(root==n1 || root==n2)
        return root;
    int left = lca(left , n1, n2);
    int right= lca(right, n1 ,n2);
    if(left !=NULL && right !=NULL)
        return root;
    if(left == NULL && right== NULL)
        return NULL;

    return left!=NULL ? left : right;
}
int main()
{
    int n;
    while(1){
    cin >> n;
    init(1,1,n);
    for(int i=1; i<=n; i++){
        cin >> tree[i];
    }
    int x,y;
    cin >> x>> y;
    cout << tree[lca(1,x,y)] << endl;
}
}
