#include<iostream>
using namespace std;
int a[8];
int *s=new int[8];
void change(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
    return;
}
int* slice()
{
    for(int i=0;i<8;i++)
    {
        s[i]=a[i];
    }
    return;
}
int length(int*a)
{
    return sizeof(a)/sizeof(a[0]);
}
void pai(int*s){
    int lower=0,sign=0;
    for(int i=0;i<8;i++)
    {
        if(s[i]<s[length(s)-1])
        {
            change(s[i],s[lower]);
            lower++;
        }
    }
    change(a[lower],a[7]);
    if(sign==0)
    {
        return;
    }
    pai(s);
    return;
}
int main()
{
    for(int i=0;i<8;i++)
    {
        cin>>a[i];
    }
    slice();
    pai(s);
    for(int i=0;i<8;i++)
    {
        cout<<a[i];
    }
    return 0;
}