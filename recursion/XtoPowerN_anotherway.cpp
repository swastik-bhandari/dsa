#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int pow(int x , int n )
{
if(n==0)
{
return 1;
}
if ( n%2==0)
{
return (pow(x,n/2)*pow(x,n/2));
}
else
{
return (2*pow(x,(n-1)/2)*pow(x,(n-1)/2));
}
}
int main ()
{
cout<<pow(2,10);
return 0;
}
