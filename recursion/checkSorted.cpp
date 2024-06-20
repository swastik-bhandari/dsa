#include<iostream>
using namespace std;
bool fibo (int a[] , int n , int i)
{
if (i==n-1)
{
return true;
}
if(a[i]>a[i+1])
{
return false;
}
return (fibo(a, n , i+1));
}
int main ()
{
const int size=5;
int a[size];
for(int i=0 ; i<size ; i++)
cin>>a[i];
cout<<fibo(a,size,0);
return 0;
}
