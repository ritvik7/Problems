#include<iostream>
#include<stdio.h>
#include<string>
#include <stdlib.h>
using namespace std;

int main()
{
  string s,x,y,z;
  int n=0,i=0,j,k,q,p,t,H=0,a[5000],h[5000],b[5000][2],c[20000];
  while(getline(cin,s))
  {
    k=0;
    x="";
    y="";
    z="";
    if(s=="")
      break;
    while(s[k]!=' ')
     x=x+s[k++];
    k++;
    while(s[k]!=' ')
      y=y+s[k++];
    k++;
    while(k<=s.length())
      z=z+s[k++];
    a[i]=atoi(x.c_str());
    h[i]=atoi(y.c_str());
    b[i][0]=atoi(z.c_str());
    b[i][1]=i;
    n++;
    i++;
  }
  for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
    {
      if(a[i]>a[j])
      {
        t=a[j];
        a[j]=a[i];
        a[i]=t;
        t=h[j];
        h[j]=h[i];
        h[i]=t;
      }
      if(b[i][0]>b[j][0])
      {
        t=b[j][0];
        b[j][0]=b[i][0];
        b[i][0]=t;
        t=b[j][1];
        b[j][1]=b[i][1];
        b[i][1]=t;
      }
    }
  for(i=0,j=0,q=0,p=0;p<=b[n-1][0]+1;p++)
  {
    if(p==a[i])
    {
      if(h[i]>H)
      {
        c[q++]=a[i];
        c[q++]=h[i];
        H=h[i];
      }
      i++;
    }
    if(p==b[j][0])
    {
      if(H==h[b[j][1]])
      {
        c[q++]=b[j][0];
        h[b[j][1]]=0;
        H=0;
        j++;
      }
      else
      {
        h[b[j][1]]=0;
        j++;
        continue;
      }
      for(int k=0;k<i;k++)
      {
        if(h[k]>H)
          H=h[k];
      }
      c[q++]=H;
    }
  }
  for(i=0;i<q;i++)
    cout<<c[i]<<" ";
  return 0;
}
//  if((a[i]==a[i+1])&&(h[i]<h[i+1]))
//  {
//    c[q++]=a[i];
//    c[q++]=h[i+1];
//    i++;
//    H=h[i];
//  }
