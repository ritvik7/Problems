#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    string d[]= {"063","010","093","079","106","103","119","011","127","107"};
    while(1)
    {
        string a,b,c;
        long long int A=0,B=0,C,i,j,x,y;
        cin>>c;
        if(c=="BYE")
            return 0;
        for(i=0; c[i]!='+'; i++)
        {    }
        a=c.substr(0,i);
        x=i;
        i++;
        for(j=i; c[j]!='='; j++);
        {  }
        b=c.substr(i,j-i);
        y=j-i;
        for(i=0; i<=x-3; i+=3)
        {
            for(j=0; j<10; j++)
            {
                if(a.substr(i,3)==d[j])
                    break;
            }
            A=A*10+j;
        }
        for(i=0; i<=y-3; i+=3)
        {
            for(j=0; j<10; j++)
            {
                if(b.substr(i,3)==d[j])
                    break;
            }
            B=B*10+j;
        }
        C=A+B;
        int p[10];
        i=0;
        while(C!=0)
        {
            x=C%10;
            C=C/10;
            p[i]=x;
            i++;
        }
        cout<<c;
        for(j=i-1; j>=0; j--)
            cout<<d[(p[j])];
        cout<<endl;
    }
}
