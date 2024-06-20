#include<iostream>
using namespace std;
int friendPair(int n)
{
if(n==1)
{
return 1;
}
if(n==2)
{
return 2;
}
return (friendPair(n-1)+(n-1)*friendPair(n-2));
}
int main ()
{
cout<<friendPair(5);
return 0;
}
