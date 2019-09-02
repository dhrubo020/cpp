#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
string s1,s2;
int m,n;
int MIN(int x, int y, int z)
{
      return min(min(x,y) , z);
}
int editdis()
{
      for(int i=0; i<=m; i++)
      {
            for(int j=0; j<=n; j++)
            {
                  if(i==0)
                        dp[i][j] = j;
                  else if(j == 0)
                        dp[i][j]=i;
                  else if(s1[i-1] == s2[j-1])
                        dp[i][j] = dp[i-1][j-1];
                  else
                        dp[i][j] = 1+MIN(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
                 // cout<<"dp "<< i <<" " <<j<<" " <<dp[i][j]<<endl;
            }
      }
      return dp[m][n];
}
void result_trace() {
    printf("%d\n", dp[m][n]);
    int step = 0, i = m, j = n;
    while (i || j) {
        if (s1[i - 1] == s2[j - 1]) {
            i--, j--;
            continue;
        }
        printf("%d ", ++step);
        if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) { // delete
            printf("Delete %d", i);
            s1.erase(i - 1, 1);
            i--;
        }
        else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) { // insert
            printf("Insert %d,%c", i + 1, s2[j - 1]);
            s1.insert(i, 1, s2[j - 1]);
            j--;
        }
        else if (i > 0 && j > 0) {  // replace
            printf("Replace %d,%c", i, s2[j - 1]);
            s1[i - 1] = s2[j - 1];
            i--, j--;
        }
        putchar('\n');
    }
}
int main()
{
      bool blank_line;
      while(getline(cin,s1))
      {
            getline(cin,s2);
            m=s1.length();
            n=s2.length();
            editdis();
            if (blank_line)
                  putchar('\n');
            blank_line = true;
            result_trace();
      }
}
