#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
  int n,m,k,i;
  long int s;
  cin>>n;
  while(n--)
  {
    cin>>k>>m;
    int a[k];
    long int b;
    s=0;
    for(i=0;i<k;i++)
    {
      cin>>a[i];
      s=s+a[i];
    }
    s=s/m;
    b=a[0];
    m--;
    cout<<b<<" ";
    for(i=1;i<k;i++)
    {
      if((b+a[i]>s)&&(m!=0))
      {
        cout<<"/ "<<a[i]<<" ";
        b=a[i];
        m--;
      }
      else
      {
        cout<<a[i]<<" ";
        b+=a[i];
      }
    }
    cout<<"\n";
  }
  return 0;
}
