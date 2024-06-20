#include<iostream>
using namespace std;
int c(int n , int i)
{
int fact1=1,fact2=1,fact3=1;
if(n>i){
for(int j=1 ; j<=n ; j++)
{
fact1*=j;
}
for(int j=1 ; j<=i ; j++)
{
fact2*=j;
}for(int j=1 ; j<=(n-i); j++)
{
fact3*=j;
}
}
return (fact1/(fact2*fact3));
}
int tile (int n , int i)
{
if(n<i)
{
return 0;
}
return (c(n,i)+tile(n-1,i+1));
}
int main ()
{
int n ;
cin>>n;
cout<<tile(n,0);
return 0;
}
