#include<bits/stdc++.h>
using namespace std;

int fx[] = { 1 , -1, 0, 0};
int fy[] = { 0, 0,  1, -1};

char grid[30][30];
int flag[30][30];
int row, col, cnt;

void floodfill(int i , int j)
{
      //cout<<i<<" "<<j<<" "<<grid[i][j]<<endl;
      if(i<0 || j<0 || i>row-1 || j>col-1)
            return;
      else if(grid[i][j] == '.' and flag[i][j]==0)
      {
            cnt++;
            flag[i][j]=1;
            for(int m=0; m<4; m++)
            {
                  int x = i+fx[m];
                  int y = j+fy[m];
                  floodfill(x,y);
            }
      }
}

int main()
{
      int t , xx, yy;
      cin>>t;
      for(int cs=1; cs<=t; cs++)
      {
            memset(grid , '\0' , sizeof(grid));
            memset(flag ,0 , sizeof(flag));
            int rw, cl;
            cin>>rw>>cl;
            row=cl;
            col = rw;
            getchar();

            cnt=0;
            for(int i=0; i<row; i++)
            {
                  for(int j=0; j<col; j++)
                  {
                        scanf("%c",&grid[i][j]);
                        if(grid[i][j] == '@')
                        {
                              grid[i][j] = '.';
                              xx=i;
                              yy=j;
                        }
                  }
                  getchar();
            }
            floodfill(xx,yy);
            printf("Case %d: %d\n",cs,cnt);
      }
}
