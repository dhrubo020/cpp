#define M 10000
#include<bits/stdc++.h>
using namespace std;
bool  vis[M][M];
int dp[M][M];
string A,B,P;
int pos[1000],p;
int LCS(int i, int j)
{
    if(A[i] == '\0' or B[j] == '\0')
        return 0;
    if(vis[i][j])
        return dp[i][j];
    int ans = 0;
    if( A[i] == B[j])
        ans =  LCS(i+1, j+1);
    else{
        int v1 = LCS(i+1,j);
        int v2 = 1+LCS(i, j+1);
        ans = min(v1,v2);
    }
    vis[i][j] = true;
    dp[i][j] = ans;
    return dp[i][j];
}

void printLCS(int i, int j)
{
    if(A[i] == '\0' or B[j] == '\0'){
        cout <<P<<endl;
        return;
    }
    if(A[i] == B[j]){
        P+=A[i];
        pos[p++]=i;
      //  cout<<i<<" ";
        //cout <<" --- "<<endl;
        printLCS(i+1,j+1);
        P.erase(P.end()-1);
    }
    else{
        if( dp[i+1][j] > dp[i][j+1])
            return printLCS(i+1,j);
        else if( dp[i+1][j] < dp[i][j+1])
            return printLCS(i,j+1);
        else{
			printLCS(i+1,j);
			printLCS(i,j+1);
		}
    }
}

int main()
{
    cin >> A >>B;
    p=0;
    cout<<LCS(0,0)<<endl;
      //  printLCS(0,0);
}
