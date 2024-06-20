#include<iostream>
using namespace std;
void F(int n, string ans , bool prev )
{
if(n==0)
{
cout<<ans<<endl;
return;
}
if(!prev)
{
F(n-1,ans+'0',0);
F(n-1,ans+'1',1);
}
else
{
F(n-1,ans+'0',0);
}
}
int main ()
{
int n ;
cin>>n;
F(n,"",0);
return 0;
}
