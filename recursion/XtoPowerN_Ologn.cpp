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
int half=pow(x,n/2);
if ( n%2==0)
{
return (half*half);
}
else
{
return (2*half *half);
}
}
int main ()
{
cout<<pow(2,10);
return 0;
}
