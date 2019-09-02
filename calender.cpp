#include<bits/stdc++.h>
using namespace std;


int step1 (int);
void month_name(int);
int no_days(int,int);
int leap(int);

int main()
{
restart:

cout<<"Enter year : ";
unsigned int y,m;
cin>>y;
int x;
x=step1(y);
int month[14][12]= {1,4,4,7,2,5,7,3,6,1,4,6,
2,5,5,1,3,6,1,4,7,2,5,7,
3,6,6,2,4,7,2,5,1,3,6,1,
4,7,7,3,5,1,3,6,2,4,7,2,
5,1,1,4,6,2,4,7,3,5,1,3,
6,2,2,5,7,3,5,1,4,6,2,4,
7,3,3,6,1,4,6,2,5,7,3,5,
1,4,5,1,3,6,1,4,7,2,5,7,
2,5,6,2,4,7,2,5,1,3,6,1,
3,6,7,3,5,1,3,6,2,4,7,2,
4,7,1,4,6,2,4,7,3,5,1,3,
5,1,2,5,7,3,5,1,4,6,2,4,
6,2,3,6,1,4,6,2,5,7,3,5,
7,3,4,7,2,5,7,3,6,1,4,6};
cout<<"Enter month (1 – 12) : ";
month_input:
cin>>m;
if(m<1 || m>12)
{
cout<<"Enter a valid month (1 -12) : ";
goto month_input;
}
cout<<"";
month_name(m);
cout<<" "<<y<<"\nMon    Tue    Wed    Thu    Fri    Sat    Sun\n";
int j=month[x-1][m-1], days=no_days(m,y);
for (int i=0; i<j-1; i++)
cout<<"";
for(int i=1; i<=days; i++)
{
cout<<i<<" ";
if(j==7)
{
cout<<"\n";
j=1;
}
else
j++;
}
cout<<"Try for another month? (y/n) : ";
char ch;
cin>>ch;
if(ch=='y' || ch=='Y')
goto restart;
}
int step1 (int y)
{
int x=y%7;
x+=(y-1)/4;
x-=(y-1)/100;
x+=(y-1)/400;
x=x%7;
if(x==0)
x=7;
if(leap(y))
x+=7;
return x;
}
void month_name(int m)
{
switch(m)
{
case 1 : cout<<"January";
break;
case 2 : cout<<"February";
break;
case 3 : cout<<"March";
break;
case 4 : cout<<"April";
break;
case 5 : cout<<"May";
break;
case 6 : cout<<"June";
break;
case 7 : cout<<"July";
break;
case 8 : cout<<"August";
break;
case 9 : cout<<"September";
break;
case 10: cout<<"October";
break;
case 11: cout<<"November";
break;
case 12: cout<<"December";
break;
}
}

int no_days(int mon, int y)
{
int d;
switch(mon)
{
case 1 :
case 3 :
case 5 :
case 7 :
case 8 :
case 10:
case 12: d=31;
break;
case 4 :
case 6 :
case 9 :
case 11: d=30;
break;
case 2 : if(leap(y))
d=29;
else
d=28;
break;
}
return d;
}
int leap (int y)
{
if (y%100==0)
if (y%400==0)
return 1;
else
return 0;
else
if (y%4==0)
return 1;
else
return 0;
}
