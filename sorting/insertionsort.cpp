#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
int a[]={5,4,1,3,2};
int n=sizeof(a)/sizeof(a[0]);
for(int i=0 ; i<n ; i++)
{
int j=i ;
while(a[j]<a[j-1] && j>0)
{
swap(a[j],a[j-1]);
j--;
}
}
for(int i=0 ; i<n ; i++)
{
cout<<a[i];
}
return 0;
}

