#include<bits/stdc++.h>
using namespace std;

int A[11][11] , r,c,dx,dy,x,y , vis[11][11];

int DFS(int x, int y, int vis[][11] , int r, int c, int A[][11], int dx, int dy)
{
      cout<<x<<" "<<y<<endl;

      if( x == dx and y == dy)
            return 1;
      if( x>= r or y>=c){
                  cout<<"T x=r"<<endl;
            return 0;
      }
      if( x<0 or y<0){
                  cout<<"T x 0"<<endl;
            return 0;
      }

      if( vis[x][y] == 1){
                  cout<<"T vis 1"<<endl;
            return 0;
      }
      if( A[x][y] == 0){
                  cout<<"T A 0"<<endl;
            return 0;
      }
      vis[x][y] == 1;

      if( DFS(x+1, y , vis , r, c , A , dx , dy) == 1)
            return 1;
      if(  DFS(x-1, y , vis , r, c , A , dx , dy) == 1)
            return 1;
      if( DFS(x, y+1 , vis , r, c , A , dx , dy) == 1)
            return 1;
      if( DFS(x, y-1 , vis , r, c , A , dx , dy) == 1)
            return 1;
      cout<<"end"<<endl;
      return 0;
}
int main()
{
      while(cin>>r>>c)
      {
            memset(vis , 0 , sizeof(vis));
            for(int i=1; i<=r; i++)
            {
                  for(int j=1; j<=c; j++)
                  {
                        cin>>A[i][j];
                  }
            }
          dx=r; dy=c;
            if( DFS(1,1, vis, r, c, A, dx, dy))
                  cout<<"Yes\n";
            else
                  cout<<"No\n";
      }
}
