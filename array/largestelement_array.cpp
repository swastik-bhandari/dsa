#include<iostream>
using namespace std;
int main ()
{
unsigned int n ;
cin>>n;
int a[n];
for(int i=0 ; i<n ; i++)
{
cin>>a[i];
}
int l=a[0];
for(int i=0 ; i<n ; i++)
{
if (l<a[i])
{
l=a[i];
}
}
cout<<"the largest element is "<<l;
return 0;
}
