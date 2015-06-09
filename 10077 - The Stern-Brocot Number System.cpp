#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
int p,q;
int comp(int a,int b,int c,int d)
{
  if(a*d>c*b)
    return 1;
  else
    return 0;
}
int find(int a,int b,int c,int d)
{
  int x,y;
  x=a+c;
  y=b+d;
  if((x==p)&&(y==q))
    return 0;
  if(comp(p,q,x,y)==1)
    {
      cout<<"R";
      find(x,y,c,d);
    }
  else
    {
      cout<<"L";
      find(a,b,x,y);
    }
}
int main()
{
  while(1)
  {
    cin>>p>>q;
    if((p==1)&&(q==1))
      break;
    if ((p/q)>1)
      {
        cout<<"R";
        find(1,1,1,0);
      }
    else
      {
        cout<<"L";
        find(0,1,1,1);
      }
    cout<<endl;
  }
  return 0;
}
