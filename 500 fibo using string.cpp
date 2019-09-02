#include<bits/stdc++.h>
using namespace std;
char str1[1005]={0};
char str2[1005]={1};
char str3[1105];
int i,j,k,sum,carry,l,a,b,c,d;

void func()
{
      //cout<<"s1 "<<str1<<endl;
      //cout<<"s2 "<<str2<<endl;
      a=strlen(str1);
      b=strlen(str2);
      k=0;
      carry=0;
      sum=0;
      for (i=a-1,j=b-1; ;)
      {
            c=str1[i]- '0' ;
            d=str2[j]- '0' ;
            //cout<<c<<" "<<d<<" "<<carry<<endl;
            if (j<0)
            {
                  d=0;
            }
            if (i<0)
            {
                  c=0;
            }

             if (i<0&&j<0)
            {
                  break ;
            }
                 sum=c+d+carry;
                  //cout<<"sum "<<sum<<endl;
                  str3[k]=sum%10+'0';
                  //cout<<str3[k]<<" ";
                  carry=sum/10;
                  k++;
            i--; j--;
      }
      if(carry!=0){
            str3[k] = carry+48;
            k++;
      }
      //cout<<"K "<<k<<endl;
      strcpy(str1 , str2);

      int z=0;
      for(l=k-1; l>=0; l--){
            str2[z] = str3[l];
            z++;
      }

}
int main()
{
      int n,Count=0;
      while(cin>>n){
            str1[0]='0';
            str2[0]='1';
            /* if(n==1)
                        cout<<0<<endl;
             if(n==2)
                        cout<<1<<endl;*/
             for(int i=0; i<=n; i++)
                  {
                        func();
                  }
      cout<<str2<<endl;
      memset(str1 , '\0' , sizeof(str1));
      memset(str2 , '\0' , sizeof(str2));
      }
}
