#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
int a[1048576];
int d,t;
int tree(int r, int x)
{
  if(x==1)
    return r;
  if(a[r-1]==0)
  {
    a[r-1]=1;
    tree(2*r,x-1);
  }
  else if((a[r-1]==1))
  {
    a[r]=0;
    tree(2*r+1,x-1);
  }
}
int main()
{
 int test;
 cin>>test;
 while(1)
  {
    cin>>d;
    if(d==-1)
      break;
    cin>>t;
    for(int i=0;i<pow(2,d);i++)
      a[i]=0;
    for(int i=0 ;i<t-1;i++)
      tree(1,d);
    cout<<tree(1,d)<<endl;
  }
return 0;
}
